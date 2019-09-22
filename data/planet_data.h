#ifndef VOXELMAN_PROP_DATA_H
#define VOXELMAN_PROP_DATA_H

#include "core/resource.h"
#include "core/math/transform.h"

class PlanetData : public Resource {
	GDCLASS(PlanetData, Resource);
	
public:
	Ref<PlanetData> get_planet_data(const int index) const;
	void set_planet_data(const int index, const Ref<PlanetData> planet_data);
	void add_planet_data(const Ref<PlanetData> planet_data);
	void remove_planet_data(const int index);

	int get_planet_data_count() const;

	Vector<Variant> get_planet_datas();
	void set_planet_datas(const Vector<Variant> &planet_datas);

	Ref<Planet> setup_planet(int seed);

	PlanetData();
	~PlanetData();

protected:
	static void _bind_methods();

private:

	int _id;
	Vector<BiomeData> _biome_datas;
	Ref<NoiseParams> _humidity_noise_params;
	Ref<NoiseParams> _temperature_noise_params;
};

#endif
