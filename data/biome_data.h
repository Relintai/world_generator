#ifndef VOXELMAN_PROP_DATA_H
#define VOXELMAN_PROP_DATA_H

#include "core/resource.h"
#include "core/math/transform.h"

class VoxelmanPropEntry : public Resource {
	GDCLASS(VoxelmanPropEntry, Resource);
	
public:

	Ref<Biome> setup_biome();

	VoxelmanPropEntry();
	~VoxelmanPropEntry();

protected:
	static void _bind_methods();

private:

	Vector2 _humidity_range;
	Vector2 _temperature_range;
	Vector<DungeonData> _dungeon_datas;
	Vector<Ref<VoxelmanProp> > _props;
};

#endif
