#ifndef DUNGEON_H
#define DUNGEON_H

#include "core/resource.h"

#include "../../voxelman/world/voxel_structure.h"

class Dungeon : public Reference {
	GDCLASS(Dungeon, Reference);
	
public:

	void generate(Ref<VoxelStructure> structure);

	Dungeon();
	~Dungeon();

protected:
	static void _bind_methods();

private:

	//Vector<Ref<DungeonRoopm> > _rooms;
};

#endif
