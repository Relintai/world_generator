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

#ifdef VOXELMAN_PRESENT
Ref<EnvironmentData> Biome::get_environment() {
	return _environment;
}
void Biome::set_environment(Ref<EnvironmentData> value) {
	_environment = value;
}
#endif

Ref<BiomeData> Biome::get_data() {
	return _data;
}
void Biome::set_data(Ref<BiomeData> value) {
	_data = value;

	setup();
}

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

void Biome::setup() {
	if (!_data.is_valid())
		return;

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
	if (!_data.is_valid())
		return;

	if (has_method("_setup_library")) {
		call("_setup_library", library);
	}
}

void Biome::_setup_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < _data->get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = _data->get_voxel_surface(i);

		if (s.is_valid()) {
			library->add_voxel_surface(s);
		}
	}

#ifdef PROPS_PRESENT
	for (int i = 0; i < _data->get_prop_data_count(); ++i) {
		Ref<WorldGeneratorPropData> s = _data->get_prop_data(i);

		if (s.is_valid()) {
			Ref<PackedScene> pd = s->get_prop();

			if (pd.is_valid())
				library->add_prop(s->get_prop());
		}
	}
#endif
}
#else
void Biome::setup_library(Ref<Resource> library) {
	if (!_data.is_valid())
		return;

	if (has_method("_setup_library")) {
		call("_setup_library", library);
	}
}

void Biome::generate_chunk(Ref<Resource> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk, spawn_mobs);
	}
}
#endif

Biome::Biome() {
	_current_seed = 0;
}
Biome::~Biome() {
#ifdef VOXELMAN_PRESENT
	_environment.unref();
#endif

	_data.unref();
	_prop_datas.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

	_dungeons.clear();
}

void Biome::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_setup"));

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_stack", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::INT, "x"), PropertyInfo(Variant::INT, "z"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#else
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "Resource")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "Resource"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#endif

	ClassDB::bind_method(D_METHOD("setup"), &Biome::setup);
	ClassDB::bind_method(D_METHOD("setup_library", "library"), &Biome::setup_library);

#ifdef VOXELMAN_PRESENT
	ClassDB::bind_method(D_METHOD("_setup_library", "library"), &Biome::_setup_library);

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk", "spawn_mobs"), &Biome::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_stack", "chunk", "x", "z", "spawn_mobs"), &Biome::generate_stack);
#else
	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk", "spawn_mobs"), &Biome::generate_chunk);
#endif

	ClassDB::bind_method(D_METHOD("get_current_seed"), &Biome::get_current_seed);
	ClassDB::bind_method(D_METHOD("set_current_seed", "value"), &Biome::set_current_seed);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "current_seed"), "set_current_seed", "get_current_seed");

	ClassDB::bind_method(D_METHOD("get_level_range"), &Biome::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &Biome::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

#ifdef VOXELMAN_PRESENT
	ClassDB::bind_method(D_METHOD("get_environment"), &Biome::get_environment);
	ClassDB::bind_method(D_METHOD("set_environment", "value"), &Biome::set_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_environment", "get_environment");
#endif

	ClassDB::bind_method(D_METHOD("get_data"), &Biome::get_data);
	ClassDB::bind_method(D_METHOD("set_data", "value"), &Biome::set_data);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data", PROPERTY_HINT_RESOURCE_TYPE, "BiomeData"), "set_data", "get_data");

	//Props
	ClassDB::bind_method(D_METHOD("get_prop_data", "index"), &Biome::get_prop_data);
	ClassDB::bind_method(D_METHOD("set_prop_data", "index", "data"), &Biome::set_prop_data);
	ClassDB::bind_method(D_METHOD("add_prop_data", "prop_data"), &Biome::add_prop_data);
	ClassDB::bind_method(D_METHOD("remove_prop_data", "index"), &Biome::remove_prop_data);
	ClassDB::bind_method(D_METHOD("get_prop_data_count"), &Biome::get_prop_data_count);

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &Biome::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &Biome::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &Biome::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &Biome::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &Biome::get_entity_data_count);
#endif

	//Dungeons
	ClassDB::bind_method(D_METHOD("get_dungeon", "index"), &Biome::get_dungeon);
	ClassDB::bind_method(D_METHOD("set_dungeon", "index", "data"), &Biome::set_dungeon);
	ClassDB::bind_method(D_METHOD("add_dungeon", "dungeon"), &Biome::add_dungeon);
	ClassDB::bind_method(D_METHOD("remove_dungeon", "index"), &Biome::remove_dungeon);
	ClassDB::bind_method(D_METHOD("get_dungeon_count"), &Biome::get_dungeon_count);
}
