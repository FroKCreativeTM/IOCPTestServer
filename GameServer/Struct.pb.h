// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
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
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace Protocol {
class Player;
struct PlayerDefaultTypeInternal;
extern PlayerDefaultTypeInternal _Player_default_instance_;
class PosInfo;
struct PosInfoDefaultTypeInternal;
extern PosInfoDefaultTypeInternal _PosInfo_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::Player* Arena::CreateMaybeMessage<::Protocol::Player>(Arena*);
template<> ::Protocol::PosInfo* Arena::CreateMaybeMessage<::Protocol::PosInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class PosInfo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.PosInfo) */ {
 public:
  inline PosInfo() : PosInfo(nullptr) {}
  ~PosInfo() override;
  explicit constexpr PosInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PosInfo(const PosInfo& from);
  PosInfo(PosInfo&& from) noexcept
    : PosInfo() {
    *this = ::std::move(from);
  }

  inline PosInfo& operator=(const PosInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline PosInfo& operator=(PosInfo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PosInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const PosInfo* internal_default_instance() {
    return reinterpret_cast<const PosInfo*>(
               &_PosInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PosInfo& a, PosInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(PosInfo* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PosInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PosInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PosInfo>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PosInfo& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PosInfo& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PosInfo* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.PosInfo";
  }
  protected:
  explicit PosInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPosXFieldNumber = 1,
    kPosYFieldNumber = 2,
    kPosZFieldNumber = 3,
    kYawFieldNumber = 4,
    kRollFieldNumber = 5,
    kPitchFieldNumber = 6,
    kVeloXFieldNumber = 7,
    kVeloYFieldNumber = 8,
    kVeloZFieldNumber = 9,
  };
  // float posX = 1;
  void clear_posx();
  float posx() const;
  void set_posx(float value);
  private:
  float _internal_posx() const;
  void _internal_set_posx(float value);
  public:

  // float posY = 2;
  void clear_posy();
  float posy() const;
  void set_posy(float value);
  private:
  float _internal_posy() const;
  void _internal_set_posy(float value);
  public:

  // float posZ = 3;
  void clear_posz();
  float posz() const;
  void set_posz(float value);
  private:
  float _internal_posz() const;
  void _internal_set_posz(float value);
  public:

  // float yaw = 4;
  void clear_yaw();
  float yaw() const;
  void set_yaw(float value);
  private:
  float _internal_yaw() const;
  void _internal_set_yaw(float value);
  public:

  // float roll = 5;
  void clear_roll();
  float roll() const;
  void set_roll(float value);
  private:
  float _internal_roll() const;
  void _internal_set_roll(float value);
  public:

  // float pitch = 6;
  void clear_pitch();
  float pitch() const;
  void set_pitch(float value);
  private:
  float _internal_pitch() const;
  void _internal_set_pitch(float value);
  public:

  // float veloX = 7;
  void clear_velox();
  float velox() const;
  void set_velox(float value);
  private:
  float _internal_velox() const;
  void _internal_set_velox(float value);
  public:

  // float veloY = 8;
  void clear_veloy();
  float veloy() const;
  void set_veloy(float value);
  private:
  float _internal_veloy() const;
  void _internal_set_veloy(float value);
  public:

  // float veloZ = 9;
  void clear_veloz();
  float veloz() const;
  void set_veloz(float value);
  private:
  float _internal_veloz() const;
  void _internal_set_veloz(float value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.PosInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  float posx_;
  float posy_;
  float posz_;
  float yaw_;
  float roll_;
  float pitch_;
  float velox_;
  float veloy_;
  float veloz_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Struct_2eproto;
};
// -------------------------------------------------------------------

class Player final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.Player) */ {
 public:
  inline Player() : Player(nullptr) {}
  ~Player() override;
  explicit constexpr Player(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Player(const Player& from);
  Player(Player&& from) noexcept
    : Player() {
    *this = ::std::move(from);
  }

  inline Player& operator=(const Player& from) {
    CopyFrom(from);
    return *this;
  }
  inline Player& operator=(Player&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Player& default_instance() {
    return *internal_default_instance();
  }
  static inline const Player* internal_default_instance() {
    return reinterpret_cast<const Player*>(
               &_Player_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Player& a, Player& b) {
    a.Swap(&b);
  }
  inline void Swap(Player* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Player* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Player* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Player>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Player& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Player& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Player* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.Player";
  }
  protected:
  explicit Player(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 2,
    kPosInfoFieldNumber = 6,
    kIdFieldNumber = 1,
    kHealthFieldNumber = 4,
    kIsAliveFieldNumber = 3,
    kIsAttackFieldNumber = 5,
  };
  // string name = 2;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // .Protocol.PosInfo posInfo = 6;
  bool has_posinfo() const;
  private:
  bool _internal_has_posinfo() const;
  public:
  void clear_posinfo();
  const ::Protocol::PosInfo& posinfo() const;
  PROTOBUF_NODISCARD ::Protocol::PosInfo* release_posinfo();
  ::Protocol::PosInfo* mutable_posinfo();
  void set_allocated_posinfo(::Protocol::PosInfo* posinfo);
  private:
  const ::Protocol::PosInfo& _internal_posinfo() const;
  ::Protocol::PosInfo* _internal_mutable_posinfo();
  public:
  void unsafe_arena_set_allocated_posinfo(
      ::Protocol::PosInfo* posinfo);
  ::Protocol::PosInfo* unsafe_arena_release_posinfo();

  // uint64 id = 1;
  void clear_id();
  uint64_t id() const;
  void set_id(uint64_t value);
  private:
  uint64_t _internal_id() const;
  void _internal_set_id(uint64_t value);
  public:

  // int32 health = 4;
  void clear_health();
  int32_t health() const;
  void set_health(int32_t value);
  private:
  int32_t _internal_health() const;
  void _internal_set_health(int32_t value);
  public:

  // bool isAlive = 3;
  void clear_isalive();
  bool isalive() const;
  void set_isalive(bool value);
  private:
  bool _internal_isalive() const;
  void _internal_set_isalive(bool value);
  public:

  // bool isAttack = 5;
  void clear_isattack();
  bool isattack() const;
  void set_isattack(bool value);
  private:
  bool _internal_isattack() const;
  void _internal_set_isattack(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.Player)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::Protocol::PosInfo* posinfo_;
  uint64_t id_;
  int32_t health_;
  bool isalive_;
  bool isattack_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PosInfo

// float posX = 1;
inline void PosInfo::clear_posx() {
  posx_ = 0;
}
inline float PosInfo::_internal_posx() const {
  return posx_;
}
inline float PosInfo::posx() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.posX)
  return _internal_posx();
}
inline void PosInfo::_internal_set_posx(float value) {
  
  posx_ = value;
}
inline void PosInfo::set_posx(float value) {
  _internal_set_posx(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.posX)
}

// float posY = 2;
inline void PosInfo::clear_posy() {
  posy_ = 0;
}
inline float PosInfo::_internal_posy() const {
  return posy_;
}
inline float PosInfo::posy() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.posY)
  return _internal_posy();
}
inline void PosInfo::_internal_set_posy(float value) {
  
  posy_ = value;
}
inline void PosInfo::set_posy(float value) {
  _internal_set_posy(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.posY)
}

// float posZ = 3;
inline void PosInfo::clear_posz() {
  posz_ = 0;
}
inline float PosInfo::_internal_posz() const {
  return posz_;
}
inline float PosInfo::posz() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.posZ)
  return _internal_posz();
}
inline void PosInfo::_internal_set_posz(float value) {
  
  posz_ = value;
}
inline void PosInfo::set_posz(float value) {
  _internal_set_posz(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.posZ)
}

// float yaw = 4;
inline void PosInfo::clear_yaw() {
  yaw_ = 0;
}
inline float PosInfo::_internal_yaw() const {
  return yaw_;
}
inline float PosInfo::yaw() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.yaw)
  return _internal_yaw();
}
inline void PosInfo::_internal_set_yaw(float value) {
  
  yaw_ = value;
}
inline void PosInfo::set_yaw(float value) {
  _internal_set_yaw(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.yaw)
}

// float roll = 5;
inline void PosInfo::clear_roll() {
  roll_ = 0;
}
inline float PosInfo::_internal_roll() const {
  return roll_;
}
inline float PosInfo::roll() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.roll)
  return _internal_roll();
}
inline void PosInfo::_internal_set_roll(float value) {
  
  roll_ = value;
}
inline void PosInfo::set_roll(float value) {
  _internal_set_roll(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.roll)
}

// float pitch = 6;
inline void PosInfo::clear_pitch() {
  pitch_ = 0;
}
inline float PosInfo::_internal_pitch() const {
  return pitch_;
}
inline float PosInfo::pitch() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.pitch)
  return _internal_pitch();
}
inline void PosInfo::_internal_set_pitch(float value) {
  
  pitch_ = value;
}
inline void PosInfo::set_pitch(float value) {
  _internal_set_pitch(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.pitch)
}

// float veloX = 7;
inline void PosInfo::clear_velox() {
  velox_ = 0;
}
inline float PosInfo::_internal_velox() const {
  return velox_;
}
inline float PosInfo::velox() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.veloX)
  return _internal_velox();
}
inline void PosInfo::_internal_set_velox(float value) {
  
  velox_ = value;
}
inline void PosInfo::set_velox(float value) {
  _internal_set_velox(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.veloX)
}

// float veloY = 8;
inline void PosInfo::clear_veloy() {
  veloy_ = 0;
}
inline float PosInfo::_internal_veloy() const {
  return veloy_;
}
inline float PosInfo::veloy() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.veloY)
  return _internal_veloy();
}
inline void PosInfo::_internal_set_veloy(float value) {
  
  veloy_ = value;
}
inline void PosInfo::set_veloy(float value) {
  _internal_set_veloy(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.veloY)
}

// float veloZ = 9;
inline void PosInfo::clear_veloz() {
  veloz_ = 0;
}
inline float PosInfo::_internal_veloz() const {
  return veloz_;
}
inline float PosInfo::veloz() const {
  // @@protoc_insertion_point(field_get:Protocol.PosInfo.veloZ)
  return _internal_veloz();
}
inline void PosInfo::_internal_set_veloz(float value) {
  
  veloz_ = value;
}
inline void PosInfo::set_veloz(float value) {
  _internal_set_veloz(value);
  // @@protoc_insertion_point(field_set:Protocol.PosInfo.veloZ)
}

// -------------------------------------------------------------------

// Player

// uint64 id = 1;
inline void Player::clear_id() {
  id_ = uint64_t{0u};
}
inline uint64_t Player::_internal_id() const {
  return id_;
}
inline uint64_t Player::id() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.id)
  return _internal_id();
}
inline void Player::_internal_set_id(uint64_t value) {
  
  id_ = value;
}
inline void Player::set_id(uint64_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.id)
}

// string name = 2;
inline void Player::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& Player::name() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Player::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.Player.name)
}
inline std::string* Player::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Protocol.Player.name)
  return _s;
}
inline const std::string& Player::_internal_name() const {
  return name_.Get();
}
inline void Player::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Player::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Player::release_name() {
  // @@protoc_insertion_point(field_release:Protocol.Player.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Player::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Protocol.Player.name)
}

// bool isAlive = 3;
inline void Player::clear_isalive() {
  isalive_ = false;
}
inline bool Player::_internal_isalive() const {
  return isalive_;
}
inline bool Player::isalive() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.isAlive)
  return _internal_isalive();
}
inline void Player::_internal_set_isalive(bool value) {
  
  isalive_ = value;
}
inline void Player::set_isalive(bool value) {
  _internal_set_isalive(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.isAlive)
}

// int32 health = 4;
inline void Player::clear_health() {
  health_ = 0;
}
inline int32_t Player::_internal_health() const {
  return health_;
}
inline int32_t Player::health() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.health)
  return _internal_health();
}
inline void Player::_internal_set_health(int32_t value) {
  
  health_ = value;
}
inline void Player::set_health(int32_t value) {
  _internal_set_health(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.health)
}

// bool isAttack = 5;
inline void Player::clear_isattack() {
  isattack_ = false;
}
inline bool Player::_internal_isattack() const {
  return isattack_;
}
inline bool Player::isattack() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.isAttack)
  return _internal_isattack();
}
inline void Player::_internal_set_isattack(bool value) {
  
  isattack_ = value;
}
inline void Player::set_isattack(bool value) {
  _internal_set_isattack(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.isAttack)
}

// .Protocol.PosInfo posInfo = 6;
inline bool Player::_internal_has_posinfo() const {
  return this != internal_default_instance() && posinfo_ != nullptr;
}
inline bool Player::has_posinfo() const {
  return _internal_has_posinfo();
}
inline void Player::clear_posinfo() {
  if (GetArenaForAllocation() == nullptr && posinfo_ != nullptr) {
    delete posinfo_;
  }
  posinfo_ = nullptr;
}
inline const ::Protocol::PosInfo& Player::_internal_posinfo() const {
  const ::Protocol::PosInfo* p = posinfo_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::PosInfo&>(
      ::Protocol::_PosInfo_default_instance_);
}
inline const ::Protocol::PosInfo& Player::posinfo() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.posInfo)
  return _internal_posinfo();
}
inline void Player::unsafe_arena_set_allocated_posinfo(
    ::Protocol::PosInfo* posinfo) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(posinfo_);
  }
  posinfo_ = posinfo;
  if (posinfo) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.Player.posInfo)
}
inline ::Protocol::PosInfo* Player::release_posinfo() {
  
  ::Protocol::PosInfo* temp = posinfo_;
  posinfo_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Protocol::PosInfo* Player::unsafe_arena_release_posinfo() {
  // @@protoc_insertion_point(field_release:Protocol.Player.posInfo)
  
  ::Protocol::PosInfo* temp = posinfo_;
  posinfo_ = nullptr;
  return temp;
}
inline ::Protocol::PosInfo* Player::_internal_mutable_posinfo() {
  
  if (posinfo_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::PosInfo>(GetArenaForAllocation());
    posinfo_ = p;
  }
  return posinfo_;
}
inline ::Protocol::PosInfo* Player::mutable_posinfo() {
  ::Protocol::PosInfo* _msg = _internal_mutable_posinfo();
  // @@protoc_insertion_point(field_mutable:Protocol.Player.posInfo)
  return _msg;
}
inline void Player::set_allocated_posinfo(::Protocol::PosInfo* posinfo) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete posinfo_;
  }
  if (posinfo) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::Protocol::PosInfo>::GetOwningArena(posinfo);
    if (message_arena != submessage_arena) {
      posinfo = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, posinfo, submessage_arena);
    }
    
  } else {
    
  }
  posinfo_ = posinfo;
  // @@protoc_insertion_point(field_set_allocated:Protocol.Player.posInfo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
