#pragma once
#include "Include.h"
class Obj
{
protected:
	int x;
	int y;
	const char* shape;
	Color color;
public:
	virtual void Initialize() abstract;
	virtual void Progress() abstract;
	virtual void Render() abstract;
	virtual void Release() abstract;
};

