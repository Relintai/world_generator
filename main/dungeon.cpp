#include "dungeon.h"

void Dungeon::generate(Ref<VoxelStructure> structure) {
	if (has_method("_generate")) {
		call("_generate", structure);
	}
}

Dungeon::Dungeon() {

}
Dungeon::~Dungeon() {

}

void Dungeon::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure")));

	ClassDB::bind_method(D_METHOD("generate", "structure"), &Dungeon::generate);
}
