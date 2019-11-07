#ifndef PROP_DATA_H
#define PROP_DATA_H

#include "core/resource.h"

#include "../../voxelman/props/voxelman_prop.h"

class WorldGeneratorPropData : public Resource {
	GDCLASS(WorldGeneratorPropData, Resource);
	
public:

	bool can_spawn(int seed);
	Ref<VoxelmanProp> get_prop(int seed);

	WorldGeneratorPropData();
	~WorldGeneratorPropData();

protected:
	static void _bind_methods();

};

#endif
