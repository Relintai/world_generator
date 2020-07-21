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

#ifndef DUNGEON_CORRIDOR_H
#define DUNGEON_CORRIDOR_H

#include "dungeon_room.h"

class DungeonCorridor : public DungeonRoom {
	GDCLASS(DungeonCorridor, DungeonRoom);

public:
	int get_max_connections();
	void set_max_connections(int value);

	//Rooms
	Ref<DungeonRoom> get_dungeon_room(const int index) const;
	void set_dungeon_room(const int index, const Ref<DungeonRoom> dungeon_room);
	void add_dungeon_room(const Ref<DungeonRoom> dungeon_room);
	void remove_dungeon_room(const int index);

	int get_dungeon_room_count() const;

	Ref<DungeonRoom> _instance(const int seed, Ref<DungeonRoom> inst);

	DungeonCorridor();
	~DungeonCorridor();

protected:
	static void _bind_methods();

private:
	int _max_connections;
	Vector<Ref<DungeonRoom> > _dungeon_rooms;
};

#endif
