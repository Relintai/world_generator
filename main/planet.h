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

#ifndef PLANET_H
#define PLANET_H

#include "core/version.h"

#if VERSION_MAJOR > 3
#include "core/io/image.h"
#include "core/io/resource.h"
#include "core/object/ref_counted.h"
#else
#include "core/image.h"
#include "core/reference.h"
#include "core/resource.h"
#endif

#include "biome.h"
#include "building.h"

#ifdef FASTNOISE_PRESENT
#include "../../fastnoise/fastnoise_noise_params.h"
#endif

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxel_surface.h"
#include "../../voxelman/library/voxelman_library.h"
#include "../../voxelman/world/environment_data.h"
#include "../../voxelman/world/voxel_chunk.h"
#endif

#ifdef TERRAMAN_PRESENT
#include "../../terraman/library/terra_surface.h"
#include "../../terraman/library/terraman_library.h"
#include "../../terraman/world/terra_environment_data.h"
#include "../../terraman/world/terra_chunk.h"
#endif

class Planet : public Resource {
	GDCLASS(Planet, Resource);

public:
	int get_id() const;
	void set_id(const int value);

	int get_current_seed();
	void set_current_seed(int value);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

#ifdef FASTNOISE_PRESENT
	Ref<FastnoiseNoiseParams> get_humidity_noise_params();
	void set_humidity_noise_params(Ref<FastnoiseNoiseParams> value);

	Ref<FastnoiseNoiseParams> get_temperature_noise_params();
	void set_temperature_noise_params(Ref<FastnoiseNoiseParams> value);
#endif

	//Biomes
	Ref<Biome> get_biome(const int index) const;
	void set_biome(const int index, const Ref<Biome> biome);
	void add_biome(const Ref<Biome> biome);
	void remove_biome(const int index);
	int get_biome_count() const;

	Vector<Variant> get_biomes();
	void set_biomes(const Vector<Variant> &biome_datas);

	//Building
	Ref<Building> get_building(const int index) const;
	void set_building(const int index, const Ref<Building> building);
	void add_building(const Ref<Building> building);
	void remove_building(const int index);
	int get_building_count() const;

	Vector<Variant> get_buildings();
	void set_buildings(const Vector<Variant> &buildings);

	Ref<Planet> instance(const int seed);
	virtual Ref<Planet> _instance(const int seed, Ref<Planet> inst);

	void setup();

	Ref<Image> generate_map();

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

	void setup_voxel_library(Ref<VoxelmanLibrary> library);
	void _setup_voxel_library(Ref<VoxelmanLibrary> library);

	void generate_voxel_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs);
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

	void setup_terra_library(Ref<TerramanLibrary> library);
	void _setup_terra_library(Ref<TerramanLibrary> library);

	void generate_terra_chunk(Ref<TerraChunk> chunk, bool spawn_mobs);
#endif

	Planet();
	~Planet();

protected:
	static void _bind_methods();

private:
	int _id;

	int _current_seed;
	Vector2 _level_range;

	Vector<Ref<Biome> > _biomes;
	Vector<Ref<Building> > _buildings;

#ifdef FASTNOISE_PRESENT
	Ref<FastnoiseNoiseParams> _humidity_noise_params;
	Ref<FastnoiseNoiseParams> _temperature_noise_params;
#endif

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
