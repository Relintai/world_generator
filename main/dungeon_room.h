#ifndef VOXELMAN_PROP_DATA_H
#define VOXELMAN_PROP_DATA_H

#include "core/resource.h"
#include "core/math/transform.h"

class VoxelmanPropEntry : public Resource {
	GDCLASS(VoxelmanPropEntry, Resource);
	
public:

	void write_room(Ref<VoxelmanStructure> structure, Vector3i position, Vector3i size);
	void generate_room(Ref<VoxelmanStructure> structure);

	VoxelmanPropEntry();
	~VoxelmanPropEntry();

protected:
	static void _bind_methods();

private:

	Vector<Ref<VoxelmanProp> > _props;
};

#endif
