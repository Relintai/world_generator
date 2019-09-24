#ifndef DUNGEON_ROOM_DATA_H
#define DUNGEON_ROOM_DATA_H

#include "core/resource.h"

#include "../main/dungeon_room.h"
#include "prop_data.h"

class DungeonRoomData : public Resource {
	GDCLASS(DungeonRoomData, Resource);
	
public:
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	Vector<Variant> get_prop_datas();
	void set_prop_datas(const Vector<Variant> &prop_datas);

	Ref<DungeonRoom> setup_room(int seed);

	DungeonRoomData();
	~DungeonRoomData();

protected:
	static void _bind_methods();

private:
	Vector<Ref<PropData> > _prop_datas;
};

#endif
