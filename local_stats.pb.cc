// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: local_stats.proto

#include "local_stats.pb.h"

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
namespace local {
constexpr Online::Online(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : stats_(){}
struct OnlineDefaultTypeInternal {
  constexpr OnlineDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~OnlineDefaultTypeInternal() {}
  union {
    Online _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT OnlineDefaultTypeInternal _Online_default_instance_;
constexpr History::History(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : stats_(){}
struct HistoryDefaultTypeInternal {
  constexpr HistoryDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~HistoryDefaultTypeInternal() {}
  union {
    History _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT HistoryDefaultTypeInternal _History_default_instance_;
constexpr LocalStats::LocalStats(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : online_(nullptr)
  , history_(nullptr)
  , last_start_time_(PROTOBUF_LONGLONG(0)){}
struct LocalStatsDefaultTypeInternal {
  constexpr LocalStatsDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LocalStatsDefaultTypeInternal() {}
  union {
    LocalStats _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LocalStatsDefaultTypeInternal _LocalStats_default_instance_;
}  // namespace local
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_local_5fstats_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_local_5fstats_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_local_5fstats_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_local_5fstats_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::local::Online, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::local::Online, stats_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::local::History, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::local::History, stats_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::local::LocalStats, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::local::LocalStats, online_),
  PROTOBUF_FIELD_OFFSET(::local::LocalStats, history_),
  PROTOBUF_FIELD_OFFSET(::local::LocalStats, last_start_time_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::local::Online)},
  { 6, -1, sizeof(::local::History)},
  { 12, -1, sizeof(::local::LocalStats)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::local::_Online_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::local::_History_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::local::_LocalStats_default_instance_),
};

const char descriptor_table_protodef_local_5fstats_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021local_stats.proto\022\005local\032\013redis.proto\""
  "%\n\006Online\022\033\n\005stats\030\001 \003(\0132\014.redis.Stats\"&"
  "\n\007History\022\033\n\005stats\030\001 \003(\0132\014.redis.Stats\"e"
  "\n\nLocalStats\022\035\n\006online\030\001 \001(\0132\r.local.Onl"
  "ine\022\037\n\007history\030\002 \001(\0132\016.local.History\022\027\n\017"
  "last_start_time\030\003 \001(\003b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_local_5fstats_2eproto_deps[1] = {
  &::descriptor_table_redis_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_local_5fstats_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_local_5fstats_2eproto = {
  false, false, 229, descriptor_table_protodef_local_5fstats_2eproto, "local_stats.proto", 
  &descriptor_table_local_5fstats_2eproto_once, descriptor_table_local_5fstats_2eproto_deps, 1, 3,
  schemas, file_default_instances, TableStruct_local_5fstats_2eproto::offsets,
  file_level_metadata_local_5fstats_2eproto, file_level_enum_descriptors_local_5fstats_2eproto, file_level_service_descriptors_local_5fstats_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_local_5fstats_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_local_5fstats_2eproto);
  return descriptor_table_local_5fstats_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_local_5fstats_2eproto(&descriptor_table_local_5fstats_2eproto);
namespace local {

// ===================================================================

class Online::_Internal {
 public:
};

void Online::clear_stats() {
  stats_.Clear();
}
Online::Online(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  stats_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:local.Online)
}
Online::Online(const Online& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      stats_(from.stats_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:local.Online)
}

void Online::SharedCtor() {
}

Online::~Online() {
  // @@protoc_insertion_point(destructor:local.Online)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Online::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Online::ArenaDtor(void* object) {
  Online* _this = reinterpret_cast< Online* >(object);
  (void)_this;
}
void Online::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Online::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Online::Clear() {
// @@protoc_insertion_point(message_clear_start:local.Online)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  stats_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Online::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .redis.Stats stats = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_stats(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Online::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:local.Online)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .redis.Stats stats = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_stats_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_stats(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:local.Online)
  return target;
}

size_t Online::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:local.Online)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .redis.Stats stats = 1;
  total_size += 1UL * this->_internal_stats_size();
  for (const auto& msg : this->stats_) {
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

void Online::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:local.Online)
  GOOGLE_DCHECK_NE(&from, this);
  const Online* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Online>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:local.Online)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:local.Online)
    MergeFrom(*source);
  }
}

void Online::MergeFrom(const Online& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:local.Online)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  stats_.MergeFrom(from.stats_);
}

void Online::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:local.Online)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Online::CopyFrom(const Online& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:local.Online)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Online::IsInitialized() const {
  return true;
}

void Online::InternalSwap(Online* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  stats_.InternalSwap(&other->stats_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Online::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class History::_Internal {
 public:
};

void History::clear_stats() {
  stats_.Clear();
}
History::History(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  stats_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:local.History)
}
History::History(const History& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      stats_(from.stats_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:local.History)
}

void History::SharedCtor() {
}

History::~History() {
  // @@protoc_insertion_point(destructor:local.History)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void History::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void History::ArenaDtor(void* object) {
  History* _this = reinterpret_cast< History* >(object);
  (void)_this;
}
void History::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void History::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void History::Clear() {
// @@protoc_insertion_point(message_clear_start:local.History)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  stats_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* History::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .redis.Stats stats = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_stats(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* History::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:local.History)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .redis.Stats stats = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_stats_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_stats(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:local.History)
  return target;
}

size_t History::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:local.History)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .redis.Stats stats = 1;
  total_size += 1UL * this->_internal_stats_size();
  for (const auto& msg : this->stats_) {
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

void History::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:local.History)
  GOOGLE_DCHECK_NE(&from, this);
  const History* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<History>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:local.History)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:local.History)
    MergeFrom(*source);
  }
}

void History::MergeFrom(const History& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:local.History)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  stats_.MergeFrom(from.stats_);
}

void History::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:local.History)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void History::CopyFrom(const History& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:local.History)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool History::IsInitialized() const {
  return true;
}

void History::InternalSwap(History* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  stats_.InternalSwap(&other->stats_);
}

::PROTOBUF_NAMESPACE_ID::Metadata History::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class LocalStats::_Internal {
 public:
  static const ::local::Online& online(const LocalStats* msg);
  static const ::local::History& history(const LocalStats* msg);
};

const ::local::Online&
LocalStats::_Internal::online(const LocalStats* msg) {
  return *msg->online_;
}
const ::local::History&
LocalStats::_Internal::history(const LocalStats* msg) {
  return *msg->history_;
}
LocalStats::LocalStats(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:local.LocalStats)
}
LocalStats::LocalStats(const LocalStats& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_online()) {
    online_ = new ::local::Online(*from.online_);
  } else {
    online_ = nullptr;
  }
  if (from._internal_has_history()) {
    history_ = new ::local::History(*from.history_);
  } else {
    history_ = nullptr;
  }
  last_start_time_ = from.last_start_time_;
  // @@protoc_insertion_point(copy_constructor:local.LocalStats)
}

void LocalStats::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&online_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&last_start_time_) -
    reinterpret_cast<char*>(&online_)) + sizeof(last_start_time_));
}

LocalStats::~LocalStats() {
  // @@protoc_insertion_point(destructor:local.LocalStats)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void LocalStats::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete online_;
  if (this != internal_default_instance()) delete history_;
}

void LocalStats::ArenaDtor(void* object) {
  LocalStats* _this = reinterpret_cast< LocalStats* >(object);
  (void)_this;
}
void LocalStats::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LocalStats::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LocalStats::Clear() {
// @@protoc_insertion_point(message_clear_start:local.LocalStats)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && online_ != nullptr) {
    delete online_;
  }
  online_ = nullptr;
  if (GetArena() == nullptr && history_ != nullptr) {
    delete history_;
  }
  history_ = nullptr;
  last_start_time_ = PROTOBUF_LONGLONG(0);
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LocalStats::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .local.Online online = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_online(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .local.History history = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_history(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 last_start_time = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          last_start_time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* LocalStats::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:local.LocalStats)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .local.Online online = 1;
  if (this->has_online()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::online(this), target, stream);
  }

  // .local.History history = 2;
  if (this->has_history()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::history(this), target, stream);
  }

  // int64 last_start_time = 3;
  if (this->last_start_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(3, this->_internal_last_start_time(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:local.LocalStats)
  return target;
}

size_t LocalStats::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:local.LocalStats)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .local.Online online = 1;
  if (this->has_online()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *online_);
  }

  // .local.History history = 2;
  if (this->has_history()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *history_);
  }

  // int64 last_start_time = 3;
  if (this->last_start_time() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_last_start_time());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LocalStats::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:local.LocalStats)
  GOOGLE_DCHECK_NE(&from, this);
  const LocalStats* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<LocalStats>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:local.LocalStats)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:local.LocalStats)
    MergeFrom(*source);
  }
}

void LocalStats::MergeFrom(const LocalStats& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:local.LocalStats)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_online()) {
    _internal_mutable_online()->::local::Online::MergeFrom(from._internal_online());
  }
  if (from.has_history()) {
    _internal_mutable_history()->::local::History::MergeFrom(from._internal_history());
  }
  if (from.last_start_time() != 0) {
    _internal_set_last_start_time(from._internal_last_start_time());
  }
}

void LocalStats::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:local.LocalStats)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LocalStats::CopyFrom(const LocalStats& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:local.LocalStats)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LocalStats::IsInitialized() const {
  return true;
}

void LocalStats::InternalSwap(LocalStats* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LocalStats, last_start_time_)
      + sizeof(LocalStats::last_start_time_)
      - PROTOBUF_FIELD_OFFSET(LocalStats, online_)>(
          reinterpret_cast<char*>(&online_),
          reinterpret_cast<char*>(&other->online_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LocalStats::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace local
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::local::Online* Arena::CreateMaybeMessage< ::local::Online >(Arena* arena) {
  return Arena::CreateMessageInternal< ::local::Online >(arena);
}
template<> PROTOBUF_NOINLINE ::local::History* Arena::CreateMaybeMessage< ::local::History >(Arena* arena) {
  return Arena::CreateMessageInternal< ::local::History >(arena);
}
template<> PROTOBUF_NOINLINE ::local::LocalStats* Arena::CreateMaybeMessage< ::local::LocalStats >(Arena* arena) {
  return Arena::CreateMessageInternal< ::local::LocalStats >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
