#ifndef BIOME_H
#define BIOME_H

#include "core/resource.h"

#include "../../voxelman/world/voxel_chunk.h"
#include "../data/prop_data.h"
#include "dungeon.h"


class Biome : public Resource {
	GDCLASS(Biome, Resource);
	
public:
	//PropData
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	//Dungeons
	Ref<Dungeon> get_dungeon(const int index) const;
	void set_dungeon(const int index, const Ref<Dungeon> dungeon);
	void add_dungeon(const Ref<Dungeon> dungeon);
	void remove_dungeon(const int index);

	int get_dungeon_count() const;

	void generate_chunk(Ref<VoxelChunk> chunk);
	void generate_stack(Ref<VoxelChunk> chunk, int x, int z);

	Biome();
	~Biome();

protected:
	static void _bind_methods();

private:
	Vector<Ref<PropData> > _prop_datas;
	Vector<Ref<Dungeon> > _dungeons;
};

#endif
