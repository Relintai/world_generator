#include "planet_data.h"

Ref<Planet> PlanetData::setup_planet(int seed) {
	if (has_method("_setup_planet")) {
		return call("_setup_planet", seed);
	}

	return Ref<Planet>(NULL);
}

PlanetData::PlanetData() {

}
PlanetData::~PlanetData() {

}

void PlanetData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "biome", PROPERTY_HINT_RESOURCE_TYPE, "Planet"), "_setup_planet", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_planet", "seed"), &PlanetData::setup_planet);
}
