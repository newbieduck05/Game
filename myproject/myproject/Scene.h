#pragma once
#include "Include.h"
class Scene
{
public:
	virtual void Initialize() abstract;
	virtual void Progress() abstract;
	virtual void Render() abstract;
	virtual void Release() abstract;
};

