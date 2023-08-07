#pragma once
#include "Obj.h"

class Player : public Obj
{
protected:
	Obj* player;
	float time = 0.0;
	float h = 0;
	float playerY = 0;
	const float G = 9.81f;
	const float Vo = 5.f;
	bool jump = false;
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

