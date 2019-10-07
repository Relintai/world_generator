#include "biome.h"

Ref<EnvironmentData> Biome::get_environment() {
	return _environment;
}
void Biome::set_environment(Ref<EnvironmentData> value) {
	_environment = value;
}

////    Prop Data    ////
Ref<PropData> Biome::get_prop_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _prop_datas.size(), Ref<PropData>());

	return _prop_datas.get(index);
}
void Biome::set_prop_data(const int index, const Ref<PropData> prop_data) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.set(index, prop_data);
}
void Biome::add_prop_data(const Ref<PropData> prop_data) {
	_prop_datas.push_back(prop_data);
}
void Biome::remove_prop_data(const int index) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.remove(index);
}

int Biome::get_prop_data_count() const {
	return _prop_datas.size();
}

////    Dungeons    ////
Ref<Dungeon> Biome::get_dungeon(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeons.size(), Ref<Dungeon>());

	return _dungeons.get(index);
}
void Biome::set_dungeon(const int index, const Ref<Dungeon> dungeon) {
	ERR_FAIL_INDEX(index, _dungeons.size());

	_dungeons.set(index, dungeon);
}
void Biome::add_dungeon(const Ref<Dungeon> dungeon) {
	_dungeons.push_back(dungeon);
}
void Biome::remove_dungeon(const int index) {
	ERR_FAIL_INDEX(index, _dungeons.size());

	_dungeons.remove(index);
}

int Biome::get_dungeon_count() const {
	return _dungeons.size();
}


void Biome::generate_chunk(Ref<VoxelChunk> chunk) {
	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk);
	}
}
void Biome::generate_stack(Ref<VoxelChunk> chunk, int x, int z) {
	if (has_method("_generate_stack")) {
		call("_generate_stack", chunk, x, z);
	}
}

Biome::Biome() {

}
Biome::~Biome() {
	_environment.unref();
	_prop_datas.clear();
	_dungeons.clear();
}

void Biome::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk")));
	BIND_VMETHOD(MethodInfo("_generate_stack", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::INT, "x"), PropertyInfo(Variant::INT, "z")));

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk"), &Biome::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_stack", "chunk", "x", "z"), &Biome::generate_stack);

	ClassDB::bind_method(D_METHOD("get_environment"), &Biome::get_environment);
	ClassDB::bind_method(D_METHOD("set_environment", "value"), &Biome::set_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_environment", "get_environment");

	ClassDB::bind_method(D_METHOD("get_prop_data", "index"), &Biome::get_prop_data);
	ClassDB::bind_method(D_METHOD("set_prop_data", "index", "data"), &Biome::set_prop_data);
	ClassDB::bind_method(D_METHOD("add_prop_data", "prop_data"), &Biome::add_prop_data);
	ClassDB::bind_method(D_METHOD("remove_prop_data", "index"), &Biome::remove_prop_data);

	ClassDB::bind_method(D_METHOD("get_prop_data_count"), &Biome::get_prop_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon", "index"), &Biome::get_dungeon);
	ClassDB::bind_method(D_METHOD("set_dungeon", "index", "data"), &Biome::set_dungeon);
	ClassDB::bind_method(D_METHOD("add_dungeon", "dungeon"), &Biome::add_dungeon);
	ClassDB::bind_method(D_METHOD("remove_dungeon", "index"), &Biome::remove_dungeon);

	ClassDB::bind_method(D_METHOD("get_dungeon_count"), &Biome::get_dungeon_count);
}
