
#include <windows.h>
#include <iostream>


typedef void(*alert)();


int main()

{
	alert func = NULL;

	HINSTANCE h = LoadLibraryExA("test_dll.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

	if (h)
	{
		func = (alert)GetProcAddress(h, "print");
		if (NULL != func)
		{
			func();
		}
	}
	else
	{
		std::cout << GetLastError();
	}

	FreeLibrary(h);

	return 0;
}
