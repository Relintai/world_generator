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

#ifndef DUNGEON_H
#define DUNGEON_H

#include "core/version.h"

#if VERSION_MAJOR > 3
#include "core/io/resource.h"
#include "core/object/reference.h"
#else
#include "core/reference.h"
#include "core/resource.h"
#endif

#include "dungeon_corridor.h"
#include "dungeon_room.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxelman_library.h"
#include "../../voxelman/world/environment_data.h"
#include "../../voxelman/world/voxel_chunk.h"
#include "../../voxelman/world/voxel_structure.h"
#else
#include "scene/main/node.h"
#endif

#ifdef ESS_PRESENT
#include "../../entity_spell_system/entities/data/entity_data.h"
#endif

class Dungeon : public Resource {
	GDCLASS(Dungeon, Resource);

public:
	int get_current_seed();
	void set_current_seed(int value);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

	//Min Size
	int get_min_sizex();
	void set_min_sizex(int value);

	int get_min_sizey();
	void set_min_sizey(int value);

	int get_min_sizez();
	void set_min_sizez(int value);

	//Max Size
	int get_max_sizex();
	void set_max_sizex(int value);

	int get_max_sizey();
	void set_max_sizey(int value);

	int get_max_sizez();
	void set_max_sizez(int value);

	//Room Count
	int get_min_room_count();
	void set_min_room_count(int value);

	int get_max_room_count();
	void set_max_room_count(int value);

	//Pos
	int get_posx();
	void set_posx(int value);

	int get_posy();
	void set_posy(int value);

	int get_posz();
	void set_posz(int value);

	//Size
	int get_sizex();
	void set_sizex(int value);

	int get_sizey();
	void set_sizey(int value);

	int get_sizez();
	void set_sizez(int value);

	//Room Count
	int get_room_count();
	void set_room_count(int value);

#ifdef VOXELMAN_PRESENT
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);
#endif

	//Rooms
	Ref<DungeonRoom> get_dungeon_room(const int index) const;
	void set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room);
	void add_dungeon_room(const Ref<DungeonRoom> dungeon_room);
	void remove_dungeon_room(const int index);
	int get_dungeon_room_count() const;

	Vector<Variant> get_dungeon_rooms();
	void set_dungeon_rooms(const Vector<Variant> &dungeon_rooms);

	//Start Rooms
	Ref<DungeonRoom> get_dungeon_start_room(const int index) const;
	void set_dungeon_start_room(const int index, const Ref<DungeonRoom> dungeon_start_room);
	void add_dungeon_start_room(const Ref<DungeonRoom> dungeon_start_room);
	void remove_dungeon_start_room(const int index);
	int get_dungeon_start_room_count() const;

	Vector<Variant> get_dungeon_start_rooms();
	void set_dungeon_start_rooms(const Vector<Variant> &dungeon_start_rooms);

	//End Rooms
	Ref<DungeonRoom> get_dungeon_end_room(const int index) const;
	void set_dungeon_end_room(const int index, const Ref<DungeonRoom> dungeon_end_room);
	void add_dungeon_end_room(const Ref<DungeonRoom> dungeon_end_room);
	void remove_dungeon_end_room(const int index);
	int get_dungeon_end_room_count() const;

	Vector<Variant> get_dungeon_end_rooms();
	void set_dungeon_end_rooms(const Vector<Variant> &dungeon_end_rooms);

	//Corridors
	Ref<DungeonCorridor> get_dungeon_corridor(const int index) const;
	void set_dungeon_corridor(const int index, const Ref<DungeonCorridor> dungeon_corridors);
	void add_dungeon_corridor(const Ref<DungeonCorridor> dungeon_corridors);
	void remove_dungeon_corridor(const int index);
	int get_dungeon_corridor_count() const;

	Vector<Variant> get_dungeon_corridors();
	void set_dungeon_corridors(const Vector<Variant> &dungeon_corridors);

	//Room Datas
	Ref<DungeonRoom> get_dungeon_room_data(const int index) const;
	void set_dungeon_room_data(const int index, const Ref<DungeonRoom> dungeon_room);
	void add_dungeon_room_data(const Ref<DungeonRoom> dungeon_room);
	void remove_dungeon_room_data(const int index);
	int get_dungeon_room_data_count() const;

	Vector<Variant> get_dungeon_room_datas();
	void set_dungeon_room_datas(const Vector<Variant> &dungeon_rooms);

	//Start Room Datas
	Ref<DungeonRoom> get_dungeon_start_room_data(const int index) const;
	void set_dungeon_start_room_data(const int index, const Ref<DungeonRoom> dungeon_start_room);
	void add_dungeon_start_room_data(const Ref<DungeonRoom> dungeon_start_room);
	void remove_dungeon_start_room_data(const int index);
	int get_dungeon_start_room_data_count() const;

	Vector<Variant> get_dungeon_start_room_datas();
	void set_dungeon_start_room_datas(const Vector<Variant> &dungeon_start_rooms);

	//End Room Datas
	Ref<DungeonRoom> get_dungeon_end_room_data(const int index) const;
	void set_dungeon_end_room_data(const int index, const Ref<DungeonRoom> dungeon_end_room);
	void add_dungeon_end_room_data(const Ref<DungeonRoom> dungeon_end_room);
	void remove_dungeon_end_room_data(const int index);
	int get_dungeon_end_room_data_count() const;

	Vector<Variant> get_dungeon_end_room_datas();
	void set_dungeon_end_room_datas(const Vector<Variant> &dungeon_end_rooms);

	//Corridor Datas
	Ref<DungeonCorridor> get_dungeon_corridor_data(const int index) const;
	void set_dungeon_corridor_data(const int index, const Ref<DungeonCorridor> dungeon_corridors);
	void add_dungeon_corridor_data(const Ref<DungeonCorridor> dungeon_corridors);
	void remove_dungeon_corridor_data(const int index);
	int get_dungeon_corridor_data_count() const;

	Vector<Variant> get_dungeon_corridor_datas();
	void set_dungeon_corridor_datas(const Vector<Variant> &dungeon_corridors);

#ifdef ESS_PRESENT
	//Entities
	Ref<EntityData> get_entity_data(const int index) const;
	void set_entity_data(const int index, const Ref<EntityData> entity_datas);
	void add_entity_data(const Ref<EntityData> entity_datas);
	void remove_entity_data(const int index);
	int get_entity_data_count() const;

	Vector<Variant> get_entity_datas();
	void set_entity_datas(const Vector<Variant> &entity_datas);
#endif

#ifdef VOXELMAN_PRESENT
	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);
	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);
#endif

#ifdef VOXELMAN_PRESENT
	//Surfaces
	Ref<VoxelSurface> get_voxel_surface(const int index) const;
	void set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface);
	void add_voxel_surface(const Ref<VoxelSurface> voxel_surface);
	void remove_voxel_surface(const int index);
	int get_voxel_surface_count() const;

	Vector<Variant> get_voxel_surfaces();
	void set_voxel_surfaces(const Vector<Variant> &voxel_surfaces);

#endif

	Ref<Dungeon> instance(const int seed);
	virtual Ref<Dungeon> _instance(const int seed, Ref<Dungeon> inst);

	void setup();

#ifdef VOXELMAN_PRESENT
	void setup_library(Ref<VoxelmanLibrary> library);
	void _setup_library(Ref<VoxelmanLibrary> library);

	void generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs);
	void generate_structure(Ref<VoxelStructure> structure, bool spawn_mobs);
#endif

	Ref<Image> generate_map();

	Dungeon();
	~Dungeon();

protected:
	static void _bind_methods();

private:
	int _current_seed;

	Vector2 _level_range;

	int _posx;
	int _posy;
	int _posz;

	int _sizex;
	int _sizey;
	int _sizez;

	int _room_count;

	int _min_sizex;
	int _min_sizey;
	int _min_sizez;

	int _max_sizex;
	int _max_sizey;
	int _max_sizez;

	int _min_room_count;
	int _max_room_count;

#ifdef VOXELMAN_PRESENT
	Ref<EnvironmentData> _environment;
#endif

	Vector<Ref<DungeonRoom> > _dungeon_rooms;
	Vector<Ref<DungeonRoom> > _dungeon_start_rooms;
	Vector<Ref<DungeonRoom> > _dungeon_end_rooms;
	Vector<Ref<DungeonCorridor> > _dungeon_corridors;

	Vector<Ref<DungeonRoom> > _dungeon_room_datas;
	Vector<Ref<DungeonRoom> > _dungeon_start_room_datas;
	Vector<Ref<DungeonRoom> > _dungeon_end_room_datas;
	Vector<Ref<DungeonCorridor> > _dungeon_corridor_datas;

#ifdef ESS_PRESENT
	Vector<Ref<EntityData> > _entity_datas;
#endif

#ifdef VOXELMAN_PRESENT
	Vector<Ref<EnvironmentData> > _environment_datas;
#endif

#ifdef VOXELMAN_PRESENT
	Vector<Ref<VoxelSurface> > _voxel_surfaces;
#endif
};

#endif
