#include "voxelman_prop_entry.h"

Transform PlanetData::get_transform() const {
	return _transform;
}
void PlanetData::set_transform(const Transform value) {
	_transform = value;
}

PlanetData::PlanetData() {

}
PlanetData::~PlanetData() {

}

void PlanetData::_bind_methods() {

}
