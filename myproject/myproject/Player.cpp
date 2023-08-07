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
	
    if (GetAsyncKeyState(VK_SPACE) && !jump)
    {
        h = 0;
        time = 0;
        playerY = y;
        jump = true;
    }

    if (jump)
    {
        time += 0.1f;
        h = -Vo * time + (0.5f * G * time * time);
        y = playerY + h;

        if (y >= playerY)
        {
            y = playerY;
            jump = false;
        }
    }
}

void Player::Render()
{
    DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
}

void Player::Release()
{
}
