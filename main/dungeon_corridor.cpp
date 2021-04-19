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

#include "dungeon_corridor.h"

int DungeonCorridor::get_max_connections() {
	return _max_connections;
}
void DungeonCorridor::set_max_connections(int value) {
	_max_connections = value;
}

//Rooms
Ref<DungeonRoom> DungeonCorridor::get_dungeon_room(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_rooms.size(), Ref<DungeonRoom>());

	return _dungeon_rooms.get(index);
}
void DungeonCorridor::set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.set(index, dungeon_room);
}
void DungeonCorridor::add_dungeon_room(const Ref<DungeonRoom> dungeon_room) {
	_dungeon_rooms.push_back(dungeon_room);
}
void DungeonCorridor::remove_dungeon_room(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_rooms.size());

	_dungeon_rooms.remove(index);
}

int DungeonCorridor::get_dungeon_room_count() const {
	return _dungeon_rooms.size();
}

Ref<DungeonRoom> DungeonCorridor::_instance(const int seed, Ref<DungeonRoom> inst) {
	DungeonRoom::_instance(seed, inst);

	Ref<DungeonCorridor> cinst = inst;
	cinst->set_max_connections(_max_connections);

	return cinst;
}

DungeonCorridor::DungeonCorridor() {
	_max_connections = 2;
}
DungeonCorridor::~DungeonCorridor() {
	_dungeon_rooms.clear();
}

void DungeonCorridor::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_max_connections"), &DungeonCorridor::get_max_connections);
	ClassDB::bind_method(D_METHOD("set_max_connections", "value"), &DungeonCorridor::set_max_connections);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_connections"), "set_max_connections", "get_max_connections");

	//Rooms
	ClassDB::bind_method(D_METHOD("get_dungeon_room", "index"), &DungeonCorridor::get_dungeon_room);
	ClassDB::bind_method(D_METHOD("set_dungeon_room", "index", "data"), &DungeonCorridor::set_dungeon_room);
	ClassDB::bind_method(D_METHOD("add_dungeon_room", "dungeon_room"), &DungeonCorridor::add_dungeon_room);
	ClassDB::bind_method(D_METHOD("remove_dungeon_room", "index"), &DungeonCorridor::remove_dungeon_room);

	ClassDB::bind_method(D_METHOD("get_dungeon_room_count"), &DungeonCorridor::get_dungeon_room_count);
}
