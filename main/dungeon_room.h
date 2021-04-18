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

#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "core/version.h"

#if VERSION_MAJOR > 3
#include "core/io/resource.h"
#include "core/object/reference.h"
#include "core/templates/vector.h"
#else
#include "core/reference.h"
#include "core/resource.h"
#include "core/vector.h"
#endif

#include "../data/world_generator_prop_data.h"

#include "scene/resources/packed_scene.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxelman_library.h"
#include "../../voxelman/world/environment_data.h"
#include "../../voxelman/world/voxel_chunk.h"
#include "../../voxelman/world/voxel_structure.h"
#else
#include "core/resource.h"
#endif

#ifdef ESS_PRESENT
#include "../../entity_spell_system/entities/data/entity_data.h"
#endif

class DungeonRoom : public Resource {
	GDCLASS(DungeonRoom, Resource);

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

	//Props
	Ref<WorldGeneratorPropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<WorldGeneratorPropData> prop_data);
	void add_prop_data(const Ref<WorldGeneratorPropData> prop_data);
	void remove_prop_data(const int index);
	int get_prop_data_count() const;

	Vector<Variant> get_prop_datas();
	void set_prop_datas(const Vector<Variant> &prop_datas);


#ifdef ESS_PRESENT
	//Entities
	Ref<EntityData> get_entity_data(const int index) const;
	void set_entity_data(const int index, const Ref<EntityData> entity_data);
	void add_entity_data(const Ref<EntityData> entity_data);
	void remove_entity_data(const int index);
	int get_entity_data_count() const;

	Vector<Variant> get_entity_datas();
	void set_entity_datas(const Vector<Variant> &entity_datas);
#endif

	Ref<DungeonRoom> instance(const int seed);
	virtual Ref<DungeonRoom> _instance(const int seed, Ref<DungeonRoom> inst);

	void setup();

#ifdef VOXELMAN_PRESENT
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);

	//Structure
	Ref<VoxelStructure> get_structure();
	void set_structure(Ref<VoxelStructure> structure);

	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);
	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);

	//Surfaces
	Ref<VoxelSurface> get_voxel_surface(const int index) const;
	void set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface);
	void add_voxel_surface(const Ref<VoxelSurface> voxel_surface);
	void remove_voxel_surface(const int index);
	int get_voxel_surface_count() const;

	Vector<Variant> get_voxel_surfaces();
	void set_voxel_surfaces(const Vector<Variant> &voxel_surfaces);

	void setup_library(Ref<VoxelmanLibrary> library);
	void _setup_library(Ref<VoxelmanLibrary> library);

	void generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs);
	void generate_room(Ref<VoxelStructure> structure, bool spawn_mobs);
#endif

	DungeonRoom();
	~DungeonRoom();

protected:
	static void _bind_methods();

private:
	int _current_seed;

	Vector2 _level_range;

	int _min_sizex;
	int _min_sizey;
	int _min_sizez;

	int _max_sizex;
	int _max_sizey;
	int _max_sizez;

	int _posx;
	int _posy;
	int _posz;

	int _sizex;
	int _sizey;
	int _sizez;

	Vector<Ref<WorldGeneratorPropData> > _prop_datas;

#ifdef ESS_PRESENT
	Vector<Ref<EntityData> > _entity_datas;
#endif

#ifdef VOXELMAN_PRESENT
	Ref<EnvironmentData> _environment;
	Ref<VoxelStructure> _structure;

	Vector<Ref<EnvironmentData> > _environment_datas;
	Vector<Ref<VoxelSurface> > _voxel_surfaces;
#endif
};

#endif
