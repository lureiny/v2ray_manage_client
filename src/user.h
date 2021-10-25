#pragma once

#include <string>
#include <type_traits>

#include "src/common/protocol/user.pb.h"
#include "src/common/serial/typed_message.pb.h"
#include "src/proxy/vless/account.pb.h"
#include "src/proxy/vmess/account.pb.h"

namespace v2m::user {
constexpr uint32_t kDefaultUserLevel = 0;
constexpr char* kVlessAccountType = (char*)"v2ray.core.proxy.vless.Account";
constexpr char* kVmessAccountType = (char*)"v2ray.core.proxy.vmess.Account";

template <typename T>
class User {
 public:
  static_assert(std::is_same<T, v2ray::core::proxy::vmess::Account>::value ||
                std::is_same<T, v2ray::core::proxy::vless::Account>::value);

  User(std::string name, std::string uuid, std::string inbound_tag)
      : email_{name}, uuid_{uuid}, inbound_tag_{inbound_tag} {
    SetAccount();
  };

  inline T GetAccount() const { return account_; };

  inline std::string GetAccountType() const { return account_type_; };

  inline std::string GetEmail() const { return email_; };

  inline std::string GetUuid() const { return uuid_; };

  inline std::string GetInboundTag() const { return inbound_tag_; };

  // Insert user info to the "v2ray::core::common::protocol::User" which has been create.
  void InsertUserInfoToUserProtobuf(v2ray::core::common::protocol::User* user) const {
    user->set_level(level_);
    user->set_email(email_);
    v2ray::core::common::serial::TypedMessage* typed_account = new v2ray::core::common::serial::TypedMessage;
    typed_account->set_type(account_type_);
    typed_account->set_value(account_.SerializeAsString());
    user->set_allocated_account(typed_account);
  };

 private:
  int32_t level_ = kDefaultUserLevel;
  std::string email_;
  std::string uuid_;
  // The inbound which the user will be added to.
  std::string inbound_tag_;
  // The user account's type. When T is "v2ray::core::proxy::vmess::Account", it is
  // "v2ray.core.proxy.vmess.Account".When T is "v2ray::core::proxy::vless::Account", it is
  // "v2ray.core.proxy.vless.Account". It can be expanded when we support morem protocol.
  std::string account_type_;
  T account_;

  inline void SetAccount() {
    account_.set_id(uuid_);
    account_type_ = std::is_same<T, v2ray::core::proxy::vmess::Account>::value ? kVmessAccountType : kVlessAccountType;
  };
};
}  // namespace v2m::user