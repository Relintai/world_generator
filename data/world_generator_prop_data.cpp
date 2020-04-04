/*
Copyright (c) 2019-2020 Péter Magyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "world_generator_prop_data.h"

#include "scene/resources/packed_scene.h"

bool WorldGeneratorPropData::can_spawn(int seed) {
	if (has_method("_can_spawn")) {
		return call("_can_spawn", seed);
	}

	return false;
}

Ref<PackedScene> WorldGeneratorPropData::get_prop() {
	return _prop;
}
void WorldGeneratorPropData::set_prop(Ref<PackedScene> value) {
	_prop = value;
}

Ref<PackedScene> WorldGeneratorPropData::get_prop_seeded(int seed) {
	if (has_method("_get_prop_seeded")) {
		return call("_get_prop_seeded", seed);
	}

	return Ref<PackedScene>();
}

WorldGeneratorPropData::WorldGeneratorPropData() {
}
WorldGeneratorPropData::~WorldGeneratorPropData() {
	_prop.unref();
}

void WorldGeneratorPropData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::BOOL, "can"), "_can_spawn", PropertyInfo(Variant::INT, "seed")));

	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "prop", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "_get_prop_seeded", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("get_prop"), &WorldGeneratorPropData::get_prop);
	ClassDB::bind_method(D_METHOD("set_prop"), &WorldGeneratorPropData::set_prop);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "prop", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "set_prop", "get_prop");

	ClassDB::bind_method(D_METHOD("can_spawn", "seed"), &WorldGeneratorPropData::can_spawn);
	ClassDB::bind_method(D_METHOD("get_prop_seeded", "seed"), &WorldGeneratorPropData::get_prop_seeded);
}
