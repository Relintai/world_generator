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

#include "dungeon_corridor_data.h"

int DungeonCorridorData::get_max_connections() {
	return _max_connections;
}
void DungeonCorridorData::set_max_connections(int value) {
	_max_connections = value;
}

Ref<DungeonCorridor> DungeonCorridorData::setup_corridor(int seed) {
	if (has_method("_setup_corridor")) {
		return call("_setup_corridor", seed);
	}

	return Ref<DungeonCorridor>();
}

DungeonCorridorData::DungeonCorridorData() {
	_max_connections = 2;
}
DungeonCorridorData::~DungeonCorridorData() {
}

void DungeonCorridorData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "corridor", PROPERTY_HINT_RESOURCE_TYPE, "DungeonCorridor"), "_setup_corridor", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_corridor", "seed"), &DungeonCorridorData::setup_corridor);

	ClassDB::bind_method(D_METHOD("get_max_connections"), &DungeonCorridorData::get_max_connections);
	ClassDB::bind_method(D_METHOD("set_max_connections", "value"), &DungeonCorridorData::set_max_connections);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_connections"), "set_max_connections", "get_max_connections");
}
