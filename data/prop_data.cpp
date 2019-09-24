#include "prop_data.h"

bool PropData::can_spawn(int seed) {
	if (has_method("_can_spawn")) {
		return call("_can_spawn", seed);
	}

	return false;
}

Ref<VoxelmanProp> PropData::get_prop(int seed) {
	if (has_method("_get_prop")) {
		return call("_get_prop", seed);
	}

	return Ref<VoxelmanProp>(NULL);
}

PropData::PropData() {

}
PropData::~PropData() {

}

void PropData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::BOOL, "can"), "_can_spawn", PropertyInfo(Variant::INT, "seed")));
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "prop", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanProp"), "_get_prop", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("can_spawn", "seed"), &PropData::can_spawn);
	ClassDB::bind_method(D_METHOD("get_prop", "seed"), &PropData::get_prop);
}
