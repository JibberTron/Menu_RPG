#include "Main_Menu.h"

#if 1
void MemLeakDetection()
{
#define MEMORY_LEAK_LINE  -1

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(MEMORY_LEAK_LINE);
}
#endif

int main()
{
	MemLeakDetection();

	Main_Menu main;
	main.BeginMenu();
	

	return 0;
}