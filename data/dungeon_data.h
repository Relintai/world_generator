#ifndef VOXELMAN_PROP_DATA_H
#define VOXELMAN_PROP_DATA_H

#include "core/resource.h"
#include "core/math/transform.h"

class VoxelmanPropEntry : public Resource {
	GDCLASS(VoxelmanPropEntry, Resource);
	
public:

	Ref<Dungeon> setup_dungeon(int seed);

	VoxelmanPropEntry();
	~VoxelmanPropEntry();

protected:
	static void _bind_methods();

private:

	Vector<Ref<DungeonRoomData> > _rooms;
};

#endif
