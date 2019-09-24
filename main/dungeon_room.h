#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "core/reference.h"
#include "core/vector.h"

#include "../../voxelman/world/voxel_structure.h"
#include "../data/prop_data.h"

class DungeonRoom : public Reference {
	GDCLASS(DungeonRoom, Reference);
	
public:
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	void generate_room(Ref<VoxelStructure> structure);

	DungeonRoom();
	~DungeonRoom();

protected:
	static void _bind_methods();

private:

	Vector<Ref<PropData> > _prop_datas;
};

#endif
