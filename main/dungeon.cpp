#include "dungeon.h"

Ref<DungeonRoom> Dungeon::get_dungeon_room(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_rooms.size(), Ref<DungeonRoom>());

	return _dungeon_rooms.get(index);
}
void Dungeon::set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.set(index, dungeon_room);
}
void Dungeon::add_dungeon_room(const Ref<DungeonRoom> dungeon_room) {
	_dungeon_rooms.push_back(dungeon_room);
}
void Dungeon::remove_dungeon_room(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.remove(index);
}

int Dungeon::get_dungeon_room_count() const {
	return _dungeon_rooms.size();
}

void Dungeon::generate_chunk(Ref<VoxelChunk> chunk) {
	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk);
	}
}

void Dungeon::generate_structure(Ref<VoxelStructure> structure) {
	if (has_method("_generate_structure")) {
		call("_generate_structure", structure);
	}
}

Dungeon::Dungeon() {

}
Dungeon::~Dungeon() {

}

void Dungeon::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate_structure", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk")));

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk"), &Dungeon::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_structure", "structure"), &Dungeon::generate_structure);

	ClassDB::bind_method(D_METHOD("get_dungeon_room", "index"), &Dungeon::get_dungeon_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_room", "index", "data"), &Dungeon::set_dungeon_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_room", "dungeon_room"), &Dungeon::add_dungeon_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room", "index"), &Dungeon::remove_dungeon_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_count"), &Dungeon::get_dungeon_room_count);
}
