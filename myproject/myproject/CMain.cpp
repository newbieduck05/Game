#include "SceneManager.h"
#include "DoubleBuffer.h"

int main()
{
	DoubleBuffer::Instance()->InitBuffer();
	SceneManager::Instance()->SetScene(LOGO);
	while (true)
	{
		SceneManager::Instance()->Progress();
		SceneManager::Instance()->Render();

		DoubleBuffer::Instance()->FlipBuffer();
		DoubleBuffer::Instance()->ClearBuffer();
		Sleep(50);
	}
	SceneManager::Instance()->Release();
	DoubleBuffer::Instance()->DestroyBuffer();
}