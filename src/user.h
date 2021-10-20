#pragma once

#include <string>
#include <type_traits>

#include "common/protocol/user.pb.h"
#include "common/serial/typed_message.pb.h"
#include "proxy/vless/account.pb.h"
#include "proxy/vmess/account.pb.h"

namespace v2m::user {

constexpr uint32_t kDefaultUserLevel = 0;
constexpr char* kVlessAccountType = "v2ray.core.proxy.vless.Account";
constexpr char* kVmessAccountType = "v2ray.core.proxy.vmess.Account";

template <typename T>
class User : v2ray::core::common::protocol::User {
 public:
  static_assert(std::is_same<T, v2ray::core::proxy::vmess::Account>::value ||
                std::is_same<T, v2ray::core::proxy::vless::Account>::value);

  User(std::string name, std::string uuid, std::string inbound_tag)
      : inbound_tag_{inbound_tag} {
    set_level(kDefaultUserLevel);
    set_email(name);
    protocol_account_.set_id(uuid);
    SetAccount();
  };

  inline T GetAccount() { return protocol_account_; };

  inline std::string GetEmail() { return email(); };

  inline std::string GetUuid() { return protocol_account_.id(); };

  inline std::string GetInboundTag() { return inbound_tag_; };

 private:
  std::string inbound_tag_;

  T protocol_account_;

  v2ray.core.common.serial.TypedMessage typed_account_;

  inline void SetAccount() {
    if (std::is_same<T, v2ray::core::proxy::vmess::Account>::value) {
      typed_account_.set_type(kVmessAccountType);
    } else {
      typed_account_.set_type(kVlessAccountType);
    }

    typed_account_.set_value(protocol_account_.SerializeAsString());
  };
};
}  // namespace v2m::user