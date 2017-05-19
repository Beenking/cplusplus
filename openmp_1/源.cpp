#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void test()
{
	int a = 0;
	clock_t start = clock();
	for (int i = 0; i < 100000000; i++)
	{
		a = i + 1;
	}
	clock_t end = clock();
	printf("one test time: %d \n", end - start);
}

int main()
{
	clock_t t1 = clock();
#pragma omp parallel for
	for (int j = 0; j < 5; j++)
	{
		test();
	}
	clock_t t2 = clock();
	printf("total test time: %d \n", t2 - t1);

	test();

	return 0;
}