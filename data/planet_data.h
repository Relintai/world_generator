#ifndef biome_data_H
#define biome_data_H

#include "core/resource.h"

#include "../../fastnoise/fastnoise_noise_params.h"

#include "../main/planet.h"
#include "../data/biome_data.h"

class PlanetData : public Resource {
	GDCLASS(PlanetData, Resource);
	
public:
	int get_id() const;
	void set_id(const int value);

	Ref<FastnoiseNoiseParams> get_humidity_noise_params();
	void set_humidity_noise_params(Ref<FastnoiseNoiseParams> value);

	Ref<FastnoiseNoiseParams> get_temperature_noise_params();
	void set_temperature_noise_params(Ref<FastnoiseNoiseParams> value);

	Ref<BiomeData> get_biome_data(const int index) const;
	void set_biome_data(const int index, const Ref<BiomeData> biome_data);
	void add_biome_data(const Ref<BiomeData> biome_data);
	void remove_biome_data(const int index);

	int get_biome_data_count() const;

	Vector<Variant> get_biome_datas();
	void set_biome_datas(const Vector<Variant> &biome_datas);

	Ref<Planet> setup_planet(int seed);

	PlanetData();
	~PlanetData();

protected:
	static void _bind_methods();

private:

	int _id;
	Ref<FastnoiseNoiseParams> _humidity_noise_params;
	Ref<FastnoiseNoiseParams> _temperature_noise_params;
	Vector<Ref<BiomeData> > _biome_datas;
};

#endif
