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

#include "../data/planet_data.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxel_surface.h"
#include "../../voxelman/library/voxelman_library.h"
#include "../../voxelman/world/environment_data.h"
#include "../../voxelman/world/voxel_chunk.h"
#endif

class PlanetData;

class Planet : public Resource {
	GDCLASS(Planet, Resource);

public:
	int get_current_seed();
	void set_current_seed(int value);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

#ifdef VOXELMAN_PRESENT
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);
#endif

	Ref<PlanetData> get_data();
	void set_data(Ref<PlanetData> value);

	//Biomes
	Ref<Biome> get_biome(const int index) const;
	void set_biome(const int index, const Ref<Biome> biome);
	void add_biome(const Ref<Biome> biome);
	void remove_biome(const int index);
	int get_biome_count() const;

	//Dungeons
	Ref<Dungeon> get_dungeon(const int index) const;
	void set_dungeon(const int index, const Ref<Dungeon> dungeon);
	void add_dungeon(const Ref<Dungeon> dungeon);
	void remove_dungeon(const int index);
	int get_dungeon_count() const;

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
	int _current_seed;
	Vector2 _level_range;

#ifdef VOXELMAN_PRESENT
	Ref<EnvironmentData> _environment;
#endif

	Ref<PlanetData> _data;
	Vector<Ref<Biome> > _biomes;
	Vector<Ref<Dungeon> > _dungeons;
};

#endif
