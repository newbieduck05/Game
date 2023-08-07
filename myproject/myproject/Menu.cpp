#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

void Menu::Initialize()
{
}

void Menu::Progress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Instance()->SetScene(STAGE);
	}
}

void Menu::Render()
{
	DoubleBuffer::Instance()->WriteBuffer(10, 10, "MENU", WHITE);
}

void Menu::Release()
{
}
