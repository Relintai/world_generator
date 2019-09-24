#ifndef DUNGEON_DATA_H
#define DUNGEON_DATA_H

#include "core/resource.h"
#include "core/vector.h"

#include "../main/dungeon.h"
#include "dungeon_room_data.h"

class DungeonData : public Resource {
	GDCLASS(DungeonData, Resource);
	
public:
	Ref<DungeonRoomData> get_dungeon_room_data(const int index) const;
	void set_dungeon_room_data(const int index, const Ref<DungeonRoomData> dungeon_room_data);
	void add_dungeon_room_data(const Ref<DungeonRoomData> dungeon_room_data);
	void remove_dungeon_room_data(const int index);

	int get_dungeon_room_data_count() const;

	Vector<Variant> get_dungeon_room_datas();
	void set_dungeon_room_datas(const Vector<Variant> &dungeon_room_datas);

	Ref<Dungeon> setup_dungeon(int seed);

	DungeonData();
	~DungeonData();

protected:
	static void _bind_methods();

private:
	Vector<Ref<DungeonRoomData> > _dungeon_room_datas;
};

#endif
