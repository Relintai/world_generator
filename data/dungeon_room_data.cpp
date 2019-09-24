#include "dungeon_room_data.h"

Ref<DungeonRoom> DungeonRoomData::setup_room(int seed) {
	if (has_method("_setup_room")) {
		return call("_setup_room", seed);
	}

	return Ref<DungeonRoom>(NULL);
}

DungeonRoomData::DungeonRoomData() {

}
DungeonRoomData::~DungeonRoomData() {

}

void DungeonRoomData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "room", PROPERTY_HINT_RESOURCE_TYPE, "DungeonRoom"), "_setup_room", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_room", "seed"), &DungeonRoomData::setup_room);
}
