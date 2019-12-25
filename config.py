def can_build(env, platform):
    return True

def configure(env):
    pass

def get_doc_classes():
    return [
        "BiomeData",
        "DungeonCorridorData",
        "DungeonData",
        "DungeonRoomData",
        "PlanetData",
        "WorldGeneratorPropData",
        "BiomeData",

        "Planet",
        "Dungeon",
        "DungeonRoom",
        "DungeonCorridor",
        "Biome",
    ]

def get_doc_path():
    return "doc_classes"