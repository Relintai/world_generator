#ifndef VOXELMAN_PROP_DATA_H
#define VOXELMAN_PROP_DATA_H

#include "core/resource.h"
#include "core/math/transform.h"

class VoxelmanPropEntry : public Resource {
	GDCLASS(VoxelmanPropEntry, Resource);
	
public:

	Ref<VoxelmanStructure> generate_dungeon();

	VoxelmanPropEntry();
	~VoxelmanPropEntry();

protected:
	static void _bind_methods();

private:

	Vector<Ref<DungeonRoopm> > _rooms;
};

#endif
