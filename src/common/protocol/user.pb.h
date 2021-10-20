// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/protocol/user.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_common_2fprotocol_2fuser_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_common_2fprotocol_2fuser_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "common/serial/typed_message.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_common_2fprotocol_2fuser_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_common_2fprotocol_2fuser_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_common_2fprotocol_2fuser_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_common_2fprotocol_2fuser_2eproto_metadata_getter(int index);
namespace v2ray {
namespace core {
namespace common {
namespace protocol {
class User;
struct UserDefaultTypeInternal;
extern UserDefaultTypeInternal _User_default_instance_;
}  // namespace protocol
}  // namespace common
}  // namespace core
}  // namespace v2ray
PROTOBUF_NAMESPACE_OPEN
template<> ::v2ray::core::common::protocol::User* Arena::CreateMaybeMessage<::v2ray::core::common::protocol::User>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace v2ray {
namespace core {
namespace common {
namespace protocol {

// ===================================================================

class User PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:v2ray.core.common.protocol.User) */ {
 public:
  inline User() : User(nullptr) {}
  virtual ~User();
  explicit constexpr User(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  User(const User& from);
  User(User&& from) noexcept
    : User() {
    *this = ::std::move(from);
  }

  inline User& operator=(const User& from) {
    CopyFrom(from);
    return *this;
  }
  inline User& operator=(User&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const User& default_instance() {
    return *internal_default_instance();
  }
  static inline const User* internal_default_instance() {
    return reinterpret_cast<const User*>(
               &_User_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(User& a, User& b) {
    a.Swap(&b);
  }
  inline void Swap(User* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(User* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline User* New() const final {
    return CreateMaybeMessage<User>(nullptr);
  }

  User* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<User>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const User& from);
  void MergeFrom(const User& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(User* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "v2ray.core.common.protocol.User";
  }
  protected:
  explicit User(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_common_2fprotocol_2fuser_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEmailFieldNumber = 2,
    kAccountFieldNumber = 3,
    kLevelFieldNumber = 1,
  };
  // string email = 2;
  void clear_email();
  const std::string& email() const;
  void set_email(const std::string& value);
  void set_email(std::string&& value);
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  std::string* mutable_email();
  std::string* release_email();
  void set_allocated_email(std::string* email);
  private:
  const std::string& _internal_email() const;
  void _internal_set_email(const std::string& value);
  std::string* _internal_mutable_email();
  public:

  // .v2ray.core.common.serial.TypedMessage account = 3;
  bool has_account() const;
  private:
  bool _internal_has_account() const;
  public:
  void clear_account();
  const ::v2ray::core::common::serial::TypedMessage& account() const;
  ::v2ray::core::common::serial::TypedMessage* release_account();
  ::v2ray::core::common::serial::TypedMessage* mutable_account();
  void set_allocated_account(::v2ray::core::common::serial::TypedMessage* account);
  private:
  const ::v2ray::core::common::serial::TypedMessage& _internal_account() const;
  ::v2ray::core::common::serial::TypedMessage* _internal_mutable_account();
  public:
  void unsafe_arena_set_allocated_account(
      ::v2ray::core::common::serial::TypedMessage* account);
  ::v2ray::core::common::serial::TypedMessage* unsafe_arena_release_account();

  // uint32 level = 1;
  void clear_level();
  ::PROTOBUF_NAMESPACE_ID::uint32 level() const;
  void set_level(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_level() const;
  void _internal_set_level(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:v2ray.core.common.protocol.User)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr email_;
  ::v2ray::core::common::serial::TypedMessage* account_;
  ::PROTOBUF_NAMESPACE_ID::uint32 level_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_common_2fprotocol_2fuser_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// User

// uint32 level = 1;
inline void User::clear_level() {
  level_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 User::_internal_level() const {
  return level_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 User::level() const {
  // @@protoc_insertion_point(field_get:v2ray.core.common.protocol.User.level)
  return _internal_level();
}
inline void User::_internal_set_level(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  level_ = value;
}
inline void User::set_level(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_level(value);
  // @@protoc_insertion_point(field_set:v2ray.core.common.protocol.User.level)
}

// string email = 2;
inline void User::clear_email() {
  email_.ClearToEmpty();
}
inline const std::string& User::email() const {
  // @@protoc_insertion_point(field_get:v2ray.core.common.protocol.User.email)
  return _internal_email();
}
inline void User::set_email(const std::string& value) {
  _internal_set_email(value);
  // @@protoc_insertion_point(field_set:v2ray.core.common.protocol.User.email)
}
inline std::string* User::mutable_email() {
  // @@protoc_insertion_point(field_mutable:v2ray.core.common.protocol.User.email)
  return _internal_mutable_email();
}
inline const std::string& User::_internal_email() const {
  return email_.Get();
}
inline void User::_internal_set_email(const std::string& value) {
  
  email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void User::set_email(std::string&& value) {
  
  email_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:v2ray.core.common.protocol.User.email)
}
inline void User::set_email(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:v2ray.core.common.protocol.User.email)
}
inline void User::set_email(const char* value,
    size_t size) {
  
  email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:v2ray.core.common.protocol.User.email)
}
inline std::string* User::_internal_mutable_email() {
  
  return email_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* User::release_email() {
  // @@protoc_insertion_point(field_release:v2ray.core.common.protocol.User.email)
  return email_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void User::set_allocated_email(std::string* email) {
  if (email != nullptr) {
    
  } else {
    
  }
  email_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), email,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:v2ray.core.common.protocol.User.email)
}

// .v2ray.core.common.serial.TypedMessage account = 3;
inline bool User::_internal_has_account() const {
  return this != internal_default_instance() && account_ != nullptr;
}
inline bool User::has_account() const {
  return _internal_has_account();
}
inline const ::v2ray::core::common::serial::TypedMessage& User::_internal_account() const {
  const ::v2ray::core::common::serial::TypedMessage* p = account_;
  return p != nullptr ? *p : reinterpret_cast<const ::v2ray::core::common::serial::TypedMessage&>(
      ::v2ray::core::common::serial::_TypedMessage_default_instance_);
}
inline const ::v2ray::core::common::serial::TypedMessage& User::account() const {
  // @@protoc_insertion_point(field_get:v2ray.core.common.protocol.User.account)
  return _internal_account();
}
inline void User::unsafe_arena_set_allocated_account(
    ::v2ray::core::common::serial::TypedMessage* account) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(account_);
  }
  account_ = account;
  if (account) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:v2ray.core.common.protocol.User.account)
}
inline ::v2ray::core::common::serial::TypedMessage* User::release_account() {
  
  ::v2ray::core::common::serial::TypedMessage* temp = account_;
  account_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::v2ray::core::common::serial::TypedMessage* User::unsafe_arena_release_account() {
  // @@protoc_insertion_point(field_release:v2ray.core.common.protocol.User.account)
  
  ::v2ray::core::common::serial::TypedMessage* temp = account_;
  account_ = nullptr;
  return temp;
}
inline ::v2ray::core::common::serial::TypedMessage* User::_internal_mutable_account() {
  
  if (account_ == nullptr) {
    auto* p = CreateMaybeMessage<::v2ray::core::common::serial::TypedMessage>(GetArena());
    account_ = p;
  }
  return account_;
}
inline ::v2ray::core::common::serial::TypedMessage* User::mutable_account() {
  // @@protoc_insertion_point(field_mutable:v2ray.core.common.protocol.User.account)
  return _internal_mutable_account();
}
inline void User::set_allocated_account(::v2ray::core::common::serial::TypedMessage* account) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(account_);
  }
  if (account) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(account)->GetArena();
    if (message_arena != submessage_arena) {
      account = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, account, submessage_arena);
    }
    
  } else {
    
  }
  account_ = account;
  // @@protoc_insertion_point(field_set_allocated:v2ray.core.common.protocol.User.account)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace common
}  // namespace core
}  // namespace v2ray

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_common_2fprotocol_2fuser_2eproto