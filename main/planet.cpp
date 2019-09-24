#include "planet.h"

void Planet::generate_chunk(Ref<VoxelChunk> chunk) {
	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk);
	}
}

Planet::Planet() {

}
Planet::~Planet() {

}

void Planet::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk")));

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk"), &Planet::generate_chunk);
}
