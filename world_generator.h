/*
Copyright (c) 2019-2020 Péter Magyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef WORLD_GENERATOR_H
#define WORLD_GENERATOR_H

#include "core/resource.h"
#include "core/vector.h"

#include "data/planet_data.h"

#include "main/planet.h"

class WorldGenerator : public Resource {
	GDCLASS(WorldGenerator, Resource);

public:
	Ref<PlanetData> get_planet_data(const int index) const;
	void set_planet_data(const int index, const Ref<PlanetData> planet_data);
	void add_planet_data(const Ref<PlanetData> planet_data);
	void remove_planet_data(const int index);

	int get_planet_data_count() const;

	Vector<Variant> get_planet_datas();
	void set_planet_datas(const Vector<Variant> &planet_datas);

	Ref<Planet> setup_planet(int seed);

	WorldGenerator();
	~WorldGenerator();

protected:
	static void _bind_methods();

private:
	Vector<Ref<PlanetData> > _planet_datas;
};

#endif
