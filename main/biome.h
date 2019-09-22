#ifndef VOXELMAN_PROP_DATA_H
#define VOXELMAN_PROP_DATA_H

#include "core/resource.h"
#include "core/math/transform.h"

class VoxelmanPropEntry : public Resource {
	GDCLASS(VoxelmanPropEntry, Resource);
	
public:

	void generate_chunk(Ref<VoxelChunk> chunk);
	void generate_stack(int x, int z, Ref<VoxelChunk> chunk);

	VoxelmanPropEntry();
	~VoxelmanPropEntry();

protected:
	static void _bind_methods();

private:

	Vector<Ref<VoxelmanProp> > _props;
	Vector<Ref<Dungeon> > _dungeons;
};

#endif
