#include "Logo.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

void Logo::Initialize()
{
	
}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Instance()->SetScene(MENU);
	}
}

void Logo::Render()
{
	DoubleBuffer::Instance()->WriteBuffer(10, 10, "LOGO", WHITE);
}

void Logo::Release()
{
}
