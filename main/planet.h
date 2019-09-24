#ifndef PLANET_H
#define PLANET_H

#include "core/resource.h"

#include "../../voxelman/world/voxel_chunk.h"
#include "biome.h"

class Planet : public Resource {
	GDCLASS(Planet, Resource);
	
public:
	Ref<Biome> get_biome(const int index) const;
	void set_biome(const int index, const Ref<Biome> biome);
	void add_biome(const Ref<Biome> biome);
	void remove_biome(const int index);

	int get_biome_count() const;

	void generate_chunk(Ref<VoxelChunk> chunk);

	Planet();
	~Planet();

protected:
	static void _bind_methods();

private:
	Vector<Ref<Biome> > _biomes;
};

#endif
