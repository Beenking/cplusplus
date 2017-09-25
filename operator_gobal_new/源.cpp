#include <iostream> 
#include <list>
#include <allocators>
#include <typeinfo>

long g_size = 0;
long g_times = 0;

void* operator new(size_t size)
{
    //std::cout << "My Operator New" << std::endl;
    g_size += size;
    ++g_times;

    return  malloc(size);
}

template<typename AllocType>
void allocator_test()
{
    std::cout << typeid(AllocType).name() << std::endl;
    std::list<double, AllocType> ld1;
    for (int i = 0; i < 1000000; ++i)
    {
        ld1.push_back(i);
    }
    std::cout << "Global Size: " << g_size << std::endl;
    std::cout << "Global Times: " << g_times << std::endl << std::endl;
    g_size = 0;
    g_times = 0;
}

int main()
{
    allocator_test<std::allocator<double>>();

    allocator_test<stdext::allocators::allocator_chunklist<double>>();

    allocator_test<stdext::allocators::allocator_fixed_size<double>>();

    allocator_test<stdext::allocators::allocator_unbounded<double>>();

    allocator_test<stdext::allocators::allocator_newdel<double>>();

    allocator_test<stdext::allocators::allocator_variable_size<double>>();

    allocator_test<stdext::allocators::allocator_suballoc<double>>();
}