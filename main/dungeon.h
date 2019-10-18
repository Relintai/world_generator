#ifndef DUNGEON_H
#define DUNGEON_H

#include "core/reference.h"

#include "dungeon_room.h"
#include "dungeon_corridor.h"

#include "../../voxelman/world/voxel_chunk.h"
#include "../../voxelman/world/voxel_structure.h"
#include "../../voxelman/world/environment_data.h"

class Dungeon : public Reference {
	GDCLASS(Dungeon, Reference);
	
public:
	int get_seed();
	void set_seed(int value);

	int get_posx();
	void set_posx(int value);

	int get_posy();
	void set_posy(int value);

	int get_posz();
	void set_posz(int value);

	int get_sizex();
	void set_sizex(int value);

	int get_sizey();
	void set_sizey(int value);

	int get_sizez();
	void set_sizez(int value);

	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);

	//Rooms
	Ref<DungeonRoom> get_dungeon_room(const int index) const;
	void set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room);
	void add_dungeon_room(const Ref<DungeonRoom> dungeon_room);
	void remove_dungeon_room(const int index);

	int get_dungeon_room_count() const;

	//Start Rooms
	Ref<DungeonRoom> get_dungeon_start_room(const int index) const;
	void set_dungeon_start_room(const int index, const Ref<DungeonRoom> dungeon_start_room);
	void add_dungeon_start_room(const Ref<DungeonRoom> dungeon_start_room);
	void remove_dungeon_start_room(const int index);

	int get_dungeon_start_room_count() const;

	//End Rooms
	Ref<DungeonRoom> get_dungeon_end_room(const int index) const;
	void set_dungeon_end_room(const int index, const Ref<DungeonRoom> dungeon_end_room);
	void add_dungeon_end_room(const Ref<DungeonRoom> dungeon_end_room);
	void remove_dungeon_end_room(const int index);

	int get_dungeon_end_room_count() const;

	//Corridors
	Ref<DungeonCorridor> get_dungeon_corridor(const int index) const;
	void set_dungeon_corridor(const int index, const Ref<DungeonCorridor> dungeon_corridors);
	void add_dungeon_corridor(const Ref<DungeonCorridor> dungeon_corridors);
	void remove_dungeon_corridor(const int index);

	int get_dungeon_corridor_count() const;

	void setup();
	void generate_chunk(Ref<VoxelChunk> chunk);
	void generate_structure(Ref<VoxelStructure> structure);

	Ref<Image> generate_map();

	Dungeon();
	~Dungeon();

protected:
	static void _bind_methods();

private:
	int _seed;

	int _posx;
	int _posy;
	int _posz;

	int _sizex;
	int _sizey;
	int _sizez;

	Ref<EnvironmentData> _environment;
	Vector<Ref<DungeonRoom> > _dungeon_rooms;
	Vector<Ref<DungeonRoom> > _dungeon_start_rooms;
	Vector<Ref<DungeonRoom> > _dungeon_end_rooms;
	Vector<Ref<DungeonCorridor> > _dungeon_corridors;
};

#endif
