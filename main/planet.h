#ifndef PLANET_H
#define PLANET_H

#include "core/reference.h"
#include "core/image.h"

#include "../../voxelman/world/voxel_chunk.h"
#include "biome.h"
#include "../../voxelman/world/environment_data.h"

class Planet : public Reference {
	GDCLASS(Planet, Reference);
	
public:
	//Environment
	Ref<EnvironmentData> get_environment();
	void set_environment(Ref<EnvironmentData> value);

	Ref<Biome> get_biome(const int index) const;
	void set_biome(const int index, const Ref<Biome> biome);
	void add_biome(const Ref<Biome> biome);
	void remove_biome(const int index);

	int get_biome_count() const;

	void generate_chunk(Ref<VoxelChunk> chunk);
	Ref<Image> generate_map();

	Planet();
	~Planet();

protected:
	static void _bind_methods();

private:
	Ref<EnvironmentData> _environment;
	Vector<Ref<Biome> > _biomes;
};

#endif
