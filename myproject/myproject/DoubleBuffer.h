#pragma once
#include "Singleton.h"
class DoubleBuffer : public Singleton<DoubleBuffer>
{
private:
	HANDLE hBuffer[2];
	int screenIndex;
public:
	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x, int y, const char* shape, int color);
	void DestroyBuffer();
};

