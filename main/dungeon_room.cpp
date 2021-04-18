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

#include "dungeon_room.h"

int DungeonRoom::get_current_seed() {
	return _current_seed;
}
void DungeonRoom::set_current_seed(int value) {
	_current_seed = value;
}

Vector2 DungeonRoom::get_level_range() {
	return _level_range;
}
void DungeonRoom::set_level_range(Vector2 value) {
	_level_range = value;
}

//Min Size
int DungeonRoom::get_min_sizex() {
	return _min_sizex;
}
void DungeonRoom::set_min_sizex(int value) {
	_min_sizex = value;
}

int DungeonRoom::get_min_sizey() {
	return _min_sizey;
}
void DungeonRoom::set_min_sizey(int value) {
	_min_sizey = value;
}

int DungeonRoom::get_min_sizez() {
	return _min_sizez;
}
void DungeonRoom::set_min_sizez(int value) {
	_min_sizez = value;
}

//Max Size
int DungeonRoom::get_max_sizex() {
	return _max_sizex;
}
void DungeonRoom::set_max_sizex(int value) {
	_max_sizex = value;
}

int DungeonRoom::get_max_sizey() {
	return _max_sizey;
}
void DungeonRoom::set_max_sizey(int value) {
	_max_sizey = value;
}

int DungeonRoom::get_max_sizez() {
	return _max_sizez;
}
void DungeonRoom::set_max_sizez(int value) {
	_max_sizez = value;
}

//Position
int DungeonRoom::get_posx() {
	return _posx;
}
void DungeonRoom::set_posx(int value) {
	_posx = value;
}

int DungeonRoom::get_posy() {
	return _posy;
}
void DungeonRoom::set_posy(int value) {
	_posy = value;
}

int DungeonRoom::get_posz() {
	return _posz;
}
void DungeonRoom::set_posz(int value) {
	_posz = value;
}

//Size
int DungeonRoom::get_sizex() {
	return _sizex;
}
void DungeonRoom::set_sizex(int value) {
	_sizex = value;
}

int DungeonRoom::get_sizey() {
	return _sizey;
}
void DungeonRoom::set_sizey(int value) {
	_sizey = value;
}

int DungeonRoom::get_sizez() {
	return _sizez;
}
void DungeonRoom::set_sizez(int value) {
	_sizez = value;
}

//Props
Ref<WorldGeneratorPropData> DungeonRoom::get_prop_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _prop_datas.size(), Ref<WorldGeneratorPropData>());

	return _prop_datas.get(index);
}
void DungeonRoom::set_prop_data(const int index, const Ref<WorldGeneratorPropData> prop_data) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.set(index, prop_data);
}
void DungeonRoom::add_prop_data(const Ref<WorldGeneratorPropData> prop_data) {
	_prop_datas.push_back(prop_data);
}
void DungeonRoom::remove_prop_data(const int index) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.remove(index);
}
int DungeonRoom::get_prop_data_count() const {
	return _prop_datas.size();
}

Vector<Variant> DungeonRoom::get_prop_datas() {
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
void DungeonRoom::set_prop_datas(const Vector<Variant> &prop_datas) {
	_prop_datas.clear();
	for (int i = 0; i < prop_datas.size(); i++) {
		Ref<WorldGeneratorPropData> prop_data = Ref<WorldGeneratorPropData>(prop_datas[i]);

		_prop_datas.push_back(prop_data);
	}
}

#ifdef ESS_PRESENT
//Entities
Ref<EntityData> DungeonRoom::get_entity_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _entity_datas.size(), Ref<EntityData>());

	return _entity_datas.get(index);
}
void DungeonRoom::set_entity_data(const int index, const Ref<EntityData> entity_data) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.set(index, entity_data);
}
void DungeonRoom::add_entity_data(const Ref<EntityData> entity_data) {
	_entity_datas.push_back(entity_data);
}
void DungeonRoom::remove_entity_data(const int index) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.remove(index);
}
int DungeonRoom::get_entity_data_count() const {
	return _entity_datas.size();
}

Vector<Variant> DungeonRoom::get_entity_datas() {
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
void DungeonRoom::set_entity_datas(const Vector<Variant> &entity_datas) {
	_entity_datas.clear();
	for (int i = 0; i < entity_datas.size(); i++) {
		Ref<EntityData> entity_data = Ref<EntityData>(entity_datas[i]);

		_entity_datas.push_back(entity_data);
	}
}

#endif

Ref<DungeonRoom> DungeonRoom::instance(const int seed) {
	Ref<DungeonRoom> inst;

	inst = Ref<DungeonRoom>(Object::cast_to<DungeonRoom>(ClassDB::instance(get_class_name())));
	ERR_FAIL_COND_V(!inst.is_valid(), inst);

	if (!get_script().is_null())
		inst->set_script(get_script());

	return call("_instance", seed, inst);
}

Ref<DungeonRoom> DungeonRoom::_instance(const int seed, Ref<DungeonRoom> inst) {
	inst->set_current_seed(seed);
	inst->set_level_range(_level_range);

	inst->set_posx(_posx);
	inst->set_posy(_posy);
	inst->set_posz(_posz);

	inst->set_sizex(_sizex);
	inst->set_sizey(_sizey);
	inst->set_sizez(_sizez);

	inst->set_min_sizex(_min_sizex);
	inst->set_min_sizey(_min_sizey);
	inst->set_min_sizez(_min_sizez);

	inst->set_max_sizex(_max_sizex);
	inst->set_max_sizey(_max_sizey);
	inst->set_max_sizez(_max_sizez);

#ifdef VOXELMAN_PRESENT
	inst->set_voxel_environment(_voxel_environment);
	//don't
	//inst->set_structure(_structure);
#endif

	for (int i = 0; i < _prop_datas.size(); ++i) {
		Ref<WorldGeneratorPropData> p = _prop_datas[i];

		inst->add_prop_data(p);
	}

#ifdef ESS_PRESENT
	for (int i = 0; i < _entity_datas.size(); ++i) {
		Ref<EntityData> d = _entity_datas[i];

		inst->add_entity_data(d);
	}
#endif

#ifdef VOXELMAN_PRESENT
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

	return inst;
}

void DungeonRoom::setup() {
	if (has_method("_setup")) {
		call("_setup");
	}
}

#ifdef VOXELMAN_PRESENT

Ref<EnvironmentData> DungeonRoom::get_voxel_environment() {
	return _voxel_environment;
}
void DungeonRoom::set_voxel_environment(Ref<EnvironmentData> value) {
	_voxel_environment = value;
}

Ref<VoxelStructure> DungeonRoom::get_voxel_structure() {
	return _voxel_structure;
}
void DungeonRoom::set_voxel_structure(Ref<VoxelStructure> structure) {
	_voxel_structure = structure;
}

//Environments
Ref<EnvironmentData> DungeonRoom::get_voxel_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_environment_datas.size(), Ref<EnvironmentData>());

	return _voxel_environment_datas.get(index);
}
void DungeonRoom::set_voxel_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _voxel_environment_datas.size());

	_voxel_environment_datas.set(index, environment_data);
}
void DungeonRoom::add_voxel_environment_data(const Ref<EnvironmentData> environment_data) {
	_voxel_environment_datas.push_back(environment_data);
}
void DungeonRoom::remove_voxel_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _voxel_environment_datas.size());

	_voxel_environment_datas.remove(index);
}
int DungeonRoom::get_voxel_environment_data_count() const {
	return _voxel_environment_datas.size();
}

Vector<Variant> DungeonRoom::get_voxel_environment_datas() {
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
void DungeonRoom::set_voxel_environment_datas(const Vector<Variant> &environment_datas) {
	_voxel_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_voxel_environment_datas.push_back(environment_data);
	}
}

////    Surfaces    ////
Ref<VoxelSurface> DungeonRoom::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void DungeonRoom::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void DungeonRoom::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void DungeonRoom::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int DungeonRoom::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> DungeonRoom::get_voxel_surfaces() {
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
void DungeonRoom::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<EnvironmentData> voxel_surface = Ref<EnvironmentData>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

void DungeonRoom::setup_voxel_library(Ref<VoxelmanLibrary> library) {
	if (has_method("_setup_voxel_library")) {
		call("_setup_voxel_library", library);
	}
}

void DungeonRoom::_setup_voxel_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = get_voxel_surface(i);

		if (s.is_valid()) {
			library->voxel_surface_add(s);
		}
	}

#ifdef PROPS_PRESENT
	for (int i = 0; i < get_prop_data_count(); ++i) {
		Ref<WorldGeneratorPropData> s = get_prop_data(i);

		if (s.is_valid()) {
			Ref<PackedScene> pd = s->get_prop();

			if (pd.is_valid())
				library->prop_add(pd);
		}
	}
#endif
}

void DungeonRoom::generate_voxel_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_voxel_chunk")) {
		call("_generate_voxel_chunk", chunk, spawn_mobs);
	}
}

void DungeonRoom::generate_voxel_room(Ref<VoxelStructure> structure, bool spawn_mobs) {
	if (has_method("_generate_voxel_room")) {
		call("_generate_voxel_room", structure, spawn_mobs);
	}
}
#endif

DungeonRoom::DungeonRoom() {
	_current_seed = 0;

	_min_sizex = 0;
	_min_sizey = 0;
	_min_sizez = 0;

	_max_sizex = 0;
	_max_sizey = 0;
	_max_sizez = 0;

	_posx = 0;
	_posy = 0;
	_posz = 0;

	_sizex = 0;
	_sizey = 0;
	_sizez = 0;
}
DungeonRoom::~DungeonRoom() {
	_prop_datas.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

#ifdef VOXELMAN_PRESENT
	_voxel_environment.unref();
	_voxel_structure.unref();

	_voxel_environment_datas.clear();
	_voxel_surfaces.clear();
#endif
}

void DungeonRoom::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "inst", PROPERTY_HINT_RESOURCE_TYPE, "DungeonRoom"),
			"_instance",
			PropertyInfo(Variant::INT, "p_seed"),
			PropertyInfo(Variant::OBJECT, "p_instance", PROPERTY_HINT_RESOURCE_TYPE, "DungeonRoom")));

	BIND_VMETHOD(MethodInfo("_setup"));

	ClassDB::bind_method(D_METHOD("instance", "seed"), &DungeonRoom::instance);
	ClassDB::bind_method(D_METHOD("_instance", "p_seed", "p_instance"), &DungeonRoom::_instance);

	ClassDB::bind_method(D_METHOD("setup"), &DungeonRoom::setup);

	ClassDB::bind_method(D_METHOD("get_current_seed"), &DungeonRoom::get_current_seed);
	ClassDB::bind_method(D_METHOD("set_current_seed", "value"), &DungeonRoom::set_current_seed);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "current_seed"), "set_current_seed", "get_current_seed");

	ClassDB::bind_method(D_METHOD("get_level_range"), &DungeonRoom::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &DungeonRoom::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

	//Min Size
	ClassDB::bind_method(D_METHOD("get_min_sizex"), &DungeonRoom::get_min_sizex);
	ClassDB::bind_method(D_METHOD("set_min_sizex", "value"), &DungeonRoom::set_min_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_sizex"), "set_min_sizex", "get_min_sizex");

	ClassDB::bind_method(D_METHOD("get_min_sizey"), &DungeonRoom::get_min_sizey);
	ClassDB::bind_method(D_METHOD("set_min_sizey", "value"), &DungeonRoom::set_min_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_sizey"), "set_min_sizey", "get_min_sizey");

	ClassDB::bind_method(D_METHOD("get_min_sizez"), &DungeonRoom::get_min_sizez);
	ClassDB::bind_method(D_METHOD("set_min_sizez", "value"), &DungeonRoom::set_min_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_sizez"), "set_min_sizez", "get_min_sizez");

	//Max Size
	ClassDB::bind_method(D_METHOD("get_max_sizex"), &DungeonRoom::get_max_sizex);
	ClassDB::bind_method(D_METHOD("set_max_sizex", "value"), &DungeonRoom::set_max_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_sizex"), "set_max_sizex", "get_max_sizex");

	ClassDB::bind_method(D_METHOD("get_max_sizey"), &DungeonRoom::get_max_sizey);
	ClassDB::bind_method(D_METHOD("set_max_sizey", "value"), &DungeonRoom::set_max_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_sizey"), "set_max_sizey", "get_max_sizey");

	ClassDB::bind_method(D_METHOD("get_max_sizez"), &DungeonRoom::get_max_sizez);
	ClassDB::bind_method(D_METHOD("set_max_sizez", "value"), &DungeonRoom::set_max_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_sizez"), "set_max_sizez", "get_max_sizez");

	//Position
	ClassDB::bind_method(D_METHOD("get_posx"), &DungeonRoom::get_posx);
	ClassDB::bind_method(D_METHOD("set_posx", "value"), &DungeonRoom::set_posx);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posx"), "set_posx", "get_posx");

	ClassDB::bind_method(D_METHOD("get_posy"), &DungeonRoom::get_posy);
	ClassDB::bind_method(D_METHOD("set_posy", "value"), &DungeonRoom::set_posy);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posy"), "set_posy", "get_posy");

	ClassDB::bind_method(D_METHOD("get_posz"), &DungeonRoom::get_posz);
	ClassDB::bind_method(D_METHOD("set_posz", "value"), &DungeonRoom::set_posz);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posz"), "set_posz", "get_posz");

	//Size
	ClassDB::bind_method(D_METHOD("get_sizex"), &DungeonRoom::get_sizex);
	ClassDB::bind_method(D_METHOD("set_sizex", "value"), &DungeonRoom::set_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizex"), "set_sizex", "get_sizex");

	ClassDB::bind_method(D_METHOD("get_sizey"), &DungeonRoom::get_sizey);
	ClassDB::bind_method(D_METHOD("set_sizey", "value"), &DungeonRoom::set_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizey"), "set_sizey", "get_sizey");

	ClassDB::bind_method(D_METHOD("get_sizez"), &DungeonRoom::get_sizez);
	ClassDB::bind_method(D_METHOD("set_sizez", "value"), &DungeonRoom::set_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizez"), "set_sizez", "get_sizez");

	//Props
	ClassDB::bind_method(D_METHOD("get_prop_data", "index"), &DungeonRoom::get_prop_data);
	ClassDB::bind_method(D_METHOD("set_prop_data", "index", "data"), &DungeonRoom::set_prop_data);
	ClassDB::bind_method(D_METHOD("add_prop_data", "prop_data"), &DungeonRoom::add_prop_data);
	ClassDB::bind_method(D_METHOD("remove_prop_data", "index"), &DungeonRoom::remove_prop_data);
	ClassDB::bind_method(D_METHOD("get_prop_data_count"), &DungeonRoom::get_prop_data_count);

	ClassDB::bind_method(D_METHOD("get_prop_datas"), &DungeonRoom::get_prop_datas);
	ClassDB::bind_method(D_METHOD("set_prop_datas", "prop_datas"), &DungeonRoom::set_prop_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "prop_datas", PROPERTY_HINT_NONE, "17/17:WorldGeneratorPropData", PROPERTY_USAGE_DEFAULT, "WorldGeneratorPropData"), "set_prop_datas", "get_prop_datas");

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &DungeonRoom::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &DungeonRoom::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &DungeonRoom::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &DungeonRoom::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &DungeonRoom::get_entity_data_count);

	ClassDB::bind_method(D_METHOD("get_entity_datas"), &DungeonRoom::get_entity_datas);
	ClassDB::bind_method(D_METHOD("set_entity_datas", "entity_datas"), &DungeonRoom::set_entity_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "entity_datas", PROPERTY_HINT_NONE, "17/17:EntityData", PROPERTY_USAGE_DEFAULT, "EntityData"), "set_entity_datas", "get_entity_datas");
#endif

#ifdef VOXELMAN_PRESENT
	ClassDB::bind_method(D_METHOD("get_voxel_environment"), &DungeonRoom::get_voxel_environment);
	ClassDB::bind_method(D_METHOD("set_voxel_environment", "value"), &DungeonRoom::set_voxel_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "voxel_environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_voxel_environment", "get_voxel_environment");

	ClassDB::bind_method(D_METHOD("get_voxel_structure"), &DungeonRoom::get_voxel_structure);
	ClassDB::bind_method(D_METHOD("set_voxel_structure", "value"), &DungeonRoom::set_voxel_structure);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "voxel_structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure"), "set_voxel_structure", "get_voxel_structure");

	//Environments
	ClassDB::bind_method(D_METHOD("get_voxel_environment_data", "index"), &DungeonRoom::get_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("set_voxel_environment_data", "index", "data"), &DungeonRoom::set_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("add_voxel_environment_data", "environment_data"), &DungeonRoom::add_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("remove_voxel_environment_data", "index"), &DungeonRoom::remove_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("get_voxel_environment_data_count"), &DungeonRoom::get_voxel_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_voxel_environment_datas"), &DungeonRoom::get_voxel_environment_datas);
	ClassDB::bind_method(D_METHOD("set_voxel_environment_datas", "voxel_environment_datas"), &DungeonRoom::set_voxel_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_voxel_environment_datas", "get_voxel_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &DungeonRoom::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &DungeonRoom::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &DungeonRoom::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &DungeonRoom::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &DungeonRoom::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &DungeonRoom::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &DungeonRoom::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");

	BIND_VMETHOD(MethodInfo("_setup_voxel_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_voxel_room", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_voxel_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));

	ClassDB::bind_method(D_METHOD("setup_voxel_library", "library"), &DungeonRoom::setup_voxel_library);
	ClassDB::bind_method(D_METHOD("_setup_voxel_library", "library"), &DungeonRoom::_setup_voxel_library);

	ClassDB::bind_method(D_METHOD("generate_voxel_chunk", "chunk", "spawn_mobs"), &DungeonRoom::generate_voxel_chunk);
	ClassDB::bind_method(D_METHOD("generate_voxel_room", "structure", "spawn_mobs"), &DungeonRoom::generate_voxel_room);
#endif


}
