#include <memory>

struct Point
{
	Point(int i = 0, int j = 0) :x(i), y(j) {}
	int x;
	int y;
};

int main()
{
	std::unique_ptr<Point> spPoint1(new Point(1, 1)); 
	spPoint1.get();
	spPoint1.reset();
	auto i = spPoint1->x;
}