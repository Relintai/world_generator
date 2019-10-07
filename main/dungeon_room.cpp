#include "dungeon_room.h"

Ref<EnvironmentData> DungeonRoom::get_environment() {
	return _environment;
}
void DungeonRoom::set_environment(Ref<EnvironmentData> value) {
	_environment = value;
}

Ref<PropData> DungeonRoom::get_prop_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _prop_datas.size(), Ref<PropData>());

	return _prop_datas.get(index);
}
void DungeonRoom::set_prop_data(const int index, const Ref<PropData> prop_data) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.set(index, prop_data);
}
void DungeonRoom::add_prop_data(const Ref<PropData> prop_data) {
	_prop_datas.push_back(prop_data);
}
void DungeonRoom::remove_prop_data(const int index) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.remove(index);
}

int DungeonRoom::get_prop_data_count() const {
	return _prop_datas.size();
}

void DungeonRoom::generate_chunk(Ref<VoxelChunk> chunk) {
	if (has_method("_generate_chunk")) {
		call("_generate_chunk", chunk);
	}
}

void DungeonRoom::generate_room(Ref<VoxelStructure> structure) {
	if (has_method("_generate_room")) {
		call("_generate_room", structure);
	}
}

DungeonRoom::DungeonRoom() {

}
DungeonRoom::~DungeonRoom() {
	_environment.unref();
	_prop_datas.clear();
}

void DungeonRoom::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_generate_room", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelStructure")));
	BIND_VMETHOD(MethodInfo("_generate_chunk", PropertyInfo(Variant::OBJECT, "structure", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk")));

	ClassDB::bind_method(D_METHOD("generate_chunk", "chunk"), &DungeonRoom::generate_chunk);
	ClassDB::bind_method(D_METHOD("generate_room", "structure"), &DungeonRoom::generate_room);

	ClassDB::bind_method(D_METHOD("get_environment"), &DungeonRoom::get_environment);
	ClassDB::bind_method(D_METHOD("set_environment", "value"), &DungeonRoom::set_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "environment", PROPERTY_HINT_RESOURCE_TYPE, "EnvironmentData"), "set_environment", "get_environment");

	ClassDB::bind_method(D_METHOD("get_prop_data", "index"), &DungeonRoom::get_prop_data);
	ClassDB::bind_method(D_METHOD("set_prop_data", "index", "data"), &DungeonRoom::set_prop_data);
	ClassDB::bind_method(D_METHOD("add_prop_data", "prop_data"), &DungeonRoom::add_prop_data);
	ClassDB::bind_method(D_METHOD("remove_prop_data", "index"), &DungeonRoom::remove_prop_data);

	ClassDB::bind_method(D_METHOD("get_prop_data_count"), &DungeonRoom::get_prop_data_count);
}
