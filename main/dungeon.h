#ifndef DUNGEON_H
#define DUNGEON_H

#include "core/resource.h"

#include "dungeon_room.h"
#include "../../voxelman/world/voxel_structure.h"

class Dungeon : public Reference {
	GDCLASS(Dungeon, Reference);
	
public:
	Ref<DungeonRoom> get_dungeon_room(const int index) const;
	void set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room);
	void add_dungeon_room(const Ref<DungeonRoom> dungeon_room);
	void remove_dungeon_room(const int index);

	int get_dungeon_room_count() const;

	void generate(Ref<VoxelStructure> structure);

	Dungeon();
	~Dungeon();

protected:
	static void _bind_methods();

private:

	Vector<Ref<DungeonRoom> > _dungeon_rooms;
};

#endif
