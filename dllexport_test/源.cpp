//#include "print_fun.h"

extern "C" 
{
	__declspec(dllimport) void print();
}

using namespace std;

//#define DLL_EXPORT

int main()
{
	print();
}
