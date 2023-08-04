#pragma once
#include "Scene.h"
class Logo : public Scene
{
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

