#include "Player.h"
#include "DoubleBuffer.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	shape = "бс";
	color = WHITE;
}

void Player::Progress()
{
	if (GetAsyncKeyState(0X41))
	{
		x--;
	}
	
	if (GetAsyncKeyState(0X44))
	{
		x++;
	}
	
	if (GetAsyncKeyState(VK_SPACE))
	{
		
	}
}

void Player::Render()
{
}

void Player::Release()
{
}
