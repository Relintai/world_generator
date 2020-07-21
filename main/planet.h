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

#ifndef PLANET_H
#define PLANET_H

#include "core/image.h"
#include "core/reference.h"
#include "core/resource.h"

#include "biome.h"
#include "dungeon.h"

#ifdef FASTNOISE_PRESENT
#include "../../fastnoise/fastnoise_noise_params.h"
#endif

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxel_surface.h"
#include "../../voxelman/library/voxelman_library.h"
#include "../../voxelman/world/environment_data.h"
#include "../../voxelman/world/voxel_chunk.h"
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

#ifdef VOXELMAN_PRESENT
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);
#endif

	//Biomes
	Ref<Biome> get_biome(const int index) const;
	void set_biome(const int index, const Ref<Biome> biome);
	void add_biome(const Ref<Biome> biome);
	void remove_biome(const int index);
	int get_biome_count() const;

	Vector<Variant> get_biomes();
	void set_biomes(const Vector<Variant> &biome_datas);

	//Dungeons
	Ref<Dungeon> get_dungeon(const int index) const;
	void set_dungeon(const int index, const Ref<Dungeon> dungeon);
	void add_dungeon(const Ref<Dungeon> dungeon);
	void remove_dungeon(const int index);
	int get_dungeon_count() const;

#ifdef VOXELMAN_PRESENT
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

#endif

	Ref<Planet> instance(const int seed);
	virtual Ref<Planet> _instance(const int seed, Ref<Planet> planet);

	void setup();

#ifdef VOXELMAN_PRESENT
	void setup_library(Ref<VoxelmanLibrary> library);
	void _setup_library(Ref<VoxelmanLibrary> library);

	void generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs);
#else
	void generate_chunk(Ref<Resource> chunk, bool spawn_mobs);
	void setup_library(Ref<Resource> library);
#endif

	Ref<Image> generate_map();

	Planet();
	~Planet();

protected:
	static void _bind_methods();

private:
	int _id;

	int _current_seed;
	Vector2 _level_range;

#ifdef VOXELMAN_PRESENT
	Ref<EnvironmentData> _environment;
#endif

	Vector<Ref<Biome> > _biomes;
	Vector<Ref<Dungeon> > _dungeons;

#ifdef FASTNOISE_PRESENT
	Ref<FastnoiseNoiseParams> _humidity_noise_params;
	Ref<FastnoiseNoiseParams> _temperature_noise_params;
#endif

#ifdef VOXELMAN_PRESENT
	Vector<Ref<EnvironmentData> > _environment_datas;
	Vector<Ref<VoxelSurface> > _voxel_surfaces;
#endif
};

#endif
