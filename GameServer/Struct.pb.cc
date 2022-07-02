// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#include "Struct.pb.h"

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
namespace Protocol {
constexpr PosInfo::PosInfo(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : posx_(0)
  , posy_(0)
  , posz_(0)
  , yaw_(0)
  , roll_(0)
  , pitch_(0)
  , velox_(0)
  , veloy_(0)
  , veloz_(0){}
struct PosInfoDefaultTypeInternal {
  constexpr PosInfoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PosInfoDefaultTypeInternal() {}
  union {
    PosInfo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PosInfoDefaultTypeInternal _PosInfo_default_instance_;
constexpr Player::Player(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , posinfo_(nullptr)
  , id_(uint64_t{0u})
  , health_(0)
  , isalive_(false)
  , isattack_(false){}
struct PlayerDefaultTypeInternal {
  constexpr PlayerDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PlayerDefaultTypeInternal() {}
  union {
    Player _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PlayerDefaultTypeInternal _Player_default_instance_;
}  // namespace Protocol
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Struct_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Struct_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Struct_2eproto = nullptr;

const uint32_t TableStruct_Struct_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, posx_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, posy_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, posz_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, yaw_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, roll_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, pitch_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, velox_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, veloy_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PosInfo, veloz_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, id_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, name_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, isalive_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, health_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, isattack_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Player, posinfo_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::PosInfo)},
  { 15, -1, -1, sizeof(::Protocol::Player)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_PosInfo_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_Player_default_instance_),
};

const char descriptor_table_protodef_Struct_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Struct.proto\022\010Protocol\032\nEnum.proto\"\212\001\n"
  "\007PosInfo\022\014\n\004posX\030\001 \001(\002\022\014\n\004posY\030\002 \001(\002\022\014\n\004"
  "posZ\030\003 \001(\002\022\013\n\003yaw\030\004 \001(\002\022\014\n\004roll\030\005 \001(\002\022\r\n"
  "\005pitch\030\006 \001(\002\022\r\n\005veloX\030\007 \001(\002\022\r\n\005veloY\030\010 \001"
  "(\002\022\r\n\005veloZ\030\t \001(\002\"y\n\006Player\022\n\n\002id\030\001 \001(\004\022"
  "\014\n\004name\030\002 \001(\t\022\017\n\007isAlive\030\003 \001(\010\022\016\n\006health"
  "\030\004 \001(\005\022\020\n\010isAttack\030\005 \001(\010\022\"\n\007posInfo\030\006 \001("
  "\0132\021.Protocol.PosInfob\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Struct_2eproto_deps[1] = {
  &::descriptor_table_Enum_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Struct_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto = {
  false, false, 308, descriptor_table_protodef_Struct_2eproto, "Struct.proto", 
  &descriptor_table_Struct_2eproto_once, descriptor_table_Struct_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_Struct_2eproto::offsets,
  file_level_metadata_Struct_2eproto, file_level_enum_descriptors_Struct_2eproto, file_level_service_descriptors_Struct_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Struct_2eproto_getter() {
  return &descriptor_table_Struct_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Struct_2eproto(&descriptor_table_Struct_2eproto);
namespace Protocol {

// ===================================================================

class PosInfo::_Internal {
 public:
};

PosInfo::PosInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Protocol.PosInfo)
}
PosInfo::PosInfo(const PosInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&posx_, &from.posx_,
    static_cast<size_t>(reinterpret_cast<char*>(&veloz_) -
    reinterpret_cast<char*>(&posx_)) + sizeof(veloz_));
  // @@protoc_insertion_point(copy_constructor:Protocol.PosInfo)
}

inline void PosInfo::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&posx_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&veloz_) -
    reinterpret_cast<char*>(&posx_)) + sizeof(veloz_));
}

PosInfo::~PosInfo() {
  // @@protoc_insertion_point(destructor:Protocol.PosInfo)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void PosInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void PosInfo::ArenaDtor(void* object) {
  PosInfo* _this = reinterpret_cast< PosInfo* >(object);
  (void)_this;
}
void PosInfo::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PosInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void PosInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.PosInfo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&posx_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&veloz_) -
      reinterpret_cast<char*>(&posx_)) + sizeof(veloz_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PosInfo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float posX = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 13)) {
          posx_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float posY = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 21)) {
          posy_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float posZ = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 29)) {
          posz_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float yaw = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 37)) {
          yaw_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float roll = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 45)) {
          roll_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float pitch = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 53)) {
          pitch_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float veloX = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 61)) {
          velox_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float veloY = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 69)) {
          veloy_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // float veloZ = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 77)) {
          veloz_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PosInfo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.PosInfo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // float posX = 1;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posx = this->_internal_posx();
  uint32_t raw_posx;
  memcpy(&raw_posx, &tmp_posx, sizeof(tmp_posx));
  if (raw_posx != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_posx(), target);
  }

  // float posY = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posy = this->_internal_posy();
  uint32_t raw_posy;
  memcpy(&raw_posy, &tmp_posy, sizeof(tmp_posy));
  if (raw_posy != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_posy(), target);
  }

  // float posZ = 3;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posz = this->_internal_posz();
  uint32_t raw_posz;
  memcpy(&raw_posz, &tmp_posz, sizeof(tmp_posz));
  if (raw_posz != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_posz(), target);
  }

  // float yaw = 4;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_yaw = this->_internal_yaw();
  uint32_t raw_yaw;
  memcpy(&raw_yaw, &tmp_yaw, sizeof(tmp_yaw));
  if (raw_yaw != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_yaw(), target);
  }

  // float roll = 5;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_roll = this->_internal_roll();
  uint32_t raw_roll;
  memcpy(&raw_roll, &tmp_roll, sizeof(tmp_roll));
  if (raw_roll != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(5, this->_internal_roll(), target);
  }

  // float pitch = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_pitch = this->_internal_pitch();
  uint32_t raw_pitch;
  memcpy(&raw_pitch, &tmp_pitch, sizeof(tmp_pitch));
  if (raw_pitch != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(6, this->_internal_pitch(), target);
  }

  // float veloX = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_velox = this->_internal_velox();
  uint32_t raw_velox;
  memcpy(&raw_velox, &tmp_velox, sizeof(tmp_velox));
  if (raw_velox != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(7, this->_internal_velox(), target);
  }

  // float veloY = 8;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_veloy = this->_internal_veloy();
  uint32_t raw_veloy;
  memcpy(&raw_veloy, &tmp_veloy, sizeof(tmp_veloy));
  if (raw_veloy != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(8, this->_internal_veloy(), target);
  }

  // float veloZ = 9;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_veloz = this->_internal_veloz();
  uint32_t raw_veloz;
  memcpy(&raw_veloz, &tmp_veloz, sizeof(tmp_veloz));
  if (raw_veloz != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(9, this->_internal_veloz(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.PosInfo)
  return target;
}

size_t PosInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.PosInfo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float posX = 1;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posx = this->_internal_posx();
  uint32_t raw_posx;
  memcpy(&raw_posx, &tmp_posx, sizeof(tmp_posx));
  if (raw_posx != 0) {
    total_size += 1 + 4;
  }

  // float posY = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posy = this->_internal_posy();
  uint32_t raw_posy;
  memcpy(&raw_posy, &tmp_posy, sizeof(tmp_posy));
  if (raw_posy != 0) {
    total_size += 1 + 4;
  }

  // float posZ = 3;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posz = this->_internal_posz();
  uint32_t raw_posz;
  memcpy(&raw_posz, &tmp_posz, sizeof(tmp_posz));
  if (raw_posz != 0) {
    total_size += 1 + 4;
  }

  // float yaw = 4;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_yaw = this->_internal_yaw();
  uint32_t raw_yaw;
  memcpy(&raw_yaw, &tmp_yaw, sizeof(tmp_yaw));
  if (raw_yaw != 0) {
    total_size += 1 + 4;
  }

  // float roll = 5;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_roll = this->_internal_roll();
  uint32_t raw_roll;
  memcpy(&raw_roll, &tmp_roll, sizeof(tmp_roll));
  if (raw_roll != 0) {
    total_size += 1 + 4;
  }

  // float pitch = 6;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_pitch = this->_internal_pitch();
  uint32_t raw_pitch;
  memcpy(&raw_pitch, &tmp_pitch, sizeof(tmp_pitch));
  if (raw_pitch != 0) {
    total_size += 1 + 4;
  }

  // float veloX = 7;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_velox = this->_internal_velox();
  uint32_t raw_velox;
  memcpy(&raw_velox, &tmp_velox, sizeof(tmp_velox));
  if (raw_velox != 0) {
    total_size += 1 + 4;
  }

  // float veloY = 8;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_veloy = this->_internal_veloy();
  uint32_t raw_veloy;
  memcpy(&raw_veloy, &tmp_veloy, sizeof(tmp_veloy));
  if (raw_veloy != 0) {
    total_size += 1 + 4;
  }

  // float veloZ = 9;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_veloz = this->_internal_veloz();
  uint32_t raw_veloz;
  memcpy(&raw_veloz, &tmp_veloz, sizeof(tmp_veloz));
  if (raw_veloz != 0) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PosInfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    PosInfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PosInfo::GetClassData() const { return &_class_data_; }

void PosInfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<PosInfo *>(to)->MergeFrom(
      static_cast<const PosInfo &>(from));
}


void PosInfo::MergeFrom(const PosInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.PosInfo)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posx = from._internal_posx();
  uint32_t raw_posx;
  memcpy(&raw_posx, &tmp_posx, sizeof(tmp_posx));
  if (raw_posx != 0) {
    _internal_set_posx(from._internal_posx());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posy = from._internal_posy();
  uint32_t raw_posy;
  memcpy(&raw_posy, &tmp_posy, sizeof(tmp_posy));
  if (raw_posy != 0) {
    _internal_set_posy(from._internal_posy());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_posz = from._internal_posz();
  uint32_t raw_posz;
  memcpy(&raw_posz, &tmp_posz, sizeof(tmp_posz));
  if (raw_posz != 0) {
    _internal_set_posz(from._internal_posz());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_yaw = from._internal_yaw();
  uint32_t raw_yaw;
  memcpy(&raw_yaw, &tmp_yaw, sizeof(tmp_yaw));
  if (raw_yaw != 0) {
    _internal_set_yaw(from._internal_yaw());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_roll = from._internal_roll();
  uint32_t raw_roll;
  memcpy(&raw_roll, &tmp_roll, sizeof(tmp_roll));
  if (raw_roll != 0) {
    _internal_set_roll(from._internal_roll());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_pitch = from._internal_pitch();
  uint32_t raw_pitch;
  memcpy(&raw_pitch, &tmp_pitch, sizeof(tmp_pitch));
  if (raw_pitch != 0) {
    _internal_set_pitch(from._internal_pitch());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_velox = from._internal_velox();
  uint32_t raw_velox;
  memcpy(&raw_velox, &tmp_velox, sizeof(tmp_velox));
  if (raw_velox != 0) {
    _internal_set_velox(from._internal_velox());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_veloy = from._internal_veloy();
  uint32_t raw_veloy;
  memcpy(&raw_veloy, &tmp_veloy, sizeof(tmp_veloy));
  if (raw_veloy != 0) {
    _internal_set_veloy(from._internal_veloy());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_veloz = from._internal_veloz();
  uint32_t raw_veloz;
  memcpy(&raw_veloz, &tmp_veloz, sizeof(tmp_veloz));
  if (raw_veloz != 0) {
    _internal_set_veloz(from._internal_veloz());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PosInfo::CopyFrom(const PosInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.PosInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PosInfo::IsInitialized() const {
  return true;
}

void PosInfo::InternalSwap(PosInfo* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PosInfo, veloz_)
      + sizeof(PosInfo::veloz_)
      - PROTOBUF_FIELD_OFFSET(PosInfo, posx_)>(
          reinterpret_cast<char*>(&posx_),
          reinterpret_cast<char*>(&other->posx_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PosInfo::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[0]);
}

// ===================================================================

class Player::_Internal {
 public:
  static const ::Protocol::PosInfo& posinfo(const Player* msg);
};

const ::Protocol::PosInfo&
Player::_Internal::posinfo(const Player* msg) {
  return *msg->posinfo_;
}
Player::Player(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Protocol.Player)
}
Player::Player(const Player& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_posinfo()) {
    posinfo_ = new ::Protocol::PosInfo(*from.posinfo_);
  } else {
    posinfo_ = nullptr;
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&isattack_) -
    reinterpret_cast<char*>(&id_)) + sizeof(isattack_));
  // @@protoc_insertion_point(copy_constructor:Protocol.Player)
}

inline void Player::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&posinfo_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&isattack_) -
    reinterpret_cast<char*>(&posinfo_)) + sizeof(isattack_));
}

Player::~Player() {
  // @@protoc_insertion_point(destructor:Protocol.Player)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Player::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete posinfo_;
}

void Player::ArenaDtor(void* object) {
  Player* _this = reinterpret_cast< Player* >(object);
  (void)_this;
}
void Player::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Player::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Player::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.Player)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && posinfo_ != nullptr) {
    delete posinfo_;
  }
  posinfo_ = nullptr;
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&isattack_) -
      reinterpret_cast<char*>(&id_)) + sizeof(isattack_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Player::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Protocol.Player.name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool isAlive = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          isalive_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 health = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          health_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool isAttack = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          isattack_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Protocol.PosInfo posInfo = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_posinfo(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Player::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.Player)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_id(), target);
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.Player.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // bool isAlive = 3;
  if (this->_internal_isalive() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_isalive(), target);
  }

  // int32 health = 4;
  if (this->_internal_health() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(4, this->_internal_health(), target);
  }

  // bool isAttack = 5;
  if (this->_internal_isattack() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_isattack(), target);
  }

  // .Protocol.PosInfo posInfo = 6;
  if (this->_internal_has_posinfo()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        6, _Internal::posinfo(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.Player)
  return target;
}

size_t Player::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.Player)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // .Protocol.PosInfo posInfo = 6;
  if (this->_internal_has_posinfo()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *posinfo_);
  }

  // uint64 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64SizePlusOne(this->_internal_id());
  }

  // int32 health = 4;
  if (this->_internal_health() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_health());
  }

  // bool isAlive = 3;
  if (this->_internal_isalive() != 0) {
    total_size += 1 + 1;
  }

  // bool isAttack = 5;
  if (this->_internal_isattack() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Player::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Player::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Player::GetClassData() const { return &_class_data_; }

void Player::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Player *>(to)->MergeFrom(
      static_cast<const Player &>(from));
}


void Player::MergeFrom(const Player& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.Player)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (from._internal_has_posinfo()) {
    _internal_mutable_posinfo()->::Protocol::PosInfo::MergeFrom(from._internal_posinfo());
  }
  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_health() != 0) {
    _internal_set_health(from._internal_health());
  }
  if (from._internal_isalive() != 0) {
    _internal_set_isalive(from._internal_isalive());
  }
  if (from._internal_isattack() != 0) {
    _internal_set_isattack(from._internal_isattack());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Player::CopyFrom(const Player& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.Player)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Player::IsInitialized() const {
  return true;
}

void Player::InternalSwap(Player* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, lhs_arena,
      &other->name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Player, isattack_)
      + sizeof(Player::isattack_)
      - PROTOBUF_FIELD_OFFSET(Player, posinfo_)>(
          reinterpret_cast<char*>(&posinfo_),
          reinterpret_cast<char*>(&other->posinfo_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Player::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Struct_2eproto_getter, &descriptor_table_Struct_2eproto_once,
      file_level_metadata_Struct_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::PosInfo* Arena::CreateMaybeMessage< ::Protocol::PosInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::PosInfo >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::Player* Arena::CreateMaybeMessage< ::Protocol::Player >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::Player >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
