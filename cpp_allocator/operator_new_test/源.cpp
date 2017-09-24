// tested on vs 2015 by beenkinger

#include <new>
#include <iostream>

void handler()
{
	std::cout << "Memory allocation failed in MY handler(), terminating\n";
	std::set_new_handler(nullptr);
}

class A 
{
public:
	A() :_a(0)
	{ 
		std::cout << "Construct A()" << std::endl; 
		//throw std::exception();
	}

	A(int i) :_a(i) 
	{
		std::cout << "Construct A(int)" << std::endl;
		//throw std::exception();
	}

	~A(){ std::cout << "A Deconstruct" << std::endl; }

public:

#pragma region operator new

	// throwing new
	static void* operator new(size_t size) throw (std::bad_alloc)
	{
		std::cout << "throwing allocation" << std::endl;
		void *p;
		while (((p = malloc(size)) == 0))
		{
			std::new_handler new_handler_call = std::get_new_handler(); //cpp11
			if (new_handler_call != nullptr)
			{
				new_handler_call();
			}
			else
			{
				throw std::bad_alloc();
			}
		}
		return p;
	}

	// nothrow new
	static void* operator new (std::size_t size, const std::nothrow_t& nothrow_value) throw()
	{
		std::cout << "nothrow allocation" << std::endl;
		void *p;
		while ((p = malloc(size)) == 0)
		{
			std::new_handler new_handler_call = std::get_new_handler();
			if (new_handler_call != nullptr)
			{
				new_handler_call();
			}
			else
			{
				return nullptr;
			}
		}
		return p;
	}

	// placement new
	static void* operator new (std::size_t size, void* ptr) throw()
	{
		std::cout << "placement new" << std::endl;
		return ptr;
	}

	// custom new
	static void* operator new(std::size_t size, int extra)
	{
		std::cout << "custom new" << std::endl;
		//return operator new(size + extra);
		void *p = nullptr;
		while (((p = malloc(size + extra)) == 0))
		{
			std::new_handler new_handler_call = std::get_new_handler();
			if (new_handler_call != nullptr)
			{
				new_handler_call();
			}
			else
			{
				throw std::bad_alloc();
			}
		}
		return p;
	}

#pragma endregion


#pragma region operator new[]

	// throwing array new
	static void* operator new[](size_t size)
	{
		std::cout << "throwing array allocation" << std::endl;
		void *p = nullptr;
		while ((p = malloc(size)) == 0)
		{
			std::new_handler new_handler_call = std::get_new_handler();
			if (new_handler_call != nullptr)
			{
				new_handler_call();
			}
			else
			{
				throw std::bad_alloc();
			}
		}
		return p;
	}

    // nothrow array new
	static void* operator new[](size_t size, const std::nothrow_t& nothrow_value) throw()
	{
		std::cout << "nothrow array allocation" << std::endl;
		void *p = nullptr;
		while ((p = malloc(size)) == 0)
		{
			std::new_handler new_handler_call = std::get_new_handler();
			if (new_handler_call != nullptr)
			{
				new_handler_call();
			}
			else
			{
				return nullptr;
			}
		}
		return p;
	}

	// placement array new
	static void* operator new[] (std::size_t size, void* ptr) throw()
	{
		std::cout << "placement array new" << std::endl;
		return ptr;
	}

	// custom array new
	static void* operator new[] (std::size_t size, int extra)
	{
		std::cout << "custom array new" << std::endl;
		//return operator new(size + extra);
		void *p = nullptr;
		while (((p = malloc(size + extra)) == 0))
		{
			std::new_handler new_handler_call = std::get_new_handler();
			if (new_handler_call != nullptr)
			{
				new_handler_call();
			}
			else
			{
				throw std::bad_alloc();
			}
		}
		return p;
	}

#pragma endregion


#pragma region operator delete

	//ordinary  (1)
	void operator delete (void* ptr) throw ()
	{
		std::cout << "ordinary delete" << std::endl;
		free(ptr);
	}

	//nothrow (2)	
	void operator delete (void* ptr, const std::nothrow_t& nothrow_value) throw()
	{
		std::cout << "nothrow delete" << std::endl;
		free(ptr);
	}

	//placement (3)
	void operator delete (void* ptr, void* place) throw()
	{
		std::cout << "palcement delete" << std::endl;
	}

	//costom (4)
	void operator delete (void* ptr, int extra) throw()
	{
		std::cout << "custom delete" << std::endl;
		free(ptr);
	}

#pragma endregion


#pragma region operator delete[]

	//ordinary  (1)
	void operator delete[] (void* ptr) throw ()
	{
		std::cout << "ordinary delete[]" << std::endl;
		free(ptr);
	}

	//nothrow (2)	
	void operator delete[] (void* ptr, const std::nothrow_t& nothrow_value) throw()
	{
		std::cout << "nothrow delete[]" << std::endl;
		free(ptr);
	}

	//placement (3)
	void operator delete[] (void* ptr, void* place) throw()
	{
		std::cout << "palcement delete[]" << std::endl;
	}

	//costom (4)
	void operator delete[] (void* ptr, int extra) throw()
	{
		std::cout << "custom delete[]" << std::endl;
		free(ptr);
	}

#pragma endregion



public:
	void print()
	{
		std::cout << _a << std::endl;
	}

private:
	int _a;
};

int main()
{
	try {
		A* pa = new A();					 // throwing
		A* pb = new(std::nothrow) A(1);		 // nothrow
		A* pc = new(pa) A(2);				 // placement new
		A* pd = new(8) A(3);				 // custom new

		//pa->A::~A();// 都可以
		//pa->A::A(); //vs可以，gnu不可以，不建议使用

		pa->print(); //2
		pb->print(); //1
		pc->print(); //2
		pd->print(); //3

		delete pa;
		delete pb;
		// delete pc; // crash becase of pa == pc
		delete pd;
	}
	catch (const std::exception& e)
	{
		std::cout << "xxxxxxxx" << std::endl;
	}
	
	

	

	


	//std::set_new_handler(handler);

	//// throwing new array
	//try {
	//	while (true) {
	//		new A[100000000ul];   // throwing overload
	//	}
	//}
	//catch (const std::bad_alloc& e) {
	//	std::cout << e.what() << '\n';
	//	//std::abort();
	//}

	/// nothrow new array
	/*int i = 6;
	while (i--) {
		if (nullptr == new(std::nothrow) A[100000000ul])
			std::cout << "bad allocation" << std::endl;
	}*/

	return 0;
}


