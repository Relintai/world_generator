#include "dungeon_data.h"

Ref<DungeonRoomData> DungeonData::get_dungeon_room_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_room_datas.size(), Ref<DungeonRoomData>());

	return _dungeon_room_datas.get(index);
}
void DungeonData::set_dungeon_room_data(const int index, const Ref<DungeonRoomData> dungeon_room_data) {
	ERR_FAIL_INDEX(index, _dungeon_room_datas.size());

	_dungeon_room_datas.set(index, dungeon_room_data);
}
void DungeonData::add_dungeon_room_data(const Ref<DungeonRoomData> dungeon_room_data) {
	_dungeon_room_datas.push_back(dungeon_room_data);
}
void DungeonData::remove_dungeon_room_data(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_room_datas.size());

	_dungeon_room_datas.remove(index);
}

int DungeonData::get_dungeon_room_data_count() const {
	return _dungeon_room_datas.size();
}

Vector<Variant> DungeonData::get_dungeon_room_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_room_datas.size(); i++) {
		r.push_back(_dungeon_room_datas[i].get_ref_ptr());
	}
	return r;
}
void DungeonData::set_dungeon_room_datas(const Vector<Variant> &dungeon_room_datas) {
	_dungeon_room_datas.clear();
	for (int i = 0; i < dungeon_room_datas.size(); i++) {
		Ref<DungeonRoomData> dungeon_room_data = Ref<DungeonRoomData>(dungeon_room_datas[i]);

		_dungeon_room_datas.push_back(dungeon_room_data);
	}
}

//Environments
Ref<EnvironmentData> DungeonData::get_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _environment_datas.size(), Ref<EnvironmentData>());

	return _environment_datas.get(index);
}
void DungeonData::set_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.set(index, environment_data);
}
void DungeonData::add_environment_data(const Ref<EnvironmentData> environment_data) {
	_environment_datas.push_back(environment_data);
}
void DungeonData::remove_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.remove(index);
}
int DungeonData::get_environment_data_count() const {
	return _environment_datas.size();
}

Vector<Variant> DungeonData::get_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _environment_datas.size(); i++) {
		r.push_back(_environment_datas[i].get_ref_ptr());
	}
	return r;
}
void DungeonData::set_environment_datas(const Vector<Variant> &environment_datas) {
	_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_environment_datas.push_back(environment_data);
	}
}

Ref<Dungeon> DungeonData::setup_dungeon(int seed) {
	if (has_method("_setup_dungeon")) {
		return call("_setup_dungeon", seed);
	}

	return Ref<Dungeon>(NULL);
}

DungeonData::DungeonData() {

}
DungeonData::~DungeonData() {

}

void DungeonData::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::OBJECT, "room", PROPERTY_HINT_RESOURCE_TYPE, "Dungeon"), "_setup_dungeon", PropertyInfo(Variant::INT, "seed")));

	ClassDB::bind_method(D_METHOD("setup_dungeon", "seed"), &DungeonData::setup_dungeon);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_data", "index"), &DungeonData::get_dungeon_room_data);
	ClassDB::bind_method(D_METHOD("set_dungeon_room_data", "index", "data"), &DungeonData::set_dungeon_room_data);
	ClassDB::bind_method(D_METHOD("add_dungeon_room_data", "dungeon_room_data"), &DungeonData::add_dungeon_room_data);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room_data", "index"), &DungeonData::remove_dungeon_room_data);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_data_count"), &DungeonData::get_dungeon_room_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_datas"), &DungeonData::get_dungeon_room_datas);
	ClassDB::bind_method(D_METHOD("set_dungeon_room_datas", "dungeon_room_datas"), &DungeonData::set_dungeon_room_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_room_datas", PROPERTY_HINT_NONE, "17/17:DungeonRoomData", PROPERTY_USAGE_DEFAULT, "DungeonRoomData"), "set_dungeon_room_datas", "get_dungeon_room_datas");

	//Environments
	ClassDB::bind_method(D_METHOD("get_environment_data", "index"), &DungeonData::get_environment_data);
	ClassDB::bind_method(D_METHOD("set_environment_data", "index", "data"), &DungeonData::set_environment_data);
	ClassDB::bind_method(D_METHOD("add_environment_data", "environment_data"), &DungeonData::add_environment_data);
	ClassDB::bind_method(D_METHOD("remove_environment_data", "index"), &DungeonData::remove_environment_data);

	ClassDB::bind_method(D_METHOD("get_environment_data_count"), &DungeonData::get_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_environment_datas"), &DungeonData::get_environment_datas);
	ClassDB::bind_method(D_METHOD("set_environment_datas", "environment_datas"), &DungeonData::set_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_environment_datas", "get_environment_datas");
}
