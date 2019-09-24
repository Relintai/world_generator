#ifndef BIOME_H
#define BIOME_H

#include "core/resource.h"

#include "../../voxelman/world/voxel_chunk.h"

class Biome : public Resource {
	GDCLASS(Biome, Resource);
	
public:
	void generate_chunk(Ref<VoxelChunk> chunk);
	void generate_stack(Ref<VoxelChunk> chunk, int x, int z);

	Biome();
	~Biome();

protected:
	static void _bind_methods();

private:
	//Vector<Ref<VoxelmanProp> > _props;
	//Vector<Ref<Dungeon> > _dungeons;
};

#endif
