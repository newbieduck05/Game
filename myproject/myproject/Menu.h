#pragma once
#include "Scene.h"
class Menu : public Scene
{
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

