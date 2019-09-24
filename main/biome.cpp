#include "biome.h"

void Biome::generate_chunk(Ref<VoxelChunk> chunk) {
	if (has_method("_generate")) {
		call("_generate", chunk);
	}
}
void Biome::generate_stack(Ref<VoxelChunk> chunk, int x, int z) {
	if (has_method("_generate")) {
		call("_generate", chunk, x, z);
	}
}

Biome::Biome() {

}
Biome::~Biome() {

}

void Biome::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk")));
	BIND_VMETHOD(MethodInfo("_generate_stack", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::INT, "x"), PropertyInfo(Variant::INT, "z")));

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk"), &Biome::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_stack", "chunk", "x", "z"), &Biome::generate_stack);
}
