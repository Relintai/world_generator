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

#include "core/reference.h"
#include "core/vector.h"

#include "../data/dungeon_room_data.h"
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

class DungeonRoomData;

class DungeonRoom : public Reference {
	GDCLASS(DungeonRoom, Reference);

public:
	int get_current_seed();
	void set_current_seed(int value);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

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

#ifdef VOXELMAN_PRESENT
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);
#endif

	Ref<DungeonRoomData> get_data();
	void set_data(Ref<DungeonRoomData> value);

#ifdef VOXELMAN_PRESENT
	//Structure
	Ref<VoxelStructure> get_structure();
	void set_structure(Ref<VoxelStructure> structure);
#endif

	//Props
	Ref<WorldGeneratorPropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<WorldGeneratorPropData> prop_data);
	void add_prop_data(const Ref<WorldGeneratorPropData> prop_data);
	void remove_prop_data(const int index);
	int get_prop_data_count() const;

#ifdef ESS_PRESENT
	//Entities
	Ref<EntityData> get_entity_data(const int index) const;
	void set_entity_data(const int index, const Ref<EntityData> entity_data);
	void add_entity_data(const Ref<EntityData> entity_data);
	void remove_entity_data(const int index);
	int get_entity_data_count() const;
#endif

	void setup();

#ifdef VOXELMAN_PRESENT
	void setup_library(Ref<VoxelmanLibrary> library);
	void _setup_library(Ref<VoxelmanLibrary> library);

	void generate_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs);
	void generate_room(Ref<VoxelStructure> structure, bool spawn_mobs);
#else
	void setup_library(Ref<Resource> library);
	void generate_chunk(Ref<Resource> chunk, bool spawn_mobs);
#endif

	DungeonRoom();
	~DungeonRoom();

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

#ifdef VOXELMAN_PRESENT
	Ref<EnvironmentData> _environment;
	Ref<VoxelStructure> _structure;
#endif

	Ref<DungeonRoomData> _data;
	Vector<Ref<WorldGeneratorPropData> > _prop_datas;

#ifdef ESS_PRESENT
	Vector<Ref<EntityData> > _entity_datas;
#endif
};

#endif
