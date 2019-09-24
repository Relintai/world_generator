#ifndef dungeon_data_H
#define dungeon_data_H

#include "core/resource.h"
#include "core/vector.h"
#include "core/math/vector2.h"

#include "../main/biome.h"
#include "dungeon_data.h"
#include "prop_data.h"

class BiomeData : public Resource {
	GDCLASS(BiomeData, Resource);
	
public:
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

	//PropData
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	Vector<Variant> get_prop_datas();
	void set_prop_datas(const Vector<Variant> &prop_datas);

	Ref<Biome> setup_biome(int seed);

	BiomeData();
	~BiomeData();

protected:
	static void _bind_methods();

private:

	Vector2 _humidity_range;
	Vector2 _temperature_range;
	Vector<Ref<DungeonData> > _dungeon_datas;
	Vector<Ref<PropData> > _prop_datas;
};

#endif
