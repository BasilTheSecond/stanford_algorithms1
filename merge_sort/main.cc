#include <iostream>
#include <algorithm>
#include "MergeSort.h"

int main()
{
	std::cout << "Test1 " << std::endl;
	std::vector<int> array1;
	array1.push_back(4);
	array1.push_back(3);
	array1.push_back(5);
	array1.push_back(1);
	array1.push_back(2);
	array1.push_back(6);
	std::vector<int> correct1 = array1;
	std::sort(correct1.begin(), correct1.end());
	std::vector<int> result1;
	MergeSort::merge(array1, result1);
	if (result1 == correct1)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	return 0;
}
