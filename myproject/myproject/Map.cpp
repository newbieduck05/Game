#include "Map.h"
#include "DoubleBuffer.h"

void Map::Initialize()
{
}

void Map::Progress()
{
}

void Map::Render()
{
	for (int i = 0; y < 40; y++)
	{
		for (int i = 0; x < 60; x++)
		{
			switch (map[y][x])
			{
			case 0:
				break;
			case 1:
				DoubleBuffer::Instance()->WriteBuffer(x, y, "##", LIGHTGREEN);
				break;
			case 2:
				break;
			default:
				break;
			}
		}
	}
	DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
}

void Map::Release()
{
}
