#ifndef PROP_DATA_H
#define PROP_DATA_H

#include "core/resource.h"

#include "../../voxelman/props/voxelman_prop.h"

class PropData : public Resource {
	GDCLASS(PropData, Resource);
	
public:

	bool can_spawn(int seed);
	Ref<VoxelmanProp> get_prop(int seed);

	PropData();
	~PropData();

protected:
	static void _bind_methods();

};

#endif
