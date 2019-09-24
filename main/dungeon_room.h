#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "core/reference.h"

#include "../../voxelman/world/voxel_structure.h"

class DungeonRoom : public Reference {
	GDCLASS(DungeonRoom, Reference);
	
public:

	void generate_room(Ref<VoxelStructure> structure);

	DungeonRoom();
	~DungeonRoom();

protected:
	static void _bind_methods();

private:

	//Vector<Ref<VoxelmanProp> > _props;
};

#endif
