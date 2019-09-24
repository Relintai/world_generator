#ifndef PLANET_H
#define PLANET_H

#include "core/resource.h"

#include "../../voxelman/world/voxel_chunk.h"

class Planet : public Resource {
	GDCLASS(Planet, Resource);
	
public:
	void generate_chunk(Ref<VoxelChunk> chunk);

	Planet();
	~Planet();

protected:
	static void _bind_methods();

private:
	//Vector<Ref<Biome> > _biomes;
};

#endif
