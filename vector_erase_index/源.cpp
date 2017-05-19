#ifndef  CHECK_INDEX_RANGE
#define  CHECK_INDEX_RANGE(index, vec)      \
if (index < 0 || index >= vec.size())                     \
{                                           \
    cout << "(1 , std::string(typeid(vec).name()) + std::string(" ") + std::string(#vec) +  is out of range.)";\
}
#endif


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//int main()
//{
//	vector<int> vi{ 1,2,3,4,5 };
//	vi.erase(vi.begin() + 1);
//
//	for (auto i = vi.cbegin(); i != vi.end(); ++i)
//	{
//		std::cout << *i << endl;
//	}
//	return 0;
//}

//int main()
//{
//	vector<int> vi{ 1,2,3,4,5,6 };
//	int mutiply = 2;
//	for_each(vi.cbegin(), vi.cend(), [=](int i) {
//		std::cout << mutiply * i << endl;
//	});
//}

//int main()
//{
//	vector<int> vi{ 1,2,3,4,5 };
//	vi.insert(vi.begin() + 5, 6);
//	//vi.insert(vi.begin(), 0);
//	//vi.insert(vi.end(), 6);
//
//	for_each(vi.cbegin(), vi.cend(), [](int i) {
//				std::cout << i << endl;
//			});
//}



int main()
{
	vector<int> vi{ 1,2,3,4,5 };
	CHECK_INDEX_RANGE(7, vi);
	vi.at(7) = 7;

	for_each(vi.cbegin(), vi.cend(), [](int i) {
				std::cout << i << endl;
			});
}