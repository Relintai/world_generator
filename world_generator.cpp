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

#include "world_generator.h"

#include "core/version.h"

Ref<Planet> WorldGenerator::get_planet_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _planet_datas.size(), Ref<Planet>());

	return _planet_datas.get(index);
}
void WorldGenerator::set_planet_data(const int index, const Ref<Planet> planet_data) {
	ERR_FAIL_INDEX(index, _planet_datas.size());

	_planet_datas.set(index, planet_data);
}
void WorldGenerator::add_planet_data(const Ref<Planet> planet_data) {
	_planet_datas.push_back(planet_data);
}
void WorldGenerator::remove_planet_data(const int index) {
	ERR_FAIL_INDEX(index, _planet_datas.size());

	_planet_datas.remove(index);
}

int WorldGenerator::get_planet_data_count() const {
	return _planet_datas.size();
}

Vector<Variant> WorldGenerator::get_planet_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _planet_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_planet_datas[i].get_ref_ptr());
#else
		r.push_back(_planet_datas[i]);
#endif
	}
	return r;
}
void WorldGenerator::set_planet_datas(const Vector<Variant> &planet_datas) {
	_planet_datas.clear();
	for (int i = 0; i < planet_datas.size(); i++) {
		Ref<Planet> planet_data = Ref<Planet>(planet_datas[i]);

		_planet_datas.push_back(planet_data);
	}
}

Ref<Planet> WorldGenerator::setup_planet(int seed) {
	if (has_method("_setup_planet")) {
		return call("_setup_planet");
	}

	return Ref<Planet>(NULL);
}

WorldGenerator::WorldGenerator() {
}
WorldGenerator::~WorldGenerator() {
	_planet_datas.clear();
}

void WorldGenerator::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "planet", PROPERTY_HINT_RESOURCE_TYPE, "Planet"), "_setup_planet", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_planet", "seed"), &WorldGenerator::setup_planet);

	ClassDB::bind_method(D_METHOD("get_planet_data", "index"), &WorldGenerator::get_planet_data);
	ClassDB::bind_method(D_METHOD("set_planet_data", "index", "data"), &WorldGenerator::set_planet_data);
	ClassDB::bind_method(D_METHOD("add_planet_data", "planet_data"), &WorldGenerator::add_planet_data);
	ClassDB::bind_method(D_METHOD("remove_planet_data", "index"), &WorldGenerator::remove_planet_data);

	ClassDB::bind_method(D_METHOD("get_planet_data_count"), &WorldGenerator::get_planet_data_count);

	ClassDB::bind_method(D_METHOD("get_planet_datas"), &WorldGenerator::get_planet_datas);
	ClassDB::bind_method(D_METHOD("set_planet_datas", "planet_datas"), &WorldGenerator::set_planet_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "planet_datas", PROPERTY_HINT_NONE, "17/17:Planet", PROPERTY_USAGE_DEFAULT, "Planet"), "set_planet_datas", "get_planet_datas");
}
