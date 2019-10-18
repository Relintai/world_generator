#ifndef DUNGEON_ROOM_H
#define DUNGEON_ROOM_H

#include "core/reference.h"
#include "core/vector.h"

#include "../../voxelman/world/voxel_chunk.h"
#include "../../voxelman/world/voxel_structure.h"
#include "../data/prop_data.h"
#include "../../voxelman/world/environment_data.h"

class DungeonRoom : public Reference {
	GDCLASS(DungeonRoom, Reference);
	
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

	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	void generate_chunk(Ref<VoxelChunk> chunk);
	void generate_room(Ref<VoxelStructure> structure);

	DungeonRoom();
	~DungeonRoom();

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
	Vector<Ref<PropData> > _prop_datas;
};

#endif
