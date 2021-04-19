/*
Copyright (c) 2019-2021 Péter Magyar

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

#include "building.h"

int Building::get_current_seed() {
	return _current_seed;
}
void Building::set_current_seed(int value) {
	_current_seed = value;
}

Vector2 Building::get_level_range() {
	return _level_range;
}
void Building::set_level_range(Vector2 value) {
	_level_range = value;
}

//Position
int Building::get_posx() {
	return _posx;
}
void Building::set_posx(int value) {
	_posx = value;
}

int Building::get_posy() {
	return _posy;
}
void Building::set_posy(int value) {
	_posy = value;
}

int Building::get_posz() {
	return _posz;
}
void Building::set_posz(int value) {
	_posz = value;
}

//Size
int Building::get_sizex() {
	return _sizex;
}
void Building::set_sizex(int value) {
	_sizex = value;
}

int Building::get_sizey() {
	return _sizey;
}
void Building::set_sizey(int value) {
	_sizey = value;
}

int Building::get_sizez() {
	return _sizez;
}
void Building::set_sizez(int value) {
	_sizez = value;
}

Ref<Building> Building::instance(const int seed) {
	Ref<Building> inst;

	inst = Ref<Building>(Object::cast_to<Building>(ClassDB::instance(get_class_name())));
	ERR_FAIL_COND_V(!inst.is_valid(), inst);

	if (!get_script().is_null())
		inst->set_script(get_script());

	return call("_instance", seed, inst);
}

Ref<Building> Building::_instance(const int seed, Ref<Building> inst) {
	inst->set_current_seed(seed);
	inst->set_level_range(_level_range);

	inst->set_posx(_posx);
	inst->set_posy(_posy);
	inst->set_posz(_posz);

	inst->set_sizex(_sizex);
	inst->set_sizey(_sizey);
	inst->set_sizez(_sizez);

#ifdef ESS_PRESENT
	for (int i = 0; i < _entity_datas.size(); ++i) {
		Ref<EntityData> d = _entity_datas[i];

		inst->add_entity_data(d);
	}
#endif

#ifdef VOXELMAN_PRESENT
	inst->set_voxel_environment(_voxel_environment);

	for (int i = 0; i < _voxel_environment_datas.size(); ++i) {
		Ref<EnvironmentData> d = _voxel_environment_datas[i];

		if (!d.is_valid())
			continue;

		inst->add_voxel_environment_data(d);
	}

	for (int i = 0; i < _voxel_surfaces.size(); ++i) {
		Ref<VoxelSurface> d = _voxel_surfaces[i];

		if (!d.is_valid())
			continue;

		inst->add_voxel_surface(d);
	}
#endif

#ifdef TERRAMAN_PRESENT
	inst->set_terra_environment(_terra_environment);

	for (int i = 0; i < _terra_environment_datas.size(); ++i) {
		Ref<TerraEnvironmentData> d = _terra_environment_datas[i];

		if (!d.is_valid())
			continue;

		inst->add_terra_environment_data(d);
	}

	for (int i = 0; i < _terra_surfaces.size(); ++i) {
		Ref<TerraSurface> d = _terra_surfaces[i];

		if (!d.is_valid())
			continue;

		inst->add_terra_surface(d);
	}
#endif

	return inst;
}

void Building::setup() {
	if (has_method("_setup")) {
		call("_setup");
	}
}

#ifdef ESS_PRESENT
//Entities
Ref<EntityData> Building::get_entity_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _entity_datas.size(), Ref<EntityData>());

	return _entity_datas.get(index);
}
void Building::set_entity_data(const int index, const Ref<EntityData> entity_data) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.set(index, entity_data);
}
void Building::add_entity_data(const Ref<EntityData> entity_data) {
	_entity_datas.push_back(entity_data);
}
void Building::remove_entity_data(const int index) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.remove(index);
}
int Building::get_entity_data_count() const {
	return _entity_datas.size();
}

Vector<Variant> Building::get_entity_datas() {
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
void Building::set_entity_datas(const Vector<Variant> &entity_datas) {
	_entity_datas.clear();
	for (int i = 0; i < entity_datas.size(); i++) {
		Ref<EntityData> entity_data = Ref<EntityData>(entity_datas[i]);

		_entity_datas.push_back(entity_data);
	}
}
#endif

#ifdef VOXELMAN_PRESENT
Ref<EnvironmentData> Building::get_voxel_environment() {
	return _voxel_environment;
}
void Building::set_voxel_environment(Ref<EnvironmentData> value) {
	_voxel_environment = value;
}

////    Surfaces    ////
Ref<VoxelSurface> Building::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void Building::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void Building::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void Building::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int Building::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> Building::get_voxel_surfaces() {
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
void Building::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<VoxelSurface> voxel_surface = Ref<VoxelSurface>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

//Environments
Ref<EnvironmentData> Building::get_voxel_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_environment_datas.size(), Ref<EnvironmentData>());

	return _voxel_environment_datas.get(index);
}
void Building::set_voxel_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _voxel_environment_datas.size());

	_voxel_environment_datas.set(index, environment_data);
}
void Building::add_voxel_environment_data(const Ref<EnvironmentData> environment_data) {
	_voxel_environment_datas.push_back(environment_data);
}
void Building::remove_voxel_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _voxel_environment_datas.size());

	_voxel_environment_datas.remove(index);
}
int Building::get_voxel_environment_data_count() const {
	return _voxel_environment_datas.size();
}

Vector<Variant> Building::get_voxel_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _voxel_environment_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_voxel_environment_datas[i].get_ref_ptr());
#else
		r.push_back(_voxel_environment_datas[i]);
#endif
	}
	return r;
}
void Building::set_voxel_environment_datas(const Vector<Variant> &environment_datas) {
	_voxel_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_voxel_environment_datas.push_back(environment_data);
	}
}

void Building::setup_voxel_library(Ref<VoxelmanLibrary> library) {
	if (has_method("_setup_voxel_library")) {
		call("_setup_voxel_library", library);
	}
}

void Building::_setup_voxel_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = get_voxel_surface(i);

		if (s.is_valid()) {
			library->voxel_surface_add(s);
		}
	}
}

void Building::generate_voxel_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_voxel_chunk")) {
		call("_generate_voxel_chunk", chunk, spawn_mobs);
	}
}

void Building::generate_voxel_structure(Ref<VoxelStructure> structure, bool spawn_mobs) {
	if (has_method("_generate_voxel_structure")) {
		call("_generate_voxel_structure", structure, spawn_mobs);
	}
}
#endif

#ifdef TERRAMAN_PRESENT
Ref<TerraEnvironmentData> Building::get_terra_environment() {
	return _terra_environment;
}
void Building::set_terra_environment(Ref<TerraEnvironmentData> value) {
	_terra_environment = value;
}

////    Surfaces    ////
Ref<TerraSurface> Building::get_terra_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _terra_surfaces.size(), Ref<TerraSurface>());

	return _terra_surfaces.get(index);
}
void Building::set_terra_surface(const int index, const Ref<TerraSurface> terra_surface) {
	ERR_FAIL_INDEX(index, _terra_surfaces.size());

	_terra_surfaces.set(index, terra_surface);
}
void Building::add_terra_surface(const Ref<TerraSurface> terra_surface) {
	_terra_surfaces.push_back(terra_surface);
}
void Building::remove_terra_surface(const int index) {
	ERR_FAIL_INDEX(index, _terra_surfaces.size());

	_terra_surfaces.remove(index);
}
int Building::get_terra_surface_count() const {
	return _terra_surfaces.size();
}

Vector<Variant> Building::get_terra_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _terra_surfaces.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_terra_surfaces[i].get_ref_ptr());
#else
		r.push_back(_terra_surfaces[i]);
#endif
	}
	return r;
}
void Building::set_terra_surfaces(const Vector<Variant> &terra_surfaces) {
	_terra_surfaces.clear();
	for (int i = 0; i < terra_surfaces.size(); i++) {
		Ref<TerraSurface> terra_surface = Ref<TerraSurface>(terra_surfaces[i]);

		_terra_surfaces.push_back(terra_surface);
	}
}

//Environments
Ref<TerraEnvironmentData> Building::get_terra_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _terra_environment_datas.size(), Ref<TerraEnvironmentData>());

	return _terra_environment_datas.get(index);
}
void Building::set_terra_environment_data(const int index, const Ref<TerraEnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _terra_environment_datas.size());

	_terra_environment_datas.set(index, environment_data);
}
void Building::add_terra_environment_data(const Ref<TerraEnvironmentData> environment_data) {
	_terra_environment_datas.push_back(environment_data);
}
void Building::remove_terra_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _terra_environment_datas.size());

	_terra_environment_datas.remove(index);
}
int Building::get_terra_environment_data_count() const {
	return _terra_environment_datas.size();
}

Vector<Variant> Building::get_terra_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _terra_environment_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_terra_environment_datas[i].get_ref_ptr());
#else
		r.push_back(_terra_environment_datas[i]);
#endif
	}
	return r;
}
void Building::set_terra_environment_datas(const Vector<Variant> &environment_datas) {
	_terra_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<TerraEnvironmentData> environment_data = Ref<TerraEnvironmentData>(environment_datas[i]);

		_terra_environment_datas.push_back(environment_data);
	}
}

void Building::setup_terra_library(Ref<TerramanLibrary> library) {
	if (has_method("_setup_terra_library")) {
		call("_setup_terra_library", library);
	}
}

void Building::_setup_terra_library(Ref<TerramanLibrary> library) {
	for (int i = 0; i < get_terra_surface_count(); ++i) {
		Ref<TerraSurface> s = get_terra_surface(i);

		if (s.is_valid()) {
			library->voxel_surface_add(s);
		}
	}
}

void Building::generate_terra_chunk(Ref<TerraChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_terra_chunk")) {
		call("_generate_terra_chunk", chunk, spawn_mobs);
	}
}

void Building::generate_terra_structure(Ref<TerraStructure> structure, bool spawn_mobs) {
	if (has_method("_generate_terra_structure")) {
		call("_generate_terra_structure", structure, spawn_mobs);
	}
}
#endif

Ref<Image> Building::generate_map() {
	ERR_FAIL_COND_V(!has_method("_generate_map"), Ref<Image>());

	return call("_generate_map");
}

Building::Building() {
	_current_seed = 0;

	_posx = 0;
	_posy = 0;
	_posz = 0;

	_sizex = 0;
	_sizey = 0;
	_sizez = 0;
}
Building::~Building() {
#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

#ifdef VOXELMAN_PRESENT
	_voxel_environment.unref();

	_voxel_environment_datas.clear();
	_voxel_surfaces.clear();
#endif

#ifdef TERRAMAN_PRESENT
	_terra_environment.unref();

	_terra_environment_datas.clear();
	_terra_surfaces.clear();
#endif
}

void Building::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "inst", PROPERTY_HINT_RESOURCE_TYPE, "Building"),
			"_instance",
			PropertyInfo(Variant::INT, "p_seed"),
			PropertyInfo(Variant::OBJECT, "p_instance", PROPERTY_HINT_RESOURCE_TYPE, "Building")));

	BIND_VMETHOD(MethodInfo("_setup"));

	ClassDB::bind_method(D_METHOD("instance", "seed"), &Building::instance);
	ClassDB::bind_method(D_METHOD("_instance", "p_seed", "p_instance"), &Building::_instance);

	ClassDB::bind_method(D_METHOD("setup"), &Building::setup);

	ClassDB::bind_method(D_METHOD("get_current_seed"), &Building::get_current_seed);
	ClassDB::bind_method(D_METHOD("set_current_seed", "value"), &Building::set_current_seed);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "current_seed"), "set_current_seed", "get_current_seed");

	ClassDB::bind_method(D_METHOD("get_level_range"), &Building::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &Building::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

	//Position
	ClassDB::bind_method(D_METHOD("get_posx"), &Building::get_posx);
	ClassDB::bind_method(D_METHOD("set_posx", "value"), &Building::set_posx);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posx"), "set_posx", "get_posx");

	ClassDB::bind_method(D_METHOD("get_posy"), &Building::get_posy);
	ClassDB::bind_method(D_METHOD("set_posy", "value"), &Building::set_posy);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posy"), "set_posy", "get_posy");

	ClassDB::bind_method(D_METHOD("get_posz"), &Building::get_posz);
	ClassDB::bind_method(D_METHOD("set_posz", "value"), &Building::set_posz);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posz"), "set_posz", "get_posz");

	//Size
	ClassDB::bind_method(D_METHOD("get_sizex"), &Building::get_sizex);
	ClassDB::bind_method(D_METHOD("set_sizex", "value"), &Building::set_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizex"), "set_sizex", "get_sizex");

	ClassDB::bind_method(D_METHOD("get_sizey"), &Building::get_sizey);
	ClassDB::bind_method(D_METHOD("set_sizey", "value"), &Building::set_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizey"), "set_sizey", "get_sizey");

	ClassDB::bind_method(D_METHOD("get_sizez"), &Building::get_sizez);
	ClassDB::bind_method(D_METHOD("set_sizez", "value"), &Building::set_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizez"), "set_sizez", "get_sizez");

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &Building::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &Building::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &Building::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &Building::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &Building::get_entity_data_count);

	ClassDB::bind_method(D_METHOD("get_entity_datas"), &Building::get_entity_datas);
	ClassDB::bind_method(D_METHOD("set_entity_datas", "entity_datas"), &Building::set_entity_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "entity_datas", PROPERTY_HINT_NONE, "17/17:EntityData", PROPERTY_USAGE_DEFAULT, "EntityData"), "set_entity_datas", "get_entity_datas");
#endif

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_voxel_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_voxel_structure", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_voxel_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));

	ClassDB::bind_method(D_METHOD("setup_voxel_library", "library"), &Building::setup_voxel_library);
	ClassDB::bind_method(D_METHOD("_setup_voxel_library", "library"), &Building::_setup_voxel_library);

	ClassDB::bind_method(D_METHOD("generate_voxel_chunk", "chunk", "spawn_mobs"), &Building::generate_voxel_chunk);
	ClassDB::bind_method(D_METHOD("generate_voxel_structure", "structure", "spawn_mobs"), &Building::generate_voxel_structure);

	//Environment
	ClassDB::bind_method(D_METHOD("get_voxel_environment"), &Building::get_voxel_environment);
	ClassDB::bind_method(D_METHOD("set_voxel_environment", "value"), &Building::set_voxel_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "voxel_environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_voxel_environment", "get_voxel_environment");

	//Environments
	ClassDB::bind_method(D_METHOD("get_voxel_environment_data", "index"), &Building::get_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("set_voxel_environment_data", "index", "data"), &Building::set_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("add_voxel_environment_data", "environment_data"), &Building::add_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("remove_voxel_environment_data", "index"), &Building::remove_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("get_voxel_environment_data_count"), &Building::get_voxel_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_voxel_environment_datas"), &Building::get_voxel_environment_datas);
	ClassDB::bind_method(D_METHOD("set_voxel_environment_datas", "environment_datas"), &Building::set_voxel_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_voxel_environment_datas", "get_voxel_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &Building::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &Building::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &Building::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &Building::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &Building::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &Building::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &Building::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");
#endif

#ifdef TERRAMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_terra_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "TerramanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_terra_structure", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "TerraStructure"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_terra_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "TerraChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));

	ClassDB::bind_method(D_METHOD("setup_terra_library", "library"), &Building::setup_terra_library);
	ClassDB::bind_method(D_METHOD("_setup_terra_library", "library"), &Building::_setup_terra_library);

	ClassDB::bind_method(D_METHOD("generate_terra_chunk", "chunk", "spawn_mobs"), &Building::generate_terra_chunk);
	ClassDB::bind_method(D_METHOD("generate_terra_structure", "structure", "spawn_mobs"), &Building::generate_terra_structure);

	//Environment
	ClassDB::bind_method(D_METHOD("get_terra_environment"), &Building::get_terra_environment);
	ClassDB::bind_method(D_METHOD("set_terra_environment", "value"), &Building::set_terra_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "terra_environment", PROPERTY_HINT_RESOURCE_TYPE, "TerraEnvironmentData"), "set_terra_environment", "get_terra_environment");

	//Environments
	ClassDB::bind_method(D_METHOD("get_terra_environment_data", "index"), &Building::get_terra_environment_data);
	ClassDB::bind_method(D_METHOD("set_terra_environment_data", "index", "data"), &Building::set_terra_environment_data);
	ClassDB::bind_method(D_METHOD("add_terra_environment_data", "environment_data"), &Building::add_terra_environment_data);
	ClassDB::bind_method(D_METHOD("remove_terra_environment_data", "index"), &Building::remove_terra_environment_data);
	ClassDB::bind_method(D_METHOD("get_terra_environment_data_count"), &Building::get_terra_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_terra_environment_datas"), &Building::get_terra_environment_datas);
	ClassDB::bind_method(D_METHOD("set_terra_environment_datas", "environment_datas"), &Building::set_terra_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "terra_environment_datas", PROPERTY_HINT_NONE, "17/17:TerraEnvironmentData", PROPERTY_USAGE_DEFAULT, "TerraEnvironmentData"), "set_terra_environment_datas", "get_terra_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_terra_surface", "index"), &Building::get_terra_surface);
	ClassDB::bind_method(D_METHOD("set_terra_surface", "index", "data"), &Building::set_terra_surface);
	ClassDB::bind_method(D_METHOD("add_terra_surface", "terra_surface"), &Building::add_terra_surface);
	ClassDB::bind_method(D_METHOD("remove_terra_surface", "index"), &Building::remove_terra_surface);
	ClassDB::bind_method(D_METHOD("get_terra_surface_count"), &Building::get_terra_surface_count);

	ClassDB::bind_method(D_METHOD("get_terra_surfaces"), &Building::get_terra_surfaces);
	ClassDB::bind_method(D_METHOD("set_terra_surfaces", "terra_surfaces"), &Building::set_terra_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "terra_surfaces", PROPERTY_HINT_NONE, "17/17:TerraSurface", PROPERTY_USAGE_DEFAULT, "TerraSurface"), "set_terra_surfaces", "get_terra_surfaces");
#endif

	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "image", PROPERTY_HINT_RESOURCE_TYPE, "Image"), "_generate_map"));

	ClassDB::bind_method(D_METHOD("generate_map"), &Building::generate_map);
}
