// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Enum.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Enum_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Enum_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Enum_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

enum PlayerType : int {
  PLAYER_TYPE_NONE = 0,
  PLAYER_TYPE_SERANA = 1,
  PLAYER_TYPE_LUKE = 2,
  PlayerType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PlayerType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PlayerType_IsValid(int value);
constexpr PlayerType PlayerType_MIN = PLAYER_TYPE_NONE;
constexpr PlayerType PlayerType_MAX = PLAYER_TYPE_LUKE;
constexpr int PlayerType_ARRAYSIZE = PlayerType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PlayerType_descriptor();
template<typename T>
inline const std::string& PlayerType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PlayerType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PlayerType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PlayerType_descriptor(), enum_t_value);
}
inline bool PlayerType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PlayerType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PlayerType>(
    PlayerType_descriptor(), name, value);
}
enum GameObjectType : int {
  GAME_OBJECT_TYPE_NONE = 0,
  GAME_OBJECT_TYPE_PLAYER = 1,
  GAME_OBJECT_TYPE_MONSTER = 2,
  GAME_OBJECT_TYPE_PROJECTILE = 3,
  GameObjectType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  GameObjectType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool GameObjectType_IsValid(int value);
constexpr GameObjectType GameObjectType_MIN = GAME_OBJECT_TYPE_NONE;
constexpr GameObjectType GameObjectType_MAX = GAME_OBJECT_TYPE_PROJECTILE;
constexpr int GameObjectType_ARRAYSIZE = GameObjectType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* GameObjectType_descriptor();
template<typename T>
inline const std::string& GameObjectType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, GameObjectType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function GameObjectType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    GameObjectType_descriptor(), enum_t_value);
}
inline bool GameObjectType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, GameObjectType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<GameObjectType>(
    GameObjectType_descriptor(), name, value);
}
enum CreatureState : int {
  IDLE = 0,
  RUN_LEFT = 1,
  RUN_RIGHT = 2,
  JUMP = 3,
  FALL = 4,
  SKILL = 5,
  DEAD = 6,
  CreatureState_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  CreatureState_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool CreatureState_IsValid(int value);
constexpr CreatureState CreatureState_MIN = IDLE;
constexpr CreatureState CreatureState_MAX = DEAD;
constexpr int CreatureState_ARRAYSIZE = CreatureState_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CreatureState_descriptor();
template<typename T>
inline const std::string& CreatureState_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CreatureState>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CreatureState_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    CreatureState_descriptor(), enum_t_value);
}
inline bool CreatureState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CreatureState* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CreatureState>(
    CreatureState_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Protocol::PlayerType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::PlayerType>() {
  return ::Protocol::PlayerType_descriptor();
}
template <> struct is_proto_enum< ::Protocol::GameObjectType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::GameObjectType>() {
  return ::Protocol::GameObjectType_descriptor();
}
template <> struct is_proto_enum< ::Protocol::CreatureState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Protocol::CreatureState>() {
  return ::Protocol::CreatureState_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Enum_2eproto
