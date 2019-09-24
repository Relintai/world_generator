#include "register_types.h"

#include "data/dungeon_room_data.h"
#include "data/dungeon_data.h"
#include "data/biome_data.h"
#include "data/planet_data.h"
#include "data/prop_data.h"

#include "main/dungeon_room.h"
#include "main/dungeon.h"
#include "main/biome.h"
#include "main/planet.h"

#include "world_generator.h"

void register_world_generator_types() {
	ClassDB::register_class<DungeonRoomData>();
	ClassDB::register_class<DungeonData>();
	ClassDB::register_class<BiomeData>();
	ClassDB::register_class<PlanetData>();
	ClassDB::register_class<PropData>();

	ClassDB::register_class<DungeonRoom>();
	ClassDB::register_class<Dungeon>();
	ClassDB::register_class<Biome>();
	ClassDB::register_class<Planet>();

	ClassDB::register_class<WorldGenerator>();
}	

void unregister_world_generator_types() {

}

