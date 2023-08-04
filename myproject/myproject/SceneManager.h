#pragma once
#include "Singleton.h"
class SceneManager : public Singleton<SceneManager>
{
private:
	class Scene* currentScene = nullptr;
public:
	void SetScene(SCENE_ID id);
	void Progress();
	void Render();
	void Release();
};

