// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/protocol/user.proto

#include "common/protocol/user.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace v2ray {
namespace core {
namespace common {
namespace protocol {
constexpr User::User(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : email_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , account_(nullptr)
  , level_(0u){}
struct UserDefaultTypeInternal {
  constexpr UserDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~UserDefaultTypeInternal() {}
  union {
    User _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT UserDefaultTypeInternal _User_default_instance_;
}  // namespace protocol
}  // namespace common
}  // namespace core
}  // namespace v2ray
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_common_2fprotocol_2fuser_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_common_2fprotocol_2fuser_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_common_2fprotocol_2fuser_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_common_2fprotocol_2fuser_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::v2ray::core::common::protocol::User, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::v2ray::core::common::protocol::User, level_),
  PROTOBUF_FIELD_OFFSET(::v2ray::core::common::protocol::User, email_),
  PROTOBUF_FIELD_OFFSET(::v2ray::core::common::protocol::User, account_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::v2ray::core::common::protocol::User)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::v2ray::core::common::protocol::_User_default_instance_),
};

const char descriptor_table_protodef_common_2fprotocol_2fuser_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032common/protocol/user.proto\022\032v2ray.core"
  ".common.protocol\032!common/serial/typed_me"
  "ssage.proto\"]\n\004User\022\r\n\005level\030\001 \001(\r\022\r\n\005em"
  "ail\030\002 \001(\t\0227\n\007account\030\003 \001(\0132&.v2ray.core."
  "common.serial.TypedMessageBo\n\036com.v2ray."
  "core.common.protocolP\001Z.github.com/v2fly"
  "/v2ray-core/v4/common/protocol\252\002\032V2Ray.C"
  "ore.Common.Protocolb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_common_2fprotocol_2fuser_2eproto_deps[1] = {
  &::descriptor_table_common_2fserial_2ftyped_5fmessage_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_common_2fprotocol_2fuser_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_common_2fprotocol_2fuser_2eproto = {
  false, false, 307, descriptor_table_protodef_common_2fprotocol_2fuser_2eproto, "common/protocol/user.proto", 
  &descriptor_table_common_2fprotocol_2fuser_2eproto_once, descriptor_table_common_2fprotocol_2fuser_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_common_2fprotocol_2fuser_2eproto::offsets,
  file_level_metadata_common_2fprotocol_2fuser_2eproto, file_level_enum_descriptors_common_2fprotocol_2fuser_2eproto, file_level_service_descriptors_common_2fprotocol_2fuser_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_common_2fprotocol_2fuser_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_common_2fprotocol_2fuser_2eproto);
  return descriptor_table_common_2fprotocol_2fuser_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_common_2fprotocol_2fuser_2eproto(&descriptor_table_common_2fprotocol_2fuser_2eproto);
namespace v2ray {
namespace core {
namespace common {
namespace protocol {

// ===================================================================

class User::_Internal {
 public:
  static const ::v2ray::core::common::serial::TypedMessage& account(const User* msg);
};

const ::v2ray::core::common::serial::TypedMessage&
User::_Internal::account(const User* msg) {
  return *msg->account_;
}
void User::clear_account() {
  if (GetArena() == nullptr && account_ != nullptr) {
    delete account_;
  }
  account_ = nullptr;
}
User::User(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:v2ray.core.common.protocol.User)
}
User::User(const User& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_email().empty()) {
    email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_email(), 
      GetArena());
  }
  if (from._internal_has_account()) {
    account_ = new ::v2ray::core::common::serial::TypedMessage(*from.account_);
  } else {
    account_ = nullptr;
  }
  level_ = from.level_;
  // @@protoc_insertion_point(copy_constructor:v2ray.core.common.protocol.User)
}

void User::SharedCtor() {
email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&account_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&level_) -
    reinterpret_cast<char*>(&account_)) + sizeof(level_));
}

User::~User() {
  // @@protoc_insertion_point(destructor:v2ray.core.common.protocol.User)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void User::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  email_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete account_;
}

void User::ArenaDtor(void* object) {
  User* _this = reinterpret_cast< User* >(object);
  (void)_this;
}
void User::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void User::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void User::Clear() {
// @@protoc_insertion_point(message_clear_start:v2ray.core.common.protocol.User)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  email_.ClearToEmpty();
  if (GetArena() == nullptr && account_ != nullptr) {
    delete account_;
  }
  account_ = nullptr;
  level_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* User::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint32 level = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          level_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string email = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_email();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "v2ray.core.common.protocol.User.email"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .v2ray.core.common.serial.TypedMessage account = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_account(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* User::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:v2ray.core.common.protocol.User)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 level = 1;
  if (this->level() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_level(), target);
  }

  // string email = 2;
  if (this->email().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "v2ray.core.common.protocol.User.email");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_email(), target);
  }

  // .v2ray.core.common.serial.TypedMessage account = 3;
  if (this->has_account()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::account(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:v2ray.core.common.protocol.User)
  return target;
}

size_t User::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:v2ray.core.common.protocol.User)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string email = 2;
  if (this->email().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());
  }

  // .v2ray.core.common.serial.TypedMessage account = 3;
  if (this->has_account()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *account_);
  }

  // uint32 level = 1;
  if (this->level() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_level());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void User::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:v2ray.core.common.protocol.User)
  GOOGLE_DCHECK_NE(&from, this);
  const User* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<User>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:v2ray.core.common.protocol.User)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:v2ray.core.common.protocol.User)
    MergeFrom(*source);
  }
}

void User::MergeFrom(const User& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:v2ray.core.common.protocol.User)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.email().size() > 0) {
    _internal_set_email(from._internal_email());
  }
  if (from.has_account()) {
    _internal_mutable_account()->::v2ray::core::common::serial::TypedMessage::MergeFrom(from._internal_account());
  }
  if (from.level() != 0) {
    _internal_set_level(from._internal_level());
  }
}

void User::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:v2ray.core.common.protocol.User)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void User::CopyFrom(const User& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:v2ray.core.common.protocol.User)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool User::IsInitialized() const {
  return true;
}

void User::InternalSwap(User* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  email_.Swap(&other->email_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(User, level_)
      + sizeof(User::level_)
      - PROTOBUF_FIELD_OFFSET(User, account_)>(
          reinterpret_cast<char*>(&account_),
          reinterpret_cast<char*>(&other->account_));
}

::PROTOBUF_NAMESPACE_ID::Metadata User::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protocol
}  // namespace common
}  // namespace core
}  // namespace v2ray
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::v2ray::core::common::protocol::User* Arena::CreateMaybeMessage< ::v2ray::core::common::protocol::User >(Arena* arena) {
  return Arena::CreateMessageInternal< ::v2ray::core::common::protocol::User >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
