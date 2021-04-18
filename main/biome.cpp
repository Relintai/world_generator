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

#include "biome.h"

int Biome::get_current_seed() {
	return _current_seed;
}
void Biome::set_current_seed(int value) {
	_current_seed = value;
}

Vector2 Biome::get_level_range() {
	return _level_range;
}
void Biome::set_level_range(Vector2 value) {
	_level_range = value;
}

Vector2 Biome::get_humidity_range() {
	return _humidity_range;
}
void Biome::set_humidity_range(Vector2 range) {
	_humidity_range = range;
}

Vector2 Biome::get_temperature_range() {
	return _temperature_range;
}
void Biome::set_temperature_range(Vector2 range) {
	_temperature_range = range;
}

#ifdef VOXELMAN_PRESENT
Ref<EnvironmentData> Biome::get_environment() {
	return _environment;
}
void Biome::set_environment(Ref<EnvironmentData> value) {
	_environment = value;
}
#endif

////    Prop Data    ////
Ref<WorldGeneratorPropData> Biome::get_prop_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _prop_datas.size(), Ref<WorldGeneratorPropData>());

	return _prop_datas.get(index);
}
void Biome::set_prop_data(const int index, const Ref<WorldGeneratorPropData> prop_data) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.set(index, prop_data);
}
void Biome::add_prop_data(const Ref<WorldGeneratorPropData> prop_data) {
	_prop_datas.push_back(prop_data);
}
void Biome::remove_prop_data(const int index) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.remove(index);
}

int Biome::get_prop_data_count() const {
	return _prop_datas.size();
}

Vector<Variant> Biome::get_prop_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _prop_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_prop_datas[i].get_ref_ptr());
#else
		r.push_back(_prop_datas[i]);
#endif
	}
	return r;
}
void Biome::set_prop_datas(const Vector<Variant> &prop_datas) {
	_prop_datas.clear();
	for (int i = 0; i < prop_datas.size(); i++) {
		Ref<WorldGeneratorPropData> prop_data = Ref<WorldGeneratorPropData>(prop_datas[i]);

		_prop_datas.push_back(prop_data);
	}
}

#ifdef ESS_PRESENT
//Entities
Ref<EntityData> Biome::get_entity_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _entity_datas.size(), Ref<EntityData>());

	return _entity_datas.get(index);
}
void Biome::set_entity_data(const int index, const Ref<EntityData> entity_data) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.set(index, entity_data);
}
void Biome::add_entity_data(const Ref<EntityData> entity_data) {
	_entity_datas.push_back(entity_data);
}
void Biome::remove_entity_data(const int index) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.remove(index);
}
int Biome::get_entity_data_count() const {
	return _entity_datas.size();
}

Vector<Variant> Biome::get_entity_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _entity_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_entity_datas[i].get_ref_ptr());
#else
		r.push_back(_entity_datas[i]);
#endif
	}
	return r;
}
void Biome::set_entity_datas(const Vector<Variant> &entity_datas) {
	_entity_datas.clear();
	for (int i = 0; i < entity_datas.size(); i++) {
		Ref<EntityData> entity_data = Ref<EntityData>(entity_datas[i]);

		_entity_datas.push_back(entity_data);
	}
}
#endif

////    Dungeons    ////
Ref<Dungeon> Biome::get_dungeon(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeons.size(), Ref<Dungeon>());

	return _dungeons.get(index);
}
void Biome::set_dungeon(const int index, const Ref<Dungeon> dungeon) {
	ERR_FAIL_INDEX(index, _dungeons.size());

	_dungeons.set(index, dungeon);
}
void Biome::add_dungeon(const Ref<Dungeon> dungeon) {
	_dungeons.push_back(dungeon);
}
void Biome::remove_dungeon(const int index) {
	ERR_FAIL_INDEX(index, _dungeons.size());

	_dungeons.remove(index);
}
int Biome::get_dungeon_count() const {
	return _dungeons.size();
}

Vector<Variant> Biome::get_dungeons() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeons.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeons[i].get_ref_ptr());
#else
		r.push_back(_dungeons[i]);
#endif
	}
	return r;
}
void Biome::set_dungeons(const Vector<Variant> &dungeon_datas) {
	_dungeons.clear();
	for (int i = 0; i < dungeon_datas.size(); i++) {
		Ref<Dungeon> dungeon_data = Ref<Dungeon>(dungeon_datas[i]);

		_dungeons.push_back(dungeon_data);
	}
}

#ifdef VOXELMAN_PRESENT
//Environments
Ref<EnvironmentData> Biome::get_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _environment_datas.size(), Ref<EnvironmentData>());

	return _environment_datas.get(index);
}
void Biome::set_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.set(index, environment_data);
}
void Biome::add_environment_data(const Ref<EnvironmentData> environment_data) {
	_environment_datas.push_back(environment_data);
}
void Biome::remove_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.remove(index);
}
int Biome::get_environment_data_count() const {
	return _environment_datas.size();
}

Vector<Variant> Biome::get_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _environment_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_environment_datas[i].get_ref_ptr());
#else
		r.push_back(_environment_datas[i]);
#endif
	}
	return r;
}
void Biome::set_environment_datas(const Vector<Variant> &environment_datas) {
	_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_environment_datas.push_back(environment_data);
	}
}

////    Surfaces    ////
Ref<VoxelSurface> Biome::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void Biome::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void Biome::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void Biome::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int Biome::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> Biome::get_voxel_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _voxel_surfaces.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_voxel_surfaces[i].get_ref_ptr());
#else
		r.push_back(_voxel_surfaces[i]);
#endif
	}
	return r;
}
void Biome::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<EnvironmentData> voxel_surface = Ref<EnvironmentData>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

#endif

Ref<Biome> Biome::instance(const int seed) {
	Ref<Biome> inst;

	inst = Ref<Biome>(Object::cast_to<Biome>(ClassDB::instance(get_class_name())));
	ERR_FAIL_COND_V(!inst.is_valid(), inst);

	if (!get_script().is_null())
		inst->set_script(get_script());

	return call("_instance", seed, inst);
}

Ref<Biome> Biome::_instance(const int seed, Ref<Biome> inst) {
	inst->set_current_seed(seed);
	inst->set_level_range(_level_range);

	inst->set_humidity_range(_humidity_range);
	inst->set_temperature_range(_temperature_range);

#ifdef VOXELMAN_PRESENT
	inst->set_environment(_environment);
#endif

	for (int i = 0; i < _prop_datas.size(); ++i) {
		Ref<WorldGeneratorPropData> p = _prop_datas[i];

		inst->add_prop_data(p);
	}

	for (int i = 0; i < _dungeons.size(); ++i) {
		Ref<Dungeon> d = _dungeons[i];

		if (!d.is_valid())
			continue;

		inst->add_dungeon(d->instance(seed));
	}

#ifdef ESS_PRESENT
	for (int i = 0; i < _entity_datas.size(); ++i) {
		Ref<EntityData> d = _entity_datas[i];

		inst->add_entity_data(d);
	}
#endif

#ifdef VOXELMAN_PRESENT
	for (int i = 0; i < _environment_datas.size(); ++i) {
		Ref<EnvironmentData> d = _environment_datas[i];

		if (!d.is_valid())
			continue;

		inst->add_environment_data(d);
	}

	for (int i = 0; i < _voxel_surfaces.size(); ++i) {
		Ref<VoxelSurface> d = _voxel_surfaces[i];

		if (!d.is_valid())
			continue;

		inst->add_voxel_surface(d);
	}
#endif

	return inst;
}

void Biome::setup() {
	if (has_method("_setup")) {
		call("_setup");
	}
}

#ifdef VOXELMAN_PRESENT
void Biome::generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk, spawn_mobs);
	}
}
void Biome::generate_stack(Ref<VoxelChunk> chunk, int x, int z, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_stack")) {
		call("_generate_stack", chunk, x, z, spawn_mobs);
	}
}

void Biome::setup_library(Ref<VoxelmanLibrary> library) {
	ERR_FAIL_COND(!library.is_valid());

	if (has_method("_setup_library")) {
		call("_setup_library", library);
	}
}

void Biome::_setup_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = get_voxel_surface(i);

		if (s.is_valid()) {
			library->voxel_surface_add(s);
		}
	}

	for (int i = 0; i < get_dungeon_count(); ++i) {
		Ref<Dungeon> d = get_dungeon(i);

		if (d.is_valid()) {
			d->setup_library(library);
		}
	}

#ifdef PROPS_PRESENT
	for (int i = 0; i < get_prop_data_count(); ++i) {
		Ref<WorldGeneratorPropData> s = get_prop_data(i);

		if (s.is_valid()) {
			Ref<PackedScene> pd = s->get_prop();

			if (pd.is_valid())
				library->prop_add(s->get_prop());
		}
	}
#endif
}
#endif

Biome::Biome() {
	_current_seed = 0;
}
Biome::~Biome() {
#ifdef VOXELMAN_PRESENT
	_environment.unref();
#endif

	_prop_datas.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

	_dungeons.clear();

	_prop_datas.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

#ifdef VOXELMAN_PRESENT
	_environment_datas.clear();
	_voxel_surfaces.clear();
#endif
}

void Biome::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "inst", PROPERTY_HINT_RESOURCE_TYPE, "Biome"),
			"_instance",
			PropertyInfo(Variant::INT, "p_seed"),
			PropertyInfo(Variant::OBJECT, "p_instance", PROPERTY_HINT_RESOURCE_TYPE, "Biome")));

	BIND_VMETHOD(MethodInfo("_setup"));

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_stack", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::INT, "x"), PropertyInfo(Variant::INT, "z"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#endif

	ClassDB::bind_method(D_METHOD("instance", "seed"), &Biome::instance);
	ClassDB::bind_method(D_METHOD("_instance", "p_seed", "p_instance"), &Biome::_instance);

	ClassDB::bind_method(D_METHOD("setup"), &Biome::setup);
	ClassDB::bind_method(D_METHOD("setup_library", "library"), &Biome::setup_library);

#ifdef VOXELMAN_PRESENT
	ClassDB::bind_method(D_METHOD("_setup_library", "library"), &Biome::_setup_library);

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk", "spawn_mobs"), &Biome::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_stack", "chunk", "x", "z", "spawn_mobs"), &Biome::generate_stack);
#endif

	ClassDB::bind_method(D_METHOD("get_current_seed"), &Biome::get_current_seed);
	ClassDB::bind_method(D_METHOD("set_current_seed", "value"), &Biome::set_current_seed);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "current_seed"), "set_current_seed", "get_current_seed");

	ClassDB::bind_method(D_METHOD("get_level_range"), &Biome::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &Biome::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

	ClassDB::bind_method(D_METHOD("get_humidity_range"), &Biome::get_humidity_range);
	ClassDB::bind_method(D_METHOD("set_humidity_range", "value"), &Biome::set_humidity_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "humidity_range"), "set_humidity_range", "get_humidity_range");

	ClassDB::bind_method(D_METHOD("get_temperature_range"), &Biome::get_temperature_range);
	ClassDB::bind_method(D_METHOD("set_temperature_range", "value"), &Biome::set_temperature_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "temperature_range"), "set_temperature_range", "get_temperature_range");

#ifdef VOXELMAN_PRESENT
	ClassDB::bind_method(D_METHOD("get_environment"), &Biome::get_environment);
	ClassDB::bind_method(D_METHOD("set_environment", "value"), &Biome::set_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_environment", "get_environment");
#endif

	//Props
	ClassDB::bind_method(D_METHOD("get_prop_data", "index"), &Biome::get_prop_data);
	ClassDB::bind_method(D_METHOD("set_prop_data", "index", "data"), &Biome::set_prop_data);
	ClassDB::bind_method(D_METHOD("add_prop_data", "prop_data"), &Biome::add_prop_data);
	ClassDB::bind_method(D_METHOD("remove_prop_data", "index"), &Biome::remove_prop_data);
	ClassDB::bind_method(D_METHOD("get_prop_data_count"), &Biome::get_prop_data_count);

	ClassDB::bind_method(D_METHOD("get_prop_datas"), &Biome::get_prop_datas);
	ClassDB::bind_method(D_METHOD("set_prop_datas", "prop_datas"), &Biome::set_prop_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "prop_datas", PROPERTY_HINT_NONE, "17/17:WorldGeneratorPropData", PROPERTY_USAGE_DEFAULT, "WorldGeneratorPropData"), "set_prop_datas", "get_prop_datas");

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &Biome::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &Biome::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &Biome::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &Biome::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &Biome::get_entity_data_count);

	ClassDB::bind_method(D_METHOD("get_entity_datas"), &Biome::get_entity_datas);
	ClassDB::bind_method(D_METHOD("set_entity_datas", "entity_datas"), &Biome::set_entity_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "entity_datas", PROPERTY_HINT_NONE, "17/17:EntityData", PROPERTY_USAGE_DEFAULT, "EntityData"), "set_entity_datas", "get_entity_datas");
#endif

	//Dungeons
	ClassDB::bind_method(D_METHOD("get_dungeon", "index"), &Biome::get_dungeon);
	ClassDB::bind_method(D_METHOD("set_dungeon", "index", "data"), &Biome::set_dungeon);
	ClassDB::bind_method(D_METHOD("add_dungeon", "dungeon"), &Biome::add_dungeon);
	ClassDB::bind_method(D_METHOD("remove_dungeon", "index"), &Biome::remove_dungeon);
	ClassDB::bind_method(D_METHOD("get_dungeon_count"), &Biome::get_dungeon_count);

	ClassDB::bind_method(D_METHOD("get_dungeons"), &Biome::get_dungeons);
	ClassDB::bind_method(D_METHOD("set_dungeons", "dungeon_datas"), &Biome::set_dungeons);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeons", PROPERTY_HINT_NONE, "17/17:Dungeon", PROPERTY_USAGE_DEFAULT, "Dungeon"), "set_dungeons", "get_dungeons");

#ifdef VOXELMAN_PRESENT
	//Environments
	ClassDB::bind_method(D_METHOD("get_environment_data", "index"), &Biome::get_environment_data);
	ClassDB::bind_method(D_METHOD("set_environment_data", "index", "data"), &Biome::set_environment_data);
	ClassDB::bind_method(D_METHOD("add_environment_data", "environment_data"), &Biome::add_environment_data);
	ClassDB::bind_method(D_METHOD("remove_environment_data", "index"), &Biome::remove_environment_data);
	ClassDB::bind_method(D_METHOD("get_environment_data_count"), &Biome::get_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_environment_datas"), &Biome::get_environment_datas);
	ClassDB::bind_method(D_METHOD("set_environment_datas", "environment_datas"), &Biome::set_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_environment_datas", "get_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &Biome::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &Biome::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &Biome::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &Biome::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &Biome::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &Biome::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &Biome::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");
#endif
}
