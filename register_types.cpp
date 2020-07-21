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

#include "register_types.h"

#include "data/biome_data.h"
#include "data/dungeon_corridor_data.h"
#include "data/dungeon_data.h"
#include "data/dungeon_room_data.h"
#include "data/world_generator_prop_data.h"

#include "main/biome.h"
#include "main/dungeon.h"
#include "main/dungeon_corridor.h"
#include "main/dungeon_room.h"
#include "main/planet.h"

#include "world_generator.h"

void register_world_generator_types() {
	ClassDB::register_class<DungeonRoomData>();
	ClassDB::register_class<DungeonCorridorData>();
	ClassDB::register_class<DungeonData>();
	ClassDB::register_class<BiomeData>();
	ClassDB::register_class<WorldGeneratorPropData>();

	ClassDB::register_class<DungeonRoom>();
	ClassDB::register_class<DungeonCorridor>();
	ClassDB::register_class<Dungeon>();
	ClassDB::register_class<Biome>();
	ClassDB::register_class<Planet>();

	ClassDB::register_class<WorldGenerator>();
}

void unregister_world_generator_types() {
}
