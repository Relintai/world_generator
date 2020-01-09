#pragma once
#include "DungeonRoom.h"
#include "GameObject.h"
#include "Quaternion.h"
#include "UnityEngine.h"
#include "Vector3.h"
#include "Voxelizzer.h"
#include <System/System.h>

using namespace UnityEngine;
using namespace VoxelToolbox;
using namespace System;
namespace BS {
namespace Levels {
namespace Generator {
class DungeonStartRoom : public virtual DungeonRoom, public virtual Object {
public:
	DungeonStartRoom(int x, int y, int width, int height);

public:
	void GenerateSpawnPoint(GameObject *startPositionPrefab);

public:
	virtual void GenerateAIPlayers(int level);
};
} // namespace Generator
} // namespace Levels
} // namespace BS
