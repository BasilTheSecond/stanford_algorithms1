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
	std::cout << "Test2 " << std::endl;
	std::vector<int> array2;
	array2.push_back(96);	
	array2.push_back(99);	
	array2.push_back(63);
	array2.push_back(16);	
	array2.push_back(75);
	array2.push_back(46);	
	array2.push_back(70);	
	array2.push_back(24);	
	array2.push_back(3);	
	array2.push_back(85);
	array2.push_back(38);	
	array2.push_back(60);
	array2.push_back(65);	
	array2.push_back(76);	
	array2.push_back(14);
	array2.push_back(22);	
	array2.push_back(61);	
	array2.push_back(35);	
	array2.push_back(62);	
	array2.push_back(69);
	std::vector<int> correct2 = array2;
	std::sort(correct2.begin(), correct2.end());
	std::vector<int> result2;
	MergeSort::merge(array2, result2);
	if (result2 == correct2)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	return 0;
}
