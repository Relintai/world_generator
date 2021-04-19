def can_build(env, platform):
    return True

def configure(env):
    pass

def get_doc_classes():
    return [
        "WorldGeneratorPropData",

        "Planet",
        "Building",
        "Biome",

        "WorldGenerator",
    ]

def get_doc_path():
    return "doc_classes"