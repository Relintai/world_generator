#include "biome_data.h"

Ref<Biome> BiomeData::setup_biome(int seed) {
	if (has_method("_setup_biome")) {
		return call("_setup_biome", seed);
	}

	return Ref<Biome>(NULL);
}

BiomeData::BiomeData() {

}
BiomeData::~BiomeData() {

}

void BiomeData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "room", PROPERTY_HINT_RESOURCE_TYPE, "Biome"), "_setup_biome", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_biome", "seed"), &BiomeData::setup_biome);
}
