
#include <windows.h>


typedef void(*alert)();


int main()

{
	alert func = NULL;

	HINSTANCE h = LoadLibraryA("test_dll.dll");

	if (h)
	{
		func = (alert)GetProcAddress(h, "print");
	}

	if (NULL != func)
	{
		func();
	}

	FreeLibrary(h);

	return 0;
}
