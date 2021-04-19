/*
Copyright (c) 2019-2021 Péter Magyar

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

#ifndef WORLD_GENERATOR_PROP_DATA_H
#define WORLD_GENERATOR_PROP_DATA_H

#include "core/version.h"

#if VERSION_MAJOR > 3
#include "core/io/resource.h"
#else
#include "core/resource.h"
#endif

class PackedScene;

class WorldGeneratorPropData : public Resource {
	GDCLASS(WorldGeneratorPropData, Resource);

public:
	bool can_spawn(int seed);

	Ref<PackedScene> get_prop();
	void set_prop(Ref<PackedScene> value);

	Ref<PackedScene> get_prop_seeded(int seed);

	WorldGeneratorPropData();
	~WorldGeneratorPropData();

protected:
	static void _bind_methods();

#ifdef VOXELMAN_PRESENT
	Ref<PackedScene> _prop;
#else
	Ref<Resource> _prop;
#endif
};

#endif
