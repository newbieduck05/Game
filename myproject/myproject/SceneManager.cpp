#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

void SceneManager::SetScene(SCENE_ID id)
{
	Release();
	switch (id)
	{
	case LOGO:
		currentScene = new Logo;
		break;
	case MENU:
		currentScene = new Menu;
		break;
	case STAGE:
		currentScene = new Stage;
		break;
	default:
		break;
	}

	currentScene->Initialize();
}

void SceneManager::Progress()
{
	currentScene->Progress();
}

void SceneManager::Render()
{
	currentScene->Render();
}

void SceneManager::Release()
{
	if (currentScene != nullptr)
	{
		currentScene->Release();
		delete currentScene;
		currentScene = nullptr;
	}
}
