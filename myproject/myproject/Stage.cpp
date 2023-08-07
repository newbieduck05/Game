#include "Stage.h"
#include "Player.h"
#include "Map.h"

void Stage::Initialize()
{
	map = new Map;
	map->Initialize();

	player = new Player;
	player->Initialize();
}

void Stage::Progress()
{
	map->Progress();

	player->Progress();
}

void Stage::Render()
{
	map->Render();

	player->Render();
}

void Stage::Release()
{
	if (true)
	{
		map->Release();
		delete map;
		map = nullptr;
	}

	if (true)
	{
		player->Release();
		delete player;
		player = nullptr;
	}
}
