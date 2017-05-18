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

namespace Mcsf
{
	namespace AppPlugin
	{
		class C
		{
		public:
			void fun(ptrA a, B b, A::Ptr pa, std::shared_ptr<ANY::X> x)
			{

			}
		};
	}
}

int main()
{
	Mcsf::AppPlugin::C c;
	c;
	return 0;
}