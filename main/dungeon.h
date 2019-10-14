#ifndef DUNGEON_H
#define DUNGEON_H

#include "core/reference.h"

#include "dungeon_room.h"

#include "../../voxelman/world/voxel_chunk.h"
#include "../../voxelman/world/voxel_structure.h"
#include "../../voxelman/world/environment_data.h"

class Dungeon : public Reference {
	GDCLASS(Dungeon, Reference);
	
public:
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);

	Ref<DungeonRoom> get_dungeon_room(const int index) const;
	void set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room);
	void add_dungeon_room(const Ref<DungeonRoom> dungeon_room);
	void remove_dungeon_room(const int index);

	int get_dungeon_room_count() const;

	void generate_chunk(Ref<VoxelChunk> chunk);
	void generate_structure(Ref<VoxelStructure> structure);

	Ref<Image> generate_map();

	Dungeon();
	~Dungeon();

protected:
	static void _bind_methods();

private:
	Ref<EnvironmentData> _environment;
	Vector<Ref<DungeonRoom> > _dungeon_rooms;
};

#endif
