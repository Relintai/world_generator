#ifndef WORLD_GENERATOR_PROP_DATA_H
#define WORLD_GENERATOR_PROP_DATA_H

#include "core/resource.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/props/prop_data.h"
#endif

class WorldGeneratorPropData : public Resource {
	GDCLASS(WorldGeneratorPropData, Resource);
	
public:

	bool can_spawn(int seed);
	
	#ifdef VOXELMAN_PRESENT
	Ref<PropData> get_prop(int seed);
	#else
	Ref<Resource> get_prop(int seed);
	#endif

	WorldGeneratorPropData();
	~WorldGeneratorPropData();

protected:
	static void _bind_methods();

};

#endif
