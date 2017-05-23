#include <iostream>

enum Day
{
	Monday = 1,
	Tus = 2,
};

int main()
{
	Day day1 = Day::Monday;
	std::cout << day1 << std::endl;
	Day day2 = (Day)3;
	std::cout << day2 << std::endl;
}