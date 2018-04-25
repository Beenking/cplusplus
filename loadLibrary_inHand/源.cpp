
#include <windows.h>
#include <iostream>


typedef void(*alert)(int i);


int main()
{
	HINSTANCE h = LoadLibraryExA("../x64/Debug/test_dll.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

	if (h)
	{
		auto func = (alert)GetProcAddress(h, "MyPrint");
		if (NULL != func)
		{
			func(2);
		}
	}
	else
	{
		std::cout << GetLastError();
	}

	FreeLibrary(h);

	return 0;
}
