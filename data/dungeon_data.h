#ifndef DUNGEON_DATA_H
#define DUNGEON_DATA_H

#include "core/resource.h"

#include "../main/dungeon.h"

class DungeonData : public Resource {
	GDCLASS(DungeonData, Resource);
	
public:
	Ref<Dungeon> setup_dungeon(int seed);

	DungeonData();
	~DungeonData();

protected:
	static void _bind_methods();

private:
	//Vector<Ref<DungeonRoomData> > _rooms;
};

#endif
