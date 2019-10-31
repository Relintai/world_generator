#include "dungeon_corridor.h"

int DungeonCorridor::get_max_connections() {
	return _max_connections;
}
void DungeonCorridor::set_max_connections(int value) {
	_max_connections = value;
}

//Rooms
Ref<DungeonRoom> DungeonCorridor::get_dungeon_room(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_rooms.size(), Ref<DungeonRoom>());

	return _dungeon_rooms.get(index);
}
void DungeonCorridor::set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.set(index, dungeon_room);
}
void DungeonCorridor::add_dungeon_room(const Ref<DungeonRoom> dungeon_room) {
	_dungeon_rooms.push_back(dungeon_room);
}
void DungeonCorridor::remove_dungeon_room(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.remove(index);
}

int DungeonCorridor::get_dungeon_room_count() const {
	return _dungeon_rooms.size();
}

void DungeonCorridor::setup() {
	if (has_method("_setup")) {
		call("_setup");
	}
}

void DungeonCorridor::generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs) {
	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk, spawn_mobs);
	}
}

void DungeonCorridor::generate_structure(Ref<VoxelStructure> structure, bool spawn_mobs) {
	if (has_method("_generate_structure")) {
		call("_generate_structure", structure, spawn_mobs);
	}
}

Ref<Image> DungeonCorridor::generate_map() {
	ERR_FAIL_COND_V(!has_method("_generate_map"), Ref<Image>());

	return call("_generate_map");
}

DungeonCorridor::DungeonCorridor() {
	_max_connections = 2;
}
DungeonCorridor::~DungeonCorridor() {
	_dungeon_rooms.clear();
}

void DungeonCorridor::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_setup"));
	BIND_VMETHOD(MethodInfo("_generate_structure", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));

	ClassDB::bind_method(D_METHOD("setup"), &DungeonCorridor::setup);
	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk", "spawn_mobs"), &DungeonCorridor::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_structure", "structure", "spawn_mobs"), &DungeonCorridor::generate_structure);

	ClassDB::bind_method(D_METHOD("get_max_connections"), &DungeonCorridor::get_max_connections);
	ClassDB::bind_method(D_METHOD("set_max_connections", "value"), &DungeonCorridor::set_max_connections);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_connections"), "set_max_connections", "get_max_connections");

	//Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_room", "index"), &DungeonCorridor::get_dungeon_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_room", "index", "data"), &DungeonCorridor::set_dungeon_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_room", "dungeon_room"), &DungeonCorridor::add_dungeon_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room", "index"), &DungeonCorridor::remove_dungeon_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_count"), &DungeonCorridor::get_dungeon_room_count);

	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "image", PROPERTY_HINT_RESOURCE_TYPE, "Image"), "_generate_map"));

	ClassDB::bind_method(D_METHOD("generate_map"), &DungeonCorridor::generate_map);
}
