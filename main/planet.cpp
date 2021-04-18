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

#include "planet.h"

#include "core/version.h"

int Planet::get_id() const {
	return _id;
}
void Planet::set_id(const int value) {
	_id = value;
}

int Planet::get_current_seed() {
	return _current_seed;
}
void Planet::set_current_seed(int value) {
	_current_seed = value;
}

Vector2 Planet::get_level_range() {
	return _level_range;
}
void Planet::set_level_range(Vector2 value) {
	_level_range = value;
}

#ifdef FASTNOISE_PRESENT
Ref<FastnoiseNoiseParams> Planet::get_humidity_noise_params() {
	return _humidity_noise_params;
}
void Planet::set_humidity_noise_params(Ref<FastnoiseNoiseParams> value) {
	_humidity_noise_params = value;
}

Ref<FastnoiseNoiseParams> Planet::get_temperature_noise_params() {
	return _temperature_noise_params;
}
void Planet::set_temperature_noise_params(Ref<FastnoiseNoiseParams> value) {
	_temperature_noise_params = value;
}
#endif

Ref<Biome> Planet::get_biome(const int index) const {
	ERR_FAIL_INDEX_V(index, _biomes.size(), Ref<Biome>());

	return _biomes.get(index);
}
void Planet::set_biome(const int index, const Ref<Biome> biome) {
	ERR_FAIL_INDEX(index, _biomes.size());

	_biomes.set(index, biome);
}
void Planet::add_biome(const Ref<Biome> biome) {
	_biomes.push_back(biome);
}
void Planet::remove_biome(const int index) {
	ERR_FAIL_INDEX(index, _biomes.size());

	_biomes.remove(index);
}

int Planet::get_biome_count() const {
	return _biomes.size();
}

Vector<Variant> Planet::get_biomes() {
	Vector<Variant> r;
	for (int i = 0; i < _biomes.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_biomes[i].get_ref_ptr());
#else
		r.push_back(_biomes[i]);
#endif
	}
	return r;
}
void Planet::set_biomes(const Vector<Variant> &biomes) {
	_biomes.clear();
	for (int i = 0; i < biomes.size(); i++) {
		Ref<Biome> biome_data = Ref<Biome>(biomes[i]);

		_biomes.push_back(biome_data);
	}
}

////    Dungeons    ////
Ref<Dungeon> Planet::get_dungeon(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeons.size(), Ref<Dungeon>());

	return _dungeons.get(index);
}
void Planet::set_dungeon(const int index, const Ref<Dungeon> dungeon) {
	ERR_FAIL_INDEX(index, _dungeons.size());

	_dungeons.set(index, dungeon);
}
void Planet::add_dungeon(const Ref<Dungeon> dungeon) {
	_dungeons.push_back(dungeon);
}
void Planet::remove_dungeon(const int index) {
	ERR_FAIL_INDEX(index, _dungeons.size());

	_dungeons.remove(index);
}
int Planet::get_dungeon_count() const {
	return _dungeons.size();
}

Ref<Planet> Planet::instance(const int seed) {
	Ref<Planet> inst;

	inst = Ref<Planet>(Object::cast_to<Planet>(ClassDB::instance(get_class_name())));
	ERR_FAIL_COND_V(!inst.is_valid(), inst);

	if (!get_script().is_null())
		inst->set_script(get_script());

	return call("_instance", seed, inst);
}

Ref<Planet> Planet::_instance(const int seed, Ref<Planet> inst) {
	inst->set_id(_id);
	inst->set_current_seed(seed);
	inst->set_level_range(_level_range);

	for (int i = 0; i < _biomes.size(); ++i) {
		Ref<Biome> b = _biomes[i];

		if (!b.is_valid())
			continue;

		inst->add_biome(b->instance(seed));
	}

	for (int i = 0; i < _dungeons.size(); ++i) {
		Ref<Dungeon> d = _dungeons[i];

		if (!d.is_valid())
			continue;

		inst->add_dungeon(d->instance(seed));
	}

#ifdef FASTNOISE_PRESENT
	if (_humidity_noise_params.is_valid())
		inst->set_humidity_noise_params(_humidity_noise_params->duplicate());

	if (_temperature_noise_params.is_valid())
		inst->set_temperature_noise_params(_temperature_noise_params->duplicate());
#endif


#ifdef VOXELMAN_PRESENT
	inst->set_voxel_environment(_voxel_environment);

	for (int i = 0; i < _voxel_environment_datas.size(); ++i) {
		Ref<EnvironmentData> d = _voxel_environment_datas[i];

		if (!d.is_valid())
			continue;

		inst->add_voxel_environment_data(d);
	}

	for (int i = 0; i < _voxel_surfaces.size(); ++i) {
		Ref<VoxelSurface> d = _voxel_surfaces[i];

		if (!d.is_valid())
			continue;

		inst->add_voxel_surface(d);
	}
#endif

#ifdef TERRAMAN_PRESENT
	inst->set_terra_environment(_terra_environment);

	for (int i = 0; i < _terra_environment_datas.size(); ++i) {
		Ref<EnvironmentData> d = _terra_environment_datas[i];

		if (!d.is_valid())
			continue;

		inst->add_terra_environment_data(d);
	}

	for (int i = 0; i < _terra_surfaces.size(); ++i) {
		Ref<VoxelSurface> d = _terra_surfaces[i];

		if (!d.is_valid())
			continue;

		inst->add_terra_surface(d);
	}
#endif

	return inst;
}

void Planet::setup() {
	if (has_method("_setup")) {
		call("_setup");
	}
}

Ref<Image> Planet::generate_map() {
	ERR_FAIL_COND_V(!has_method("_generate_map"), Ref<Image>());

	return call("_generate_map");
}

#ifdef VOXELMAN_PRESENT
Ref<EnvironmentData> Planet::get_voxel_environment() {
	return _voxel_environment;
}
void Planet::set_voxel_environment(Ref<EnvironmentData> value) {
	_voxel_environment = value;
}

//Environments
Ref<EnvironmentData> Planet::get_voxel_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_environment_datas.size(), Ref<EnvironmentData>());

	return _voxel_environment_datas.get(index);
}
void Planet::set_voxel_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _voxel_environment_datas.size());

	_voxel_environment_datas.set(index, environment_data);
}
void Planet::add_voxel_environment_data(const Ref<EnvironmentData> environment_data) {
	_voxel_environment_datas.push_back(environment_data);
}
void Planet::remove_voxel_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _voxel_environment_datas.size());

	_voxel_environment_datas.remove(index);
}
int Planet::get_voxel_environment_data_count() const {
	return _voxel_environment_datas.size();
}

Vector<Variant> Planet::get_voxel_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _voxel_environment_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_voxel_environment_datas[i].get_ref_ptr());
#else
		r.push_back(_voxel_environment_datas[i]);
#endif
	}
	return r;
}
void Planet::set_voxel_environment_datas(const Vector<Variant> &environment_datas) {
	_voxel_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_voxel_environment_datas.push_back(environment_data);
	}
}

////    Surfaces    ////
Ref<VoxelSurface> Planet::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void Planet::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void Planet::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void Planet::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int Planet::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> Planet::get_voxel_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _voxel_surfaces.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_voxel_surfaces[i].get_ref_ptr());
#else
		r.push_back(_voxel_surfaces[i]);
#endif
	}
	return r;
}
void Planet::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<VoxelSurface> voxel_surface = Ref<VoxelSurface>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

void Planet::setup_voxel_library(Ref<VoxelmanLibrary> library) {
	ERR_FAIL_COND(!library.is_valid());

	if (has_method("_setup_voxel_library")) {
		call("_setup_voxel_library", library);
	}
}

void Planet::_setup_voxel_library(Ref<VoxelmanLibrary> library) {
	for (int i = 0; i < get_voxel_surface_count(); ++i) {
		Ref<VoxelSurface> s = get_voxel_surface(i);

		if (s.is_valid()) {
			library->voxel_surface_add(s);
		}
	}

	for (int i = 0; i < get_biome_count(); ++i) {
		Ref<Biome> s = get_biome(i);

		if (s.is_valid()) {
			s->setup_voxel_library(library);
		}
	}

	for (int i = 0; i < get_dungeon_count(); ++i) {
		Ref<Dungeon> d = get_dungeon(i);

		if (d.is_valid()) {
			d->setup_voxel_library(library);
		}
	}
}

void Planet::generate_voxel_chunk(Ref<VoxelChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_voxel_chunk")) {
		call("_generate_voxel_chunk", chunk, spawn_mobs);
	}
}

#endif

#ifdef TERRAMAN_PRESENT
Ref<TerraEnvironmentData> Planet::get_terra_environment() {
	return _terra_environment;
}
void Planet::set_terra_environment(Ref<TerraEnvironmentData> value) {
	_terra_environment = value;
}

//Environments
Ref<TerraEnvironmentData> Planet::get_terra_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _terra_environment_datas.size(), Ref<TerraEnvironmentData>());

	return _terra_environment_datas.get(index);
}
void Planet::set_terra_environment_data(const int index, const Ref<TerraEnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _terra_environment_datas.size());

	_terra_environment_datas.set(index, environment_data);
}
void Planet::add_terra_environment_data(const Ref<TerraEnvironmentData> environment_data) {
	_terra_environment_datas.push_back(environment_data);
}
void Planet::remove_terra_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _terra_environment_datas.size());

	_terra_environment_datas.remove(index);
}
int Planet::get_terra_environment_data_count() const {
	return _terra_environment_datas.size();
}

Vector<Variant> Planet::get_terra_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _terra_environment_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_terra_environment_datas[i].get_ref_ptr());
#else
		r.push_back(_terra_environment_datas[i]);
#endif
	}
	return r;
}
void Planet::set_terra_environment_datas(const Vector<Variant> &environment_datas) {
	_terra_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<TerraEnvironmentData> environment_data = Ref<TerraEnvironmentData>(environment_datas[i]);

		_terra_environment_datas.push_back(environment_data);
	}
}

////    Surfaces    ////
Ref<TerraSurface> Planet::get_terra_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _terra_surfaces.size(), Ref<TerraSurface>());

	return _terra_surfaces.get(index);
}
void Planet::set_terra_surface(const int index, const Ref<TerraSurface> terra_surface) {
	ERR_FAIL_INDEX(index, _terra_surfaces.size());

	_terra_surfaces.set(index, terra_surface);
}
void Planet::add_terra_surface(const Ref<TerraSurface> terra_surface) {
	_terra_surfaces.push_back(terra_surface);
}
void Planet::remove_terra_surface(const int index) {
	ERR_FAIL_INDEX(index, _terra_surfaces.size());

	_terra_surfaces.remove(index);
}
int Planet::get_terra_surface_count() const {
	return _terra_surfaces.size();
}

Vector<Variant> Planet::get_terra_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _terra_surfaces.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_terra_surfaces[i].get_ref_ptr());
#else
		r.push_back(_terra_surfaces[i]);
#endif
	}
	return r;
}
void Planet::set_terra_surfaces(const Vector<Variant> &terra_surfaces) {
	_terra_surfaces.clear();
	for (int i = 0; i < terra_surfaces.size(); i++) {
		Ref<TerraSurface> terra_surface = Ref<TerraSurface>(terra_surfaces[i]);

		_terra_surfaces.push_back(terra_surface);
	}
}

void Planet::setup_terra_library(Ref<TerramanLibrary> library) {
	ERR_FAIL_COND(!library.is_valid());

	if (has_method("_setup_terra_library")) {
		call("_setup_terra_library", library);
	}
}

void Planet::_setup_terra_library(Ref<TerramanLibrary> library) {
	for (int i = 0; i < get_terra_surface_count(); ++i) {
		Ref<TerraSurface> s = get_terra_surface(i);

		if (s.is_valid()) {
			library->voxel_surface_add(s);
		}
	}

	for (int i = 0; i < get_biome_count(); ++i) {
		Ref<Biome> s = get_biome(i);

		if (s.is_valid()) {
			s->setup_terra_library(library);
		}
	}

	for (int i = 0; i < get_dungeon_count(); ++i) {
		Ref<Dungeon> d = get_dungeon(i);

		if (d.is_valid()) {
			d->setup_terra_library(library);
		}
	}
}

void Planet::generate_terra_chunk(Ref<TerraChunk> chunk, bool spawn_mobs) {
	ERR_FAIL_COND(!chunk.is_valid());

	if (has_method("_generate_terra_chunk")) {
		call("_generate_terra_chunk", chunk, spawn_mobs);
	}
}

#endif

Planet::Planet() {
	_id = 0;
	_current_seed = 0;
}
Planet::~Planet() {
	_biomes.clear();
	_dungeons.clear();

#ifdef FASTNOISE_PRESENT
	_humidity_noise_params.unref();
	_temperature_noise_params.unref();
#endif

#ifdef VOXELMAN_PRESENT
	_voxel_environment.unref();

	_voxel_environment_datas.clear();
	_voxel_surfaces.clear();
#endif

#ifdef TERRAMAN_PRESENT
	_terra_environment.unref();

	_terra_environment_datas.clear();
	_terra_surfaces.clear();
#endif
}

void Planet::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "inst", PROPERTY_HINT_RESOURCE_TYPE, "Planet"),
			"_instance",
			PropertyInfo(Variant::INT, "p_seed"),
			PropertyInfo(Variant::OBJECT, "p_instance", PROPERTY_HINT_RESOURCE_TYPE, "Planet")));

	BIND_VMETHOD(MethodInfo("_setup"));

	ClassDB::bind_method(D_METHOD("instance", "seed"), &Planet::instance);
	ClassDB::bind_method(D_METHOD("_instance", "p_seed", "p_instance"), &Planet::_instance);

	ClassDB::bind_method(D_METHOD("setup"), &Planet::setup);

	ClassDB::bind_method(D_METHOD("get_id"), &Planet::get_id);
	ClassDB::bind_method(D_METHOD("set_id", "value"), &Planet::set_id);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "id"), "set_id", "get_id");

	ClassDB::bind_method(D_METHOD("get_current_seed"), &Planet::get_current_seed);
	ClassDB::bind_method(D_METHOD("set_current_seed", "value"), &Planet::set_current_seed);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "current_seed"), "set_current_seed", "get_current_seed");

	ClassDB::bind_method(D_METHOD("get_level_range"), &Planet::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &Planet::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

#ifdef FASTNOISE_PRESENT
	ClassDB::bind_method(D_METHOD("get_humidity_noise_params"), &Planet::get_humidity_noise_params);
	ClassDB::bind_method(D_METHOD("set_humidity_noise_params", "value"), &Planet::set_humidity_noise_params);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "humidity_noise_params", PROPERTY_HINT_RESOURCE_TYPE, "FastnoiseNoiseParams"), "set_humidity_noise_params", "get_humidity_noise_params");

	ClassDB::bind_method(D_METHOD("get_temperature_noise_params"), &Planet::get_temperature_noise_params);
	ClassDB::bind_method(D_METHOD("set_temperature_noise_params", "value"), &Planet::set_temperature_noise_params);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "temperature_noise_params", PROPERTY_HINT_RESOURCE_TYPE, "FastnoiseNoiseParams"), "set_temperature_noise_params", "get_temperature_noise_params");
#endif

	//biomes
	ClassDB::bind_method(D_METHOD("get_biome", "index"), &Planet::get_biome);
	ClassDB::bind_method(D_METHOD("set_biome", "index", "data"), &Planet::set_biome);
	ClassDB::bind_method(D_METHOD("add_biome", "biome"), &Planet::add_biome);
	ClassDB::bind_method(D_METHOD("remove_biome", "index"), &Planet::remove_biome);
	ClassDB::bind_method(D_METHOD("get_biome_count"), &Planet::get_biome_count);

	ClassDB::bind_method(D_METHOD("get_biomes"), &Planet::get_biomes);
	ClassDB::bind_method(D_METHOD("set_biomes", "biomes"), &Planet::set_biomes);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "biomes", PROPERTY_HINT_NONE, "17/17:Biome", PROPERTY_USAGE_DEFAULT, "Biome"), "set_biomes", "get_biomes");

	//Dungeons
	ClassDB::bind_method(D_METHOD("get_dungeon", "index"), &Planet::get_dungeon);
	ClassDB::bind_method(D_METHOD("set_dungeon", "index", "data"), &Planet::set_dungeon);
	ClassDB::bind_method(D_METHOD("add_dungeon", "dungeon"), &Planet::add_dungeon);
	ClassDB::bind_method(D_METHOD("remove_dungeon", "index"), &Planet::remove_dungeon);
	ClassDB::bind_method(D_METHOD("get_dungeon_count"), &Planet::get_dungeon_count);

	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "image", PROPERTY_HINT_RESOURCE_TYPE, "Image"), "_generate_map"));

	ClassDB::bind_method(D_METHOD("generate_map"), &Planet::generate_map);

#ifdef VOXELMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "VoxelmanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));

	ClassDB::bind_method(D_METHOD("generate_voxel_chunk", "chunk"), &Planet::generate_voxel_chunk);
	ClassDB::bind_method(D_METHOD("_setup_voxel_library", "library"), &Planet::_setup_voxel_library);
	ClassDB::bind_method(D_METHOD("setup_voxel_library", "library"), &Planet::setup_voxel_library);

	ClassDB::bind_method(D_METHOD("get_voxel_environment"), &Planet::get_voxel_environment);
	ClassDB::bind_method(D_METHOD("set_voxel_environment", "value"), &Planet::set_voxel_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "voxel_environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_voxel_environment", "get_voxel_environment");

	//Environments
	ClassDB::bind_method(D_METHOD("get_voxel_environment_data", "index"), &Planet::get_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("set_voxel_environment_data", "index", "data"), &Planet::set_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("add_voxel_environment_data", "environment_data"), &Planet::add_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("remove_voxel_environment_data", "index"), &Planet::remove_voxel_environment_data);
	ClassDB::bind_method(D_METHOD("get_voxel_environment_data_count"), &Planet::get_voxel_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_voxel_environment_datas"), &Planet::get_voxel_environment_datas);
	ClassDB::bind_method(D_METHOD("set_voxel_environment_datas", "environment_datas"), &Planet::set_voxel_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_voxel_environment_datas", "get_voxel_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &Planet::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &Planet::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &Planet::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &Planet::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &Planet::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &Planet::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &Planet::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");
#endif

#ifdef TERRAMAN_PRESENT
	BIND_VMETHOD(MethodInfo("_setup_library", PropertyInfo(Variant::OBJECT, "library", PROPERTY_HINT_RESOURCE_TYPE, "TerramanLibrary")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "TerraChunk"), PropertyInfo(Variant::BOOL, "spawn_mobs")));

	ClassDB::bind_method(D_METHOD("generate_terra_chunk", "chunk"), &Planet::generate_terra_chunk);
	ClassDB::bind_method(D_METHOD("_setup_terra_library", "library"), &Planet::_setup_terra_library);
	ClassDB::bind_method(D_METHOD("setup_terra_library", "library"), &Planet::setup_terra_library);

	ClassDB::bind_method(D_METHOD("get_terra_environment"), &Planet::get_terra_environment);
	ClassDB::bind_method(D_METHOD("set_terra_environment", "value"), &Planet::set_terra_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "terra_environment", PROPERTY_HINT_RESOURCE_TYPE, "TerraEnvironmentData"), "set_terra_environment", "get_terra_environment");

	//Environments
	ClassDB::bind_method(D_METHOD("get_terra_environment_data", "index"), &Planet::get_terra_environment_data);
	ClassDB::bind_method(D_METHOD("set_terra_environment_data", "index", "data"), &Planet::set_terra_environment_data);
	ClassDB::bind_method(D_METHOD("add_terra_environment_data", "environment_data"), &Planet::add_terra_environment_data);
	ClassDB::bind_method(D_METHOD("remove_terra_environment_data", "index"), &Planet::remove_terra_environment_data);
	ClassDB::bind_method(D_METHOD("get_terra_environment_data_count"), &Planet::get_terra_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_terra_environment_datas"), &Planet::get_terra_environment_datas);
	ClassDB::bind_method(D_METHOD("set_terra_environment_datas", "environment_datas"), &Planet::set_terra_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "terra_environment_datas", PROPERTY_HINT_NONE, "17/17:TerraEnvironmentData", PROPERTY_USAGE_DEFAULT, "TerraEnvironmentData"), "set_terra_environment_datas", "get_terra_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_terra_surface", "index"), &Planet::get_terra_surface);
	ClassDB::bind_method(D_METHOD("set_terra_surface", "index", "data"), &Planet::set_terra_surface);
	ClassDB::bind_method(D_METHOD("add_terra_surface", "terra_surface"), &Planet::add_terra_surface);
	ClassDB::bind_method(D_METHOD("remove_terra_surface", "index"), &Planet::remove_terra_surface);
	ClassDB::bind_method(D_METHOD("get_terra_surface_count"), &Planet::get_terra_surface_count);

	ClassDB::bind_method(D_METHOD("get_terra_surfaces"), &Planet::get_terra_surfaces);
	ClassDB::bind_method(D_METHOD("set_terra_surfaces", "terra_surfaces"), &Planet::set_terra_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "terra_surfaces", PROPERTY_HINT_NONE, "17/17:TerraSurface", PROPERTY_USAGE_DEFAULT, "TerraSurface"), "set_terra_surfaces", "get_terra_surfaces");
#endif
}
