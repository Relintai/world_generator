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

#include "dungeon.h"

int Dungeon::get_current_seed() {
	return _current_seed;
}
void Dungeon::set_current_seed(int value) {
	_current_seed = value;
}

Vector2 Dungeon::get_level_range() {
	return _level_range;
}
void Dungeon::set_level_range(Vector2 value) {
	_level_range = value;
}

//Min Size
int Dungeon::get_min_sizex() {
	return _min_sizex;
}
void Dungeon::set_min_sizex(int value) {
	_min_sizex = value;
}

int Dungeon::get_min_sizey() {
	return _min_sizey;
}
void Dungeon::set_min_sizey(int value) {
	_min_sizey = value;
}

int Dungeon::get_min_sizez() {
	return _min_sizez;
}
void Dungeon::set_min_sizez(int value) {
	_min_sizez = value;
}

//Max Size
int Dungeon::get_max_sizex() {
	return _max_sizex;
}
void Dungeon::set_max_sizex(int value) {
	_max_sizex = value;
}

int Dungeon::get_max_sizey() {
	return _max_sizey;
}
void Dungeon::set_max_sizey(int value) {
	_max_sizey = value;
}

int Dungeon::get_max_sizez() {
	return _max_sizez;
}
void Dungeon::set_max_sizez(int value) {
	_max_sizez = value;
}

int Dungeon::get_min_room_count() {
	return _min_room_count;
}
void Dungeon::set_min_room_count(int value) {
	_min_room_count = value;
}

int Dungeon::get_max_room_count() {
	return _max_room_count;
}
void Dungeon::set_max_room_count(int value) {
	_max_room_count = value;
}

//Position
int Dungeon::get_posx() {
	return _posx;
}
void Dungeon::set_posx(int value) {
	_posx = value;
}

int Dungeon::get_posy() {
	return _posy;
}
void Dungeon::set_posy(int value) {
	_posy = value;
}

int Dungeon::get_posz() {
	return _posz;
}
void Dungeon::set_posz(int value) {
	_posz = value;
}

//Size
int Dungeon::get_sizex() {
	return _sizex;
}
void Dungeon::set_sizex(int value) {
	_sizex = value;
}

int Dungeon::get_sizey() {
	return _sizey;
}
void Dungeon::set_sizey(int value) {
	_sizey = value;
}

int Dungeon::get_sizez() {
	return _sizez;
}
void Dungeon::set_sizez(int value) {
	_sizez = value;
}

int Dungeon::get_room_count() {
	return _room_count;
}
void Dungeon::set_room_count(int value) {
	_room_count = value;
}

#ifdef VOXELMAN_PRESENT
Ref<EnvironmentData> Dungeon::get_environment() {
	return _environment;
}
void Dungeon::set_environment(Ref<EnvironmentData> value) {
	_environment = value;
}
#endif

//Rooms
Ref<DungeonRoom> Dungeon::get_dungeon_room(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_rooms.size(), Ref<DungeonRoom>());

	return _dungeon_rooms.get(index);
}
void Dungeon::set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.set(index, dungeon_room);
}
void Dungeon::add_dungeon_room(const Ref<DungeonRoom> dungeon_room) {
	_dungeon_rooms.push_back(dungeon_room);
}
void Dungeon::remove_dungeon_room(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.remove(index);
}

int Dungeon::get_dungeon_room_count() const {
	return _dungeon_rooms.size();
}

Vector<Variant> Dungeon::get_dungeon_rooms() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_rooms.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_rooms[i].get_ref_ptr());
#else
		r.push_back(_dungeon_rooms[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_rooms(const Vector<Variant> &dungeon_rooms) {
	_dungeon_rooms.clear();
	for (int i = 0; i < dungeon_rooms.size(); i++) {
		Ref<DungeonRoom> dungeon_room_data = Ref<DungeonRoom>(dungeon_rooms[i]);

		_dungeon_rooms.push_back(dungeon_room_data);
	}
}

//Start Rooms
Ref<DungeonRoom> Dungeon::get_dungeon_start_room(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_start_rooms.size(), Ref<DungeonRoom>());

	return _dungeon_start_rooms.get(index);
}
void Dungeon::set_dungeon_start_room(const int index, const Ref<DungeonRoom> dungeon_start_room) {
	ERR_FAIL_INDEX(index, _dungeon_start_rooms.size());

	_dungeon_start_rooms.set(index, dungeon_start_room);
}
void Dungeon::add_dungeon_start_room(const Ref<DungeonRoom> dungeon_start_room) {
	_dungeon_start_rooms.push_back(dungeon_start_room);
}
void Dungeon::remove_dungeon_start_room(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_start_rooms.size());

	_dungeon_start_rooms.remove(index);
}

int Dungeon::get_dungeon_start_room_count() const {
	return _dungeon_start_rooms.size();
}

Vector<Variant> Dungeon::get_dungeon_start_rooms() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_start_rooms.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_start_rooms[i].get_ref_ptr());
#else
		r.push_back(_dungeon_start_rooms[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_start_rooms(const Vector<Variant> &dungeon_start_rooms) {
	_dungeon_start_rooms.clear();
	for (int i = 0; i < dungeon_start_rooms.size(); i++) {
		Ref<DungeonRoom> dungeon_start_room_data = Ref<DungeonRoom>(dungeon_start_rooms[i]);

		_dungeon_start_rooms.push_back(dungeon_start_room_data);
	}
}

//End Rooms
Ref<DungeonRoom> Dungeon::get_dungeon_end_room(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_end_rooms.size(), Ref<DungeonRoom>());

	return _dungeon_end_rooms.get(index);
}
void Dungeon::set_dungeon_end_room(const int index, const Ref<DungeonRoom> dungeon_end_room) {
	ERR_FAIL_INDEX(index, _dungeon_end_rooms.size());

	_dungeon_end_rooms.set(index, dungeon_end_room);
}
void Dungeon::add_dungeon_end_room(const Ref<DungeonRoom> dungeon_end_room) {
	_dungeon_end_rooms.push_back(dungeon_end_room);
}
void Dungeon::remove_dungeon_end_room(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_end_rooms.size());

	_dungeon_end_rooms.remove(index);
}

int Dungeon::get_dungeon_end_room_count() const {
	return _dungeon_end_rooms.size();
}

Vector<Variant> Dungeon::get_dungeon_end_rooms() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_end_rooms.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_end_rooms[i].get_ref_ptr());
#else
		r.push_back(_dungeon_end_rooms[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_end_rooms(const Vector<Variant> &dungeon_end_rooms) {
	_dungeon_end_rooms.clear();
	for (int i = 0; i < dungeon_end_rooms.size(); i++) {
		Ref<DungeonRoom> dungeon_end_room_data = Ref<DungeonRoom>(dungeon_end_rooms[i]);

		_dungeon_end_rooms.push_back(dungeon_end_room_data);
	}
}

//Corridors
Ref<DungeonCorridor> Dungeon::get_dungeon_corridor(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_corridors.size(), Ref<DungeonCorridor>());

	return _dungeon_corridors.get(index);
}
void Dungeon::set_dungeon_corridor(const int index, const Ref<DungeonCorridor> dungeon_corridor) {
	ERR_FAIL_INDEX(index, _dungeon_corridors.size());

	_dungeon_corridors.set(index, dungeon_corridor);
}
void Dungeon::add_dungeon_corridor(const Ref<DungeonCorridor> dungeon_corridor) {
	_dungeon_corridors.push_back(dungeon_corridor);
}
void Dungeon::remove_dungeon_corridor(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_corridors.size());

	_dungeon_corridors.remove(index);
}
int Dungeon::get_dungeon_corridor_count() const {
	return _dungeon_corridors.size();
}

Vector<Variant> Dungeon::get_dungeon_corridors() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_corridors.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_corridors[i].get_ref_ptr());
#else
		r.push_back(_dungeon_corridors[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_corridors(const Vector<Variant> &dungeon_corridors) {
	_dungeon_corridors.clear();
	for (int i = 0; i < dungeon_corridors.size(); i++) {
		Ref<DungeonRoom> dungeon_corridor_data = Ref<DungeonRoom>(dungeon_corridors[i]);

		_dungeon_corridors.push_back(dungeon_corridor_data);
	}
}

//Room Datas
Ref<DungeonRoom> Dungeon::get_dungeon_room_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_room_datas.size(), Ref<DungeonRoom>());

	return _dungeon_room_datas.get(index);
}
void Dungeon::set_dungeon_room_data(const int index, const Ref<DungeonRoom> dungeon_room) {
	ERR_FAIL_INDEX(index, _dungeon_room_datas.size());

	_dungeon_room_datas.set(index, dungeon_room);
}
void Dungeon::add_dungeon_room_data(const Ref<DungeonRoom> dungeon_room) {
	_dungeon_room_datas.push_back(dungeon_room);
}
void Dungeon::remove_dungeon_room_data(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_room_datas.size());

	_dungeon_room_datas.remove(index);
}

int Dungeon::get_dungeon_room_data_count() const {
	return _dungeon_room_datas.size();
}

Vector<Variant> Dungeon::get_dungeon_room_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_room_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_room_datas[i].get_ref_ptr());
#else
		r.push_back(_dungeon_room_datas[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_room_datas(const Vector<Variant> &dungeon_room_datas) {
	_dungeon_room_datas.clear();
	for (int i = 0; i < dungeon_room_datas.size(); i++) {
		Ref<DungeonRoom> dungeon_room_data = Ref<DungeonRoom>(dungeon_room_datas[i]);

		_dungeon_room_datas.push_back(dungeon_room_data);
	}
}

//Start Room Datas
Ref<DungeonRoom> Dungeon::get_dungeon_start_room_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_start_room_datas.size(), Ref<DungeonRoom>());

	return _dungeon_start_room_datas.get(index);
}
void Dungeon::set_dungeon_start_room_data(const int index, const Ref<DungeonRoom> dungeon_start_room) {
	ERR_FAIL_INDEX(index, _dungeon_start_room_datas.size());

	_dungeon_start_room_datas.set(index, dungeon_start_room);
}
void Dungeon::add_dungeon_start_room_data(const Ref<DungeonRoom> dungeon_start_room) {
	_dungeon_start_room_datas.push_back(dungeon_start_room);
}
void Dungeon::remove_dungeon_start_room_data(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_start_room_datas.size());

	_dungeon_start_room_datas.remove(index);
}

int Dungeon::get_dungeon_start_room_data_count() const {
	return _dungeon_start_room_datas.size();
}

Vector<Variant> Dungeon::get_dungeon_start_room_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_start_room_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_start_room_datas[i].get_ref_ptr());
#else
		r.push_back(_dungeon_start_room_datas[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_start_room_datas(const Vector<Variant> &dungeon_start_room_datas) {
	_dungeon_start_room_datas.clear();
	for (int i = 0; i < dungeon_start_room_datas.size(); i++) {
		Ref<DungeonRoom> dungeon_start_room_data = Ref<DungeonRoom>(dungeon_start_room_datas[i]);

		_dungeon_start_room_datas.push_back(dungeon_start_room_data);
	}
}

//End Room Datas
Ref<DungeonRoom> Dungeon::get_dungeon_end_room_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_end_room_datas.size(), Ref<DungeonRoom>());

	return _dungeon_end_room_datas.get(index);
}
void Dungeon::set_dungeon_end_room_data(const int index, const Ref<DungeonRoom> dungeon_end_room) {
	ERR_FAIL_INDEX(index, _dungeon_end_room_datas.size());

	_dungeon_end_room_datas.set(index, dungeon_end_room);
}
void Dungeon::add_dungeon_end_room_data(const Ref<DungeonRoom> dungeon_end_room) {
	_dungeon_end_room_datas.push_back(dungeon_end_room);
}
void Dungeon::remove_dungeon_end_room_data(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_end_room_datas.size());

	_dungeon_end_room_datas.remove(index);
}

int Dungeon::get_dungeon_end_room_data_count() const {
	return _dungeon_end_room_datas.size();
}

Vector<Variant> Dungeon::get_dungeon_end_room_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_end_room_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_end_room_datas[i].get_ref_ptr());
#else
		r.push_back(_dungeon_end_room_datas[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_end_room_datas(const Vector<Variant> &dungeon_end_room_datas) {
	_dungeon_end_room_datas.clear();
	for (int i = 0; i < dungeon_end_room_datas.size(); i++) {
		Ref<DungeonRoom> dungeon_end_room_data = Ref<DungeonRoom>(dungeon_end_room_datas[i]);

		_dungeon_end_room_datas.push_back(dungeon_end_room_data);
	}
}

//Corridor Datas
Ref<DungeonCorridor> Dungeon::get_dungeon_corridor_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_corridor_datas.size(), Ref<DungeonCorridor>());

	return _dungeon_corridor_datas.get(index);
}
void Dungeon::set_dungeon_corridor_data(const int index, const Ref<DungeonCorridor> dungeon_corridor) {
	ERR_FAIL_INDEX(index, _dungeon_corridor_datas.size());

	_dungeon_corridor_datas.set(index, dungeon_corridor);
}
void Dungeon::add_dungeon_corridor_data(const Ref<DungeonCorridor> dungeon_corridor) {
	_dungeon_corridor_datas.push_back(dungeon_corridor);
}
void Dungeon::remove_dungeon_corridor_data(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_corridor_datas.size());

	_dungeon_corridor_datas.remove(index);
}
int Dungeon::get_dungeon_corridor_data_count() const {
	return _dungeon_corridor_datas.size();
}

Vector<Variant> Dungeon::get_dungeon_corridor_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_corridor_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_corridor_datas[i].get_ref_ptr());
#else
		r.push_back(_dungeon_corridor_datas[i]);
#endif
	}
	return r;
}
void Dungeon::set_dungeon_corridor_datas(const Vector<Variant> &dungeon_corridor_datas) {
	_dungeon_corridor_datas.clear();
	for (int i = 0; i < dungeon_corridor_datas.size(); i++) {
		Ref<DungeonRoom> dungeon_corridor_data = Ref<DungeonRoom>(dungeon_corridor_datas[i]);

		_dungeon_corridor_datas.push_back(dungeon_corridor_data);
	}
}

#ifdef ESS_PRESENT
//Entities
Ref<EntityData> Dungeon::get_entity_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _entity_datas.size(), Ref<DungeonCorridor>());

	return _entity_datas.get(index);
}
void Dungeon::set_entity_data(const int index, const Ref<EntityData> entity_data) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.set(index, entity_data);
}
void Dungeon::add_entity_data(const Ref<EntityData> entity_data) {
	_entity_datas.push_back(entity_data);
}
void Dungeon::remove_entity_data(const int index) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.remove(index);
}
int Dungeon::get_entity_data_count() const {
	return _entity_datas.size();
}

Vector<Variant> Dungeon::get_entity_datas() {
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
void Dungeon::set_entity_datas(const Vector<Variant> &entity_datas) {
	_entity_datas.clear();
	for (int i = 0; i < entity_datas.size(); i++) {
		Ref<EntityData> entity_data = Ref<EntityData>(entity_datas[i]);

		_entity_datas.push_back(entity_data);
	}
}
#endif

#ifdef VOXELMAN_PRESENT
////    Surfaces    ////
Ref<VoxelSurface> Dungeon::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void Dungeon::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void Dungeon::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void Dungeon::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int Dungeon::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> Dungeon::get_voxel_surfaces() {
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
void Dungeon::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<EnvironmentData> voxel_surface = Ref<EnvironmentData>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

//Environments
Ref<EnvironmentData> Dungeon::get_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _environment_datas.size(), Ref<EnvironmentData>());

	return _environment_datas.get(index);
}
void Dungeon::set_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.set(index, environment_data);
}
void Dungeon::add_environment_data(const Ref<EnvironmentData> environment_data) {
	_environment_datas.push_back(environment_data);
}
void Dungeon::remove_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.remove(index);
}
int Dungeon::get_environment_data_count() const {
	return _environment_datas.size();
}

Vector<Variant> Dungeon::get_environment_datas() {
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
void Dungeon::set_environment_datas(const Vector<Variant> &environment_datas) {
	_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_environment_datas.push_back(environment_data);
	}
}
#endif

Ref<Dungeon> Dungeon::instance(const int seed) {
	Ref<Dungeon> inst;

	inst = Ref<Dungeon>(Object::cast_to<Dungeon>(ClassDB::instance(get_class_name())));
	ERR_FAIL_COND_V(!inst.is_valid(), inst);

	if (!get_script().is_null())
		inst->set_script(get_script());

	return call("_instance", seed, inst);
}

Ref<Dungeon> Dungeon::_instance(const int seed, Ref<Dungeon> inst) {
	inst->set_current_seed(seed);
	inst->set_level_range(_level_range);

	inst->set_posx(_posx);
	inst->set_posy(_posy);
	inst->set_posz(_posz);

	inst->set_sizex(_sizex);
	inst->set_sizey(_sizey);
	inst->set_sizez(_sizez);

	inst->set_room_count(_room_count);

	inst->set_min_sizex(_min_sizex);
	inst->set_min_sizey(_min_sizey);
	inst->set_min_sizez(_min_sizez);

	inst->set_max_sizex(_max_sizex);
	inst->set_max_sizey(_max_sizey);
	inst->set_max_sizez(_max_sizez);

	inst->set_min_room_count(_min_room_count);
	inst->set_max_room_count(_max_room_count);

#ifdef VOXELMAN_PRESENT
	inst->set_environment(_environment);
#endif

	for (int i = 0; i < _dungeon_rooms.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_rooms[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_room(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_start_rooms.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_start_rooms[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_start_room(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_end_rooms.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_end_rooms[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_end_room(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_corridors.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_corridors[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_corridor(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_room_datas.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_room_datas[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_room_data(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_start_room_datas.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_start_room_datas[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_start_room_data(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_end_room_datas.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_end_room_datas[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_end_room_data(r->instance(seed));
	}

	for (int i = 0; i < _dungeon_corridor_datas.size(); ++i) {
		Ref<DungeonRoom> r = _dungeon_corridor_datas[i];

		if (!r.is_valid())
			continue;

		inst->add_dungeon_corridor_data(r->instance(seed));
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

void Dungeon::setup() {
	if (has_method("_setup")) {
		call("_setup");
	}
}

#ifdef VOXELMAN_PRESENT
void Dungeon::setup_library(Ref<VoxelmanLibrary> library) {
	if (has_method("_setup_library")) {
		call("_setup_library", library);
	}
}

void Dungeon::_setup_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = get_voxel_surface(i);

		if (s.is_valid()) {
			library->add_voxel_surface(s);
		}
	}

	for (int i = 0; i < get_dungeon_corridor_count(); ++i) {
		Ref<DungeonCorridor> d = get_dungeon_corridor(i);

		if (d.is_valid()) {
			d->setup_library(library);
		}
	}

	for (int i = 0; i < get_dungeon_end_room_count(); ++i) {
		Ref<DungeonRoom> d = get_dungeon_end_room(i);

		if (d.is_valid()) {
			d->setup_library(library);
		}
	}

	for (int i = 0; i < get_dungeon_room_count(); ++i) {
		Ref<DungeonRoom> d = get_dungeon_room(i);

		if (d.is_valid()) {
			d->setup_library(library);
		}
	}

	for (int i = 0; i < get_dungeon_start_room_count(); ++i) {
		Ref<DungeonRoom> d = get_dungeon_start_room(i);

		if (d.is_valid()) {
			d->setup_library(library);
		}
	}
}

void Dungeon::generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk, spawn_mobs);
	}
}

void Dungeon::generate_structure(Ref<VoxelStructure> structure, bool spawn_mobs) {
	if (has_method("_generate_structure")) {
		call("_generate_structure", structure, spawn_mobs);
	}
}
#else

void Dungeon::setup_library(Ref<Resource> library) {
	if (has_method("_setup_library")) {
		call("_setup_library", library);
	}
}

void Dungeon::generate_chunk(Ref<Resource> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk, spawn_mobs);
	}
}
#endif

Ref<Image> Dungeon::generate_map() {
	ERR_FAIL_COND_V(!has_method("_generate_map"), Ref<Image>());

	return call("_generate_map");
}

Dungeon::Dungeon() {
	_current_seed = 0;

	_min_sizex = 0;
	_min_sizey = 0;
	_min_sizez = 0;

	_max_sizex = 0;
	_max_sizey = 0;
	_max_sizez = 0;

	_min_room_count = 0;
	_max_room_count = 0;

	_posx = 0;
	_posy = 0;
	_posz = 0;

	_sizex = 0;
	_sizey = 0;
	_sizez = 0;

	_room_count = 0;
}
Dungeon::~Dungeon() {
#ifdef VOXELMAN_PRESENT
	_environment.unref();
#endif

	_dungeon_rooms.clear();
	_dungeon_start_rooms.clear();
	_dungeon_end_rooms.clear();
	_dungeon_corridors.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

#ifdef VOXELMAN_PRESENT
	_environment_datas.clear();
	_voxel_surfaces.clear();
#endif
}

void Dungeon::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "inst", PROPERTY_HINT_RESOURCE_TYPE, "Dungeon"),
			"_instance",
			PropertyInfo(Variant::INT, "p_seed"),
			PropertyInfo(Variant::OBJECT, "p_instance", PROPERTY_HINT_RESOURCE_TYPE, "Dungeon")));

	BIND_VMETHOD(MethodInfo("_setup"));

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_structure", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#else
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "Resource")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "Node"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#endif

	ClassDB::bind_method(D_METHOD("instance", "seed"), &Dungeon::instance);
	ClassDB::bind_method(D_METHOD("_instance", "p_seed", "p_instance"), &Dungeon::_instance);

	ClassDB::bind_method(D_METHOD("setup"), &Dungeon::setup);

#ifdef VOXELMAN_PRESENT
	ClassDB::bind_method(D_METHOD("setup_library", "library"), &Dungeon::setup_library);
	ClassDB::bind_method(D_METHOD("_setup_library", "library"), &Dungeon::_setup_library);

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk", "spawn_mobs"), &Dungeon::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_structure", "structure", "spawn_mobs"), &Dungeon::generate_structure);
#else
	ClassDB::bind_method(D_METHOD("setup_library", "library"), &Dungeon::setup_library);
	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk", "spawn_mobs"), &Dungeon::generate_chunk);
#endif

	ClassDB::bind_method(D_METHOD("get_current_seed"), &Dungeon::get_current_seed);
	ClassDB::bind_method(D_METHOD("set_current_seed", "value"), &Dungeon::set_current_seed);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "current_seed"), "set_current_seed", "get_current_seed");

	ClassDB::bind_method(D_METHOD("get_level_range"), &Dungeon::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &Dungeon::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

	//Min Size
	ClassDB::bind_method(D_METHOD("get_min_sizex"), &Dungeon::get_min_sizex);
	ClassDB::bind_method(D_METHOD("set_min_sizex", "value"), &Dungeon::set_min_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_sizex"), "set_min_sizex", "get_min_sizex");

	ClassDB::bind_method(D_METHOD("get_min_sizey"), &Dungeon::get_min_sizey);
	ClassDB::bind_method(D_METHOD("set_min_sizey", "value"), &Dungeon::set_min_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_sizey"), "set_min_sizey", "get_min_sizey");

	ClassDB::bind_method(D_METHOD("get_min_sizez"), &Dungeon::get_min_sizez);
	ClassDB::bind_method(D_METHOD("set_min_sizez", "value"), &Dungeon::set_min_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_sizez"), "set_min_sizez", "get_min_sizez");

	//Max Size
	ClassDB::bind_method(D_METHOD("get_max_sizex"), &Dungeon::get_max_sizex);
	ClassDB::bind_method(D_METHOD("set_max_sizex", "value"), &Dungeon::set_max_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_sizex"), "set_max_sizex", "get_max_sizex");

	ClassDB::bind_method(D_METHOD("get_max_sizey"), &Dungeon::get_max_sizey);
	ClassDB::bind_method(D_METHOD("set_max_sizey", "value"), &Dungeon::set_max_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_sizey"), "set_max_sizey", "get_max_sizey");

	ClassDB::bind_method(D_METHOD("get_max_sizez"), &Dungeon::get_max_sizez);
	ClassDB::bind_method(D_METHOD("set_max_sizez", "value"), &Dungeon::set_max_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_sizez"), "set_max_sizez", "get_max_sizez");

	//Room Count
	ClassDB::bind_method(D_METHOD("get_min_room_count"), &Dungeon::get_min_room_count);
	ClassDB::bind_method(D_METHOD("set_min_room_count", "value"), &Dungeon::set_min_room_count);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "min_room_count"), "set_min_room_count", "get_min_room_count");

	ClassDB::bind_method(D_METHOD("get_max_room_count"), &Dungeon::get_max_room_count);
	ClassDB::bind_method(D_METHOD("set_max_room_count", "value"), &Dungeon::set_max_room_count);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_room_count"), "set_max_room_count", "get_max_room_count");

	//Position
	ClassDB::bind_method(D_METHOD("get_posx"), &Dungeon::get_posx);
	ClassDB::bind_method(D_METHOD("set_posx", "value"), &Dungeon::set_posx);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posx"), "set_posx", "get_posx");

	ClassDB::bind_method(D_METHOD("get_posy"), &Dungeon::get_posy);
	ClassDB::bind_method(D_METHOD("set_posy", "value"), &Dungeon::set_posy);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posy"), "set_posy", "get_posy");

	ClassDB::bind_method(D_METHOD("get_posz"), &Dungeon::get_posz);
	ClassDB::bind_method(D_METHOD("set_posz", "value"), &Dungeon::set_posz);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "posz"), "set_posz", "get_posz");

	//Size
	ClassDB::bind_method(D_METHOD("get_sizex"), &Dungeon::get_sizex);
	ClassDB::bind_method(D_METHOD("set_sizex", "value"), &Dungeon::set_sizex);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizex"), "set_sizex", "get_sizex");

	ClassDB::bind_method(D_METHOD("get_sizey"), &Dungeon::get_sizey);
	ClassDB::bind_method(D_METHOD("set_sizey", "value"), &Dungeon::set_sizey);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizey"), "set_sizey", "get_sizey");

	ClassDB::bind_method(D_METHOD("get_sizez"), &Dungeon::get_sizez);
	ClassDB::bind_method(D_METHOD("set_sizez", "value"), &Dungeon::set_sizez);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sizez"), "set_sizez", "get_sizez");

	//Room Count
	ClassDB::bind_method(D_METHOD("get_room_count"), &Dungeon::get_room_count);
	ClassDB::bind_method(D_METHOD("set_room_count", "value"), &Dungeon::set_room_count);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "room_count"), "set_room_count", "get_room_count");

#ifdef VOXELMAN_PRESENT
	//Environment
	ClassDB::bind_method(D_METHOD("get_environment"), &Dungeon::get_environment);
	ClassDB::bind_method(D_METHOD("set_environment", "value"), &Dungeon::set_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_environment", "get_environment");
#endif

	//Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_room", "index"), &Dungeon::get_dungeon_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_room", "index", "data"), &Dungeon::set_dungeon_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_room", "dungeon_room"), &Dungeon::add_dungeon_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room", "index"), &Dungeon::remove_dungeon_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_count"), &Dungeon::get_dungeon_room_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_rooms"), &Dungeon::get_dungeon_rooms);
	ClassDB::bind_method(D_METHOD("set_dungeon_rooms", "dungeon_rooms"), &Dungeon::set_dungeon_rooms);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_rooms", PROPERTY_HINT_NONE, "17/17:DungeonRoom", PROPERTY_USAGE_DEFAULT, "DungeonRoom"), "set_dungeon_rooms", "get_dungeon_rooms");

	//Start Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_start_room", "index"), &Dungeon::get_dungeon_start_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_start_room", "index", "data"), &Dungeon::set_dungeon_start_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_start_room", "dungeon_start_room"), &Dungeon::add_dungeon_start_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_start_room", "index"), &Dungeon::remove_dungeon_start_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_start_room_count"), &Dungeon::get_dungeon_start_room_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_start_rooms"), &Dungeon::get_dungeon_start_rooms);
	ClassDB::bind_method(D_METHOD("set_dungeon_start_rooms", "dungeon_start_rooms"), &Dungeon::set_dungeon_start_rooms);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_start_rooms", PROPERTY_HINT_NONE, "17/17:DungeonRoom", PROPERTY_USAGE_DEFAULT, "DungeonRoom"), "set_dungeon_start_rooms", "get_dungeon_start_rooms");

	//End Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_end_room", "index"), &Dungeon::get_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_end_room", "index", "data"), &Dungeon::set_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_end_room", "dungeon_end_room"), &Dungeon::add_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_end_room", "index"), &Dungeon::remove_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("get_dungeon_end_room_count"), &Dungeon::get_dungeon_end_room_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_end_rooms"), &Dungeon::get_dungeon_end_rooms);
	ClassDB::bind_method(D_METHOD("set_dungeon_end_rooms", "dungeon_end_rooms"), &Dungeon::set_dungeon_end_rooms);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_end_rooms", PROPERTY_HINT_NONE, "17/17:DungeonRoom", PROPERTY_USAGE_DEFAULT, "DungeonRoom"), "set_dungeon_end_rooms", "get_dungeon_end_rooms");

	//Corridors
	ClassDB::bind_method(D_METHOD("get_dungeon_corridor", "index"), &Dungeon::get_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("set_dungeon_corridor", "index", "data"), &Dungeon::set_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("add_dungeon_corridor", "dungeon_corridor"), &Dungeon::add_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("remove_dungeon_corridor", "index"), &Dungeon::remove_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("get_dungeon_corridor_count"), &Dungeon::get_dungeon_corridor_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_corridors"), &Dungeon::get_dungeon_corridors);
	ClassDB::bind_method(D_METHOD("set_dungeon_corridors", "dungeon_corridors"), &Dungeon::set_dungeon_corridors);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_corridors", PROPERTY_HINT_NONE, "17/17:DungeonCorridor", PROPERTY_USAGE_DEFAULT, "DungeonCorridor"), "set_dungeon_corridors", "get_dungeon_corridors");

	//Room Datas
	ClassDB::bind_method(D_METHOD("get_dungeon_room_data", "index"), &Dungeon::get_dungeon_room_data);
	ClassDB::bind_method(D_METHOD("set_dungeon_room_data", "index", "data"), &Dungeon::set_dungeon_room_data);
	ClassDB::bind_method(D_METHOD("add_dungeon_room_data", "dungeon_room_data"), &Dungeon::add_dungeon_room_data);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room_data", "index"), &Dungeon::remove_dungeon_room_data);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_data_count"), &Dungeon::get_dungeon_room_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_datas"), &Dungeon::get_dungeon_room_datas);
	ClassDB::bind_method(D_METHOD("set_dungeon_room_datas", "dungeon_room_datas"), &Dungeon::set_dungeon_room_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_room_datas", PROPERTY_HINT_NONE, "17/17:DungeonRoom", PROPERTY_USAGE_DEFAULT, "DungeonRoom"), "set_dungeon_room_datas", "get_dungeon_room_datas");

	//Start Room Datas
	ClassDB::bind_method(D_METHOD("get_dungeon_start_room_data", "index"), &Dungeon::get_dungeon_start_room_data);
	ClassDB::bind_method(D_METHOD("set_dungeon_start_room_data", "index", "data"), &Dungeon::set_dungeon_start_room_data);
	ClassDB::bind_method(D_METHOD("add_dungeon_start_room_data", "dungeon_start_room_data"), &Dungeon::add_dungeon_start_room_data);
	ClassDB::bind_method(D_METHOD("remove_dungeon_start_room_data", "index"), &Dungeon::remove_dungeon_start_room_data);

	ClassDB::bind_method(D_METHOD("get_dungeon_start_room_data_count"), &Dungeon::get_dungeon_start_room_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_start_room_datas"), &Dungeon::get_dungeon_start_room_datas);
	ClassDB::bind_method(D_METHOD("set_dungeon_start_room_datas", "dungeon_start_room_datas"), &Dungeon::set_dungeon_start_room_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_start_room_datas", PROPERTY_HINT_NONE, "17/17:DungeonRoom", PROPERTY_USAGE_DEFAULT, "DungeonRoom"), "set_dungeon_start_room_datas", "get_dungeon_start_room_datas");

	//End Room Datas
	ClassDB::bind_method(D_METHOD("get_dungeon_end_room_data", "index"), &Dungeon::get_dungeon_end_room_data);
	ClassDB::bind_method(D_METHOD("set_dungeon_end_room_data", "index", "data"), &Dungeon::set_dungeon_end_room_data);
	ClassDB::bind_method(D_METHOD("add_dungeon_end_room_data", "dungeon_end_room_data"), &Dungeon::add_dungeon_end_room_data);
	ClassDB::bind_method(D_METHOD("remove_dungeon_end_room_data", "index"), &Dungeon::remove_dungeon_end_room_data);
	ClassDB::bind_method(D_METHOD("get_dungeon_end_room_data_count"), &Dungeon::get_dungeon_end_room_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_end_room_datas"), &Dungeon::get_dungeon_end_room_datas);
	ClassDB::bind_method(D_METHOD("set_dungeon_end_room_datas", "dungeon_end_room_datas"), &Dungeon::set_dungeon_end_room_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_end_room_datas", PROPERTY_HINT_NONE, "17/17:DungeonRoom", PROPERTY_USAGE_DEFAULT, "DungeonRoom"), "set_dungeon_end_room_datas", "get_dungeon_end_room_datas");

	//Corridor Datas
	ClassDB::bind_method(D_METHOD("get_dungeon_corridor_data", "index"), &Dungeon::get_dungeon_corridor_data);
	ClassDB::bind_method(D_METHOD("set_dungeon_corridor_data", "index", "data"), &Dungeon::set_dungeon_corridor_data);
	ClassDB::bind_method(D_METHOD("add_dungeon_corridor_data", "dungeon_corridor_data"), &Dungeon::add_dungeon_corridor_data);
	ClassDB::bind_method(D_METHOD("remove_dungeon_corridor_data", "index"), &Dungeon::remove_dungeon_corridor_data);
	ClassDB::bind_method(D_METHOD("get_dungeon_corridor_data_count"), &Dungeon::get_dungeon_corridor_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_corridor_datas"), &Dungeon::get_dungeon_corridor_datas);
	ClassDB::bind_method(D_METHOD("set_dungeon_corridor_datas", "dungeon_corridor_datas"), &Dungeon::set_dungeon_corridor_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_corridor_datas", PROPERTY_HINT_NONE, "17/17:DungeonCorridor", PROPERTY_USAGE_DEFAULT, "DungeonCorridor"), "set_dungeon_corridor_datas", "get_dungeon_corridor_datas");

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &Dungeon::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &Dungeon::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &Dungeon::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &Dungeon::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &Dungeon::get_entity_data_count);

	ClassDB::bind_method(D_METHOD("get_entity_datas"), &Dungeon::get_entity_datas);
	ClassDB::bind_method(D_METHOD("set_entity_datas", "entity_datas"), &Dungeon::set_entity_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "entity_datas", PROPERTY_HINT_NONE, "17/17:EntityData", PROPERTY_USAGE_DEFAULT, "EntityData"), "set_entity_datas", "get_entity_datas");
#endif

#ifdef VOXELMAN_PRESENT
	//Environments
	ClassDB::bind_method(D_METHOD("get_environment_data", "index"), &Dungeon::get_environment_data);
	ClassDB::bind_method(D_METHOD("set_environment_data", "index", "data"), &Dungeon::set_environment_data);
	ClassDB::bind_method(D_METHOD("add_environment_data", "environment_data"), &Dungeon::add_environment_data);
	ClassDB::bind_method(D_METHOD("remove_environment_data", "index"), &Dungeon::remove_environment_data);
	ClassDB::bind_method(D_METHOD("get_environment_data_count"), &Dungeon::get_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_environment_datas"), &Dungeon::get_environment_datas);
	ClassDB::bind_method(D_METHOD("set_environment_datas", "environment_datas"), &Dungeon::set_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_environment_datas", "get_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &Dungeon::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &Dungeon::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &Dungeon::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &Dungeon::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &Dungeon::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &Dungeon::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &Dungeon::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");
#endif

	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "image", PROPERTY_HINT_RESOURCE_TYPE, "Image"), "_generate_map"));

	ClassDB::bind_method(D_METHOD("generate_map"), &Dungeon::generate_map);
}
