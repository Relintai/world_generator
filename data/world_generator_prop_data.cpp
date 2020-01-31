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

bool WorldGeneratorPropData::can_spawn(int seed) {
	if (has_method("_can_spawn")) {
		return call("_can_spawn", seed);
	}

	return false;
}

#ifdef VOXELMAN_PRESENT
Ref<PropData> WorldGeneratorPropData::get_prop(int seed) {
	if (has_method("_get_prop")) {
		return call("_get_prop", seed);
	}

	return Ref<PropData>(NULL);
}
#else
Ref<Resource> WorldGeneratorPropData::get_prop(int seed) {
	if (has_method("_get_prop")) {
		return call("_get_prop", seed);
	}

	return Ref<Resource>(NULL);
}
#endif

WorldGeneratorPropData::WorldGeneratorPropData() {
}
WorldGeneratorPropData::~WorldGeneratorPropData() {
}

void WorldGeneratorPropData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::BOOL, "can"), "_can_spawn", PropertyInfo(Variant::INT, "seed")));

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "prop", PROPERTY_HINT_RESOURCE_TYPE, "PropData"), "_get_prop", PropertyInfo(Variant::INT, "seed")));
#else
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "prop", PROPERTY_HINT_RESOURCE_TYPE, "Resource"), "_get_prop", PropertyInfo(Variant::INT, "seed")));
#endif

	ClassDB::bind_method(D_METHOD("can_spawn", "seed"), &WorldGeneratorPropData::can_spawn);
	ClassDB::bind_method(D_METHOD("get_prop", "seed"), &WorldGeneratorPropData::get_prop);
}
