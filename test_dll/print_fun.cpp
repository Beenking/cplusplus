#define DLL_EXPORT

#include "print_fun.h"
#include <iostream>


extern "C"

{

	DECLDIR void print()

	{

		std::cout <<  "Hello,World!";

	}

}