#include <iostream>
#include <memory>

#include "data_type.h"

namespace ANY
{
	class Y
	{

	};
	class X;
}

namespace std {
	namespace Mcsf
	{
		namespace AppPlugin
		{
			class C
			{
			public:
				// can use std, Mcsf, AppPlugin namespace
				void fun(ptrA a, B b, A::Ptr pa, std::shared_ptr<ANY::X> x)
				{
					cout << "namespace test";
				}
			};
		}
	}
}

int main()
{
	std::Mcsf::AppPlugin::C c;
	c;
	return 0;
}