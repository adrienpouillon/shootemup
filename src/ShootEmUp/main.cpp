#include "pch.h"
#include "main.h"
#include "GameManager.h"

int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	GameManager* gameManager = new GameManager;
	gameManager->Run();
	return 0;
}
