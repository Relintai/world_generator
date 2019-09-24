#include "dungeon_room.h"

void DungeonRoom::generate_room(Ref<VoxelStructure> structure) {
	if (has_method("_generate_room")) {
		call("_generate_room", structure);
	}
}

DungeonRoom::DungeonRoom() {

}
DungeonRoom::~DungeonRoom() {

}

void DungeonRoom::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate_room", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure")));

	ClassDB::bind_method(D_METHOD("generate_room", "structure"), &DungeonRoom::generate_room);
}
