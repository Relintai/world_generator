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

Ref<DungeonData> Dungeon::get_data() {
	return _data;
}
void Dungeon::set_data(Ref<DungeonData> value) {
	_data = value;

	setup();
}

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
#endif

void Dungeon::setup() {
	if (!_data.is_valid())
		return;

	if (has_method("_setup")) {
		call("_setup");
	}
}

#ifdef VOXELMAN_PRESENT
void Dungeon::setup_library(Ref<VoxelmanLibrary> library) {
	if (!_data.is_valid())
		return;

	if (has_method("_setup_library")) {
		call("_setup_library", library);
	}
}

void Dungeon::_setup_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < _data->get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = _data->get_voxel_surface(i);

		if (s.is_valid()) {
			library->add_voxel_surface(s);
		}
	}

	for (int i = 0; i < _data->get_liquid_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = _data->get_liquid_voxel_surface(i);

		if (s.is_valid()) {
			library->add_liquid_surface(s);
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
	if (!_data.is_valid())
		return;

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

	_data.unref();
	_dungeon_rooms.clear();
	_dungeon_start_rooms.clear();
	_dungeon_end_rooms.clear();
	_dungeon_corridors.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif
}

void Dungeon::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_setup"));

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_structure", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#else
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "Resource")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "Node"), PropertyInfo(Variant::BOOL, "spawn_mobs")));
#endif

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

	ClassDB::bind_method(D_METHOD("get_data"), &Dungeon::get_data);
	ClassDB::bind_method(D_METHOD("set_data", "value"), &Dungeon::set_data);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data", PROPERTY_HINT_RESOURCE_TYPE, "PlanetData"), "set_data", "get_data");

	//Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_room", "index"), &Dungeon::get_dungeon_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_room", "index", "data"), &Dungeon::set_dungeon_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_room", "dungeon_room"), &Dungeon::add_dungeon_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room", "index"), &Dungeon::remove_dungeon_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_count"), &Dungeon::get_dungeon_room_count);

	//Start Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_start_room", "index"), &Dungeon::get_dungeon_start_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_start_room", "index", "data"), &Dungeon::set_dungeon_start_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_start_room", "dungeon_start_room"), &Dungeon::add_dungeon_start_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_start_room", "index"), &Dungeon::remove_dungeon_start_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_start_room_count"), &Dungeon::get_dungeon_start_room_count);

	//End Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_end_room", "index"), &Dungeon::get_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_end_room", "index", "data"), &Dungeon::set_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_end_room", "dungeon_end_room"), &Dungeon::add_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_end_room", "index"), &Dungeon::remove_dungeon_end_room);
	ClassDB::bind_method(D_METHOD("get_dungeon_end_room_count"), &Dungeon::get_dungeon_end_room_count);

	//Corridors
	ClassDB::bind_method(D_METHOD("get_dungeon_corridor", "index"), &Dungeon::get_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("set_dungeon_corridor", "index", "data"), &Dungeon::set_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("add_dungeon_corridor", "dungeon_corridor"), &Dungeon::add_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("remove_dungeon_corridor", "index"), &Dungeon::remove_dungeon_corridor);
	ClassDB::bind_method(D_METHOD("get_dungeon_corridor_count"), &Dungeon::get_dungeon_corridor_count);

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &Dungeon::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &Dungeon::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &Dungeon::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &Dungeon::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &Dungeon::get_entity_data_count);
#endif

	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "image", PROPERTY_HINT_RESOURCE_TYPE, "Image"), "_generate_map"));

	ClassDB::bind_method(D_METHOD("generate_map"), &Dungeon::generate_map);
}
