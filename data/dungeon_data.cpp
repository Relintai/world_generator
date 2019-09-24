#include "dungeon_data.h"

Ref<Dungeon> DungeonData::setup_dungeon(int seed) {
	if (has_method("_setup_dungeon")) {
		return call("_setup_dungeon", seed);
	}

	return Ref<Dungeon>(NULL);
}

DungeonData::DungeonData() {

}
DungeonData::~DungeonData() {

}

void DungeonData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "room", PROPERTY_HINT_RESOURCE_TYPE, "Dungeon"), "_setup_dungeon", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_dungeon", "seed"), &DungeonData::setup_dungeon);
}
