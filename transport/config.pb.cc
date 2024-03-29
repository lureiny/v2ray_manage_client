// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transport/config.proto

#include "transport/config.pb.h"

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
namespace transport {
constexpr Config::Config(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : transport_settings_(){}
struct ConfigDefaultTypeInternal {
  constexpr ConfigDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ConfigDefaultTypeInternal() {}
  union {
    Config _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ConfigDefaultTypeInternal _Config_default_instance_;
}  // namespace transport
}  // namespace core
}  // namespace v2ray
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_transport_2fconfig_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_transport_2fconfig_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_transport_2fconfig_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_transport_2fconfig_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::v2ray::core::transport::Config, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::v2ray::core::transport::Config, transport_settings_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::v2ray::core::transport::Config)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::v2ray::core::transport::_Config_default_instance_),
};

const char descriptor_table_protodef_transport_2fconfig_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026transport/config.proto\022\024v2ray.core.tra"
  "nsport\032\037transport/internet/config.proto\""
  "X\n\006Config\022J\n\022transport_settings\030\001 \003(\0132.."
  "v2ray.core.transport.internet.TransportC"
  "onfig:\002\030\001B]\n\030com.v2ray.core.transportP\001Z"
  "(github.com/v2fly/v2ray-core/v4/transpor"
  "t\252\002\024V2Ray.Core.Transportb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_transport_2fconfig_2eproto_deps[1] = {
  &::descriptor_table_transport_2finternet_2fconfig_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_transport_2fconfig_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transport_2fconfig_2eproto = {
  false, false, 272, descriptor_table_protodef_transport_2fconfig_2eproto, "transport/config.proto", 
  &descriptor_table_transport_2fconfig_2eproto_once, descriptor_table_transport_2fconfig_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_transport_2fconfig_2eproto::offsets,
  file_level_metadata_transport_2fconfig_2eproto, file_level_enum_descriptors_transport_2fconfig_2eproto, file_level_service_descriptors_transport_2fconfig_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_transport_2fconfig_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_transport_2fconfig_2eproto);
  return descriptor_table_transport_2fconfig_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_transport_2fconfig_2eproto(&descriptor_table_transport_2fconfig_2eproto);
namespace v2ray {
namespace core {
namespace transport {

// ===================================================================

class Config::_Internal {
 public:
};

void Config::clear_transport_settings() {
  transport_settings_.Clear();
}
Config::Config(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  transport_settings_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:v2ray.core.transport.Config)
}
Config::Config(const Config& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      transport_settings_(from.transport_settings_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:v2ray.core.transport.Config)
}

void Config::SharedCtor() {
}

Config::~Config() {
  // @@protoc_insertion_point(destructor:v2ray.core.transport.Config)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Config::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Config::ArenaDtor(void* object) {
  Config* _this = reinterpret_cast< Config* >(object);
  (void)_this;
}
void Config::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Config::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Config::Clear() {
// @@protoc_insertion_point(message_clear_start:v2ray.core.transport.Config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  transport_settings_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Config::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .v2ray.core.transport.internet.TransportConfig transport_settings = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_transport_settings(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* Config::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:v2ray.core.transport.Config)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .v2ray.core.transport.internet.TransportConfig transport_settings = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_transport_settings_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_transport_settings(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:v2ray.core.transport.Config)
  return target;
}

size_t Config::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:v2ray.core.transport.Config)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .v2ray.core.transport.internet.TransportConfig transport_settings = 1;
  total_size += 1UL * this->_internal_transport_settings_size();
  for (const auto& msg : this->transport_settings_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Config::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:v2ray.core.transport.Config)
  GOOGLE_DCHECK_NE(&from, this);
  const Config* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Config>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:v2ray.core.transport.Config)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:v2ray.core.transport.Config)
    MergeFrom(*source);
  }
}

void Config::MergeFrom(const Config& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:v2ray.core.transport.Config)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  transport_settings_.MergeFrom(from.transport_settings_);
}

void Config::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:v2ray.core.transport.Config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Config::CopyFrom(const Config& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:v2ray.core.transport.Config)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Config::IsInitialized() const {
  return true;
}

void Config::InternalSwap(Config* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  transport_settings_.InternalSwap(&other->transport_settings_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Config::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace transport
}  // namespace core
}  // namespace v2ray
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::v2ray::core::transport::Config* Arena::CreateMaybeMessage< ::v2ray::core::transport::Config >(Arena* arena) {
  return Arena::CreateMessageInternal< ::v2ray::core::transport::Config >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
