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

#ifndef BIOME_H
#define BIOME_H

#include "core/version.h"

#if VERSION_MAJOR > 3
#include "core/io/resource.h"
#include "core/object/reference.h"
#else
#include "core/reference.h"
#include "core/resource.h"
#endif

#include "building.h"

#include "../data/world_generator_prop_data.h"
#include "scene/resources/packed_scene.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxelman_library.h"
#include "../../voxelman/world/environment_data.h"
#include "../../voxelman/world/voxel_chunk.h"
#endif

#ifdef TERRAMAN_PRESENT
#include "../../terraman/library/terraman_library.h"
#include "../../terraman/world/terra_environment_data.h"
#include "../../terraman/world/terra_chunk.h"
#endif

#ifdef ESS_PRESENT
#include "../../entity_spell_system/entities/data/entity_data.h"
#endif

class Biome : public Resource {
	GDCLASS(Biome, Resource);

public:
	int get_current_seed();
	void set_current_seed(int value);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

	Vector2 get_humidity_range();
	void set_humidity_range(Vector2 range);

	Vector2 get_temperature_range();
	void set_temperature_range(Vector2 range);

	//WorldGeneratorPropData
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

	//Buildings
	Ref<Building> get_building(const int index) const;
	void set_building(const int index, const Ref<Building> building);
	void add_building(const Ref<Building> building);
	void remove_building(const int index);
	int get_building_count() const;

	Vector<Variant> get_buildings();
	void set_buildings(const Vector<Variant> &buildings);

	Ref<Biome> instance(const int seed);
	virtual Ref<Biome> _instance(const int seed, Ref<Biome> inst);

	void setup();

#ifdef VOXELMAN_PRESENT
	//Environment
	Ref<EnvironmentData> get_voxel_environment();
	void set_voxel_environment(Ref<EnvironmentData> value);

	//Environments
	Ref<EnvironmentData> get_voxel_environment_data(const int index) const;
	void set_voxel_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_voxel_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_voxel_environment_data(const int index);
	int get_voxel_environment_data_count() const;

	Vector<Variant> get_voxel_environment_datas();
	void set_voxel_environment_datas(const Vector<Variant> &environment_datas);

	//Surfaces
	Ref<VoxelSurface> get_voxel_surface(const int index) const;
	void set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface);
	void add_voxel_surface(const Ref<VoxelSurface> voxel_surface);
	void remove_voxel_surface(const int index);
	int get_voxel_surface_count() const;

	Vector<Variant> get_voxel_surfaces();
	void set_voxel_surfaces(const Vector<Variant> &voxel_surfaces);

	void generate_voxel_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs);
	void generate_voxel_stack(Ref<VoxelChunk> chunk, int x, int z, bool spawn_mobs);

	void setup_voxel_library(Ref<VoxelmanLibrary> library);
	void _setup_voxel_library(Ref<VoxelmanLibrary> library);
#endif

#ifdef TERRAMAN_PRESENT
	//Environment
	Ref<TerraEnvironmentData> get_terra_environment();
	void set_terra_environment(Ref<TerraEnvironmentData> value);

	//Environments
	Ref<TerraEnvironmentData> get_terra_environment_data(const int index) const;
	void set_terra_environment_data(const int index, const Ref<TerraEnvironmentData> environment_data);
	void add_terra_environment_data(const Ref<TerraEnvironmentData> environment_data);
	void remove_terra_environment_data(const int index);
	int get_terra_environment_data_count() const;

	Vector<Variant> get_terra_environment_datas();
	void set_terra_environment_datas(const Vector<Variant> &environment_datas);

	//Surfaces
	Ref<TerraSurface> get_terra_surface(const int index) const;
	void set_terra_surface(const int index, const Ref<TerraSurface> terra_surface);
	void add_terra_surface(const Ref<TerraSurface> terra_surface);
	void remove_terra_surface(const int index);
	int get_terra_surface_count() const;

	Vector<Variant> get_terra_surfaces();
	void set_terra_surfaces(const Vector<Variant> &terra_surfaces);

	void generate_terra_chunk(Ref<TerraChunk> chunk, bool spawn_mobs);
	void generate_terra_stack(Ref<TerraChunk> chunk, int x, int z, bool spawn_mobs);

	void setup_terra_library(Ref<TerramanLibrary> library);
	void _setup_terra_library(Ref<TerramanLibrary> library);
#endif

	Biome();
	~Biome();

protected:
	static void _bind_methods();

private:
	int _current_seed;

	Vector2 _level_range;

	Vector2 _humidity_range;
	Vector2 _temperature_range;

	Vector<Ref<WorldGeneratorPropData> > _prop_datas;

#ifdef ESS_PRESENT
	Vector<Ref<EntityData> > _entity_datas;
#endif

	Vector<Ref<Building> > _buildings;

#ifdef VOXELMAN_PRESENT
	Ref<EnvironmentData> _voxel_environment;

	Vector<Ref<EnvironmentData> > _voxel_environment_datas;
	Vector<Ref<VoxelSurface> > _voxel_surfaces;
#endif

#ifdef TERRAMAN_PRESENT
	Ref<TerraEnvironmentData> _terra_environment;

	Vector<Ref<TerraEnvironmentData> > _terra_environment_datas;
	Vector<Ref<TerraSurface> > _terra_surfaces;
#endif
};

#endif
