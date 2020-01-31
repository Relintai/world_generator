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

#ifndef dungeon_data_H
#define dungeon_data_H

#include "core/math/vector2.h"
#include "core/resource.h"
#include "core/script_language.h"
#include "core/ustring.h"
#include "core/vector.h"

#include "../main/biome.h"
#include "dungeon_data.h"
#include "world_generator_prop_data.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxel_surface.h"
#include "../../voxelman/world/environment_data.h"
#endif

#ifdef ESS_PRESENT
#include "../../entity_spell_system/entities/data/entity_data.h"
#endif

class BiomeData : public Resource {
	GDCLASS(BiomeData, Resource);

public:
	String get_target_class_name();
	void set_target_class_name(String name);

	Ref<Script> get_target_script();
	void set_target_script(Ref<Script> script);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

	Vector2 get_humidity_range();
	void set_humidity_range(Vector2 range);

	Vector2 get_temperature_range();
	void set_temperature_range(Vector2 range);

	//DungeonData
	Ref<DungeonData> get_dungeon_data(const int index) const;
	void set_dungeon_data(const int index, const Ref<DungeonData> dungeon_data);
	void add_dungeon_data(const Ref<DungeonData> dungeon_data);
	void remove_dungeon_data(const int index);

	int get_dungeon_data_count() const;

	Vector<Variant> get_dungeon_datas();
	void set_dungeon_datas(const Vector<Variant> &dungeon_datas);

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

	//Liquid Surfaces
	Ref<VoxelSurface> get_liquid_voxel_surface(const int index) const;
	void set_liquid_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface);
	void add_liquid_voxel_surface(const Ref<VoxelSurface> voxel_surface);
	void remove_liquid_voxel_surface(const int index);
	int get_liquid_voxel_surface_count() const;

	Vector<Variant> get_liquid_voxel_surfaces();
	void set_liquid_voxel_surfaces(const Vector<Variant> &voxel_surfaces);
#endif

	BiomeData();
	~BiomeData();

protected:
	static void _bind_methods();

private:
	String _target_class_name;
	Ref<Script> _target_script;

	Vector2 _level_range;

	Vector2 _humidity_range;
	Vector2 _temperature_range;

	Vector<Ref<DungeonData> > _dungeon_datas;
	Vector<Ref<WorldGeneratorPropData> > _prop_datas;

#ifdef ESS_PRESENT
	Vector<Ref<EntityData> > _entity_datas;
#endif

#ifdef VOXELMAN_PRESENT
	Vector<Ref<EnvironmentData> > _environment_datas;
	Vector<Ref<VoxelSurface> > _voxel_surfaces;
	Vector<Ref<VoxelSurface> > _liquid_voxel_surfaces;
#endif
};

#endif
