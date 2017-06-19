#include <iostream>
#include <new>
#include <memory>
#include <exception>

class A
{
public:
	A()
	{
		//std::cout << "Class A constructor" << std::endl;
	}

	~A()
	{
		//std::cout << "Class A destructor" << std::endl;
	}

	void* operator new(size_t size)
	{
		std::cout << "custom operator new" << std::endl;
		return ::operator new(size);
	}

	void* operator new[](size_t size)
	{
		std::cout << "custom operator new[]" << std::endl;
		//return malloc(size);
		void* p  = ::operator new[](size);
		int n = *((int*)p);
		return p;
	}

private:
	int i = 0;
	//long long l = 0;
};

void new_handler()
{
	std::cout << "custom new handler" << std::endl;
	//throw bad_alloc();
	std::abort();
}

int main()
{
	//std::set_new_handler(new_handler);
	std::cout << sizeof(A) << std::endl;
	A* pa = new A[2];

	return 0;
}