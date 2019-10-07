#ifndef DUNGEON_ROOM_DATA_H
#define DUNGEON_ROOM_DATA_H

#include "core/resource.h"

#include "../main/dungeon_room.h"
#include "prop_data.h"
#include "../../voxelman/world/environment_data.h"

class DungeonRoomData : public Resource {
	GDCLASS(DungeonRoomData, Resource);
	
public:
	//Prop Data
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	Vector<Variant> get_prop_datas();
	void set_prop_datas(const Vector<Variant> &prop_datas);

	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);

	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);

	Ref<DungeonRoom> setup_room(int seed);

	DungeonRoomData();
	~DungeonRoomData();

protected:
	static void _bind_methods();

private:
	Vector<Ref<PropData> > _prop_datas;
	Vector<Ref<EnvironmentData> > _environment_datas;
};

#endif
