#ifndef BIOME_DATA_H
#define BIOME_DATA_H

#include "core/resource.h"

#include "../main/biome.h"

class BiomeData : public Resource {
	GDCLASS(BiomeData, Resource);
	
public:

	Ref<Biome> setup_biome(int seed);

	BiomeData();
	~BiomeData();

protected:
	static void _bind_methods();

private:

	//Vector2 _humidity_range;
	//Vector2 _temperature_range;
	//Vector<DungeonData> _dungeon_datas;
	//Vector<Ref<VoxelmanProp> > _props;
};

#endif
