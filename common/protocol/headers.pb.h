// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/protocol/headers.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_common_2fprotocol_2fheaders_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_common_2fprotocol_2fheaders_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_common_2fprotocol_2fheaders_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_common_2fprotocol_2fheaders_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_common_2fprotocol_2fheaders_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_common_2fprotocol_2fheaders_2eproto_metadata_getter(int index);
namespace v2ray {
namespace core {
namespace common {
namespace protocol {
class SecurityConfig;
struct SecurityConfigDefaultTypeInternal;
extern SecurityConfigDefaultTypeInternal _SecurityConfig_default_instance_;
}  // namespace protocol
}  // namespace common
}  // namespace core
}  // namespace v2ray
PROTOBUF_NAMESPACE_OPEN
template<> ::v2ray::core::common::protocol::SecurityConfig* Arena::CreateMaybeMessage<::v2ray::core::common::protocol::SecurityConfig>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace v2ray {
namespace core {
namespace common {
namespace protocol {

enum SecurityType : int {
  UNKNOWN = 0,
  LEGACY = 1,
  AUTO = 2,
  AES128_GCM = 3,
  CHACHA20_POLY1305 = 4,
  NONE = 5,
  ZERO = 6,
  SecurityType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  SecurityType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool SecurityType_IsValid(int value);
constexpr SecurityType SecurityType_MIN = UNKNOWN;
constexpr SecurityType SecurityType_MAX = ZERO;
constexpr int SecurityType_ARRAYSIZE = SecurityType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SecurityType_descriptor();
template<typename T>
inline const std::string& SecurityType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SecurityType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SecurityType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    SecurityType_descriptor(), enum_t_value);
}
inline bool SecurityType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, SecurityType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<SecurityType>(
    SecurityType_descriptor(), name, value);
}
// ===================================================================

class SecurityConfig PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:v2ray.core.common.protocol.SecurityConfig) */ {
 public:
  inline SecurityConfig() : SecurityConfig(nullptr) {}
  virtual ~SecurityConfig();
  explicit constexpr SecurityConfig(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SecurityConfig(const SecurityConfig& from);
  SecurityConfig(SecurityConfig&& from) noexcept
    : SecurityConfig() {
    *this = ::std::move(from);
  }

  inline SecurityConfig& operator=(const SecurityConfig& from) {
    CopyFrom(from);
    return *this;
  }
  inline SecurityConfig& operator=(SecurityConfig&& from) noexcept {
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
  static const SecurityConfig& default_instance() {
    return *internal_default_instance();
  }
  static inline const SecurityConfig* internal_default_instance() {
    return reinterpret_cast<const SecurityConfig*>(
               &_SecurityConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SecurityConfig& a, SecurityConfig& b) {
    a.Swap(&b);
  }
  inline void Swap(SecurityConfig* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SecurityConfig* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SecurityConfig* New() const final {
    return CreateMaybeMessage<SecurityConfig>(nullptr);
  }

  SecurityConfig* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SecurityConfig>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SecurityConfig& from);
  void MergeFrom(const SecurityConfig& from);
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
  void InternalSwap(SecurityConfig* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "v2ray.core.common.protocol.SecurityConfig";
  }
  protected:
  explicit SecurityConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_common_2fprotocol_2fheaders_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTypeFieldNumber = 1,
  };
  // .v2ray.core.common.protocol.SecurityType type = 1;
  void clear_type();
  ::v2ray::core::common::protocol::SecurityType type() const;
  void set_type(::v2ray::core::common::protocol::SecurityType value);
  private:
  ::v2ray::core::common::protocol::SecurityType _internal_type() const;
  void _internal_set_type(::v2ray::core::common::protocol::SecurityType value);
  public:

  // @@protoc_insertion_point(class_scope:v2ray.core.common.protocol.SecurityConfig)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_common_2fprotocol_2fheaders_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SecurityConfig

// .v2ray.core.common.protocol.SecurityType type = 1;
inline void SecurityConfig::clear_type() {
  type_ = 0;
}
inline ::v2ray::core::common::protocol::SecurityType SecurityConfig::_internal_type() const {
  return static_cast< ::v2ray::core::common::protocol::SecurityType >(type_);
}
inline ::v2ray::core::common::protocol::SecurityType SecurityConfig::type() const {
  // @@protoc_insertion_point(field_get:v2ray.core.common.protocol.SecurityConfig.type)
  return _internal_type();
}
inline void SecurityConfig::_internal_set_type(::v2ray::core::common::protocol::SecurityType value) {
  
  type_ = value;
}
inline void SecurityConfig::set_type(::v2ray::core::common::protocol::SecurityType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:v2ray.core.common.protocol.SecurityConfig.type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace common
}  // namespace core
}  // namespace v2ray

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::v2ray::core::common::protocol::SecurityType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::v2ray::core::common::protocol::SecurityType>() {
  return ::v2ray::core::common::protocol::SecurityType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_common_2fprotocol_2fheaders_2eproto
