#ifndef DUNGEON_ROOM_DATA_H
#define DUNGEON_ROOM_DATA_H

#include "core/resource.h"

#include "../main/dungeon_room.h"

class DungeonRoomData : public Resource {
	GDCLASS(DungeonRoomData, Resource);
	
public:

	Ref<DungeonRoom> setup_room(int seed);

	DungeonRoomData();
	~DungeonRoomData();

protected:
	static void _bind_methods();

private:
	//Vector<VoxelmanProp> _props;
};

#endif
