#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "MergeSort.h"

//
static std::vector<int>& order(const std::vector<int>& array, std::vector<int>& order);

//
int main()
{
	std::cout << "Test1 " << std::endl;
	std::vector<int> array1;
	std::vector<int> result1;
	array1.push_back(4);
	array1.push_back(3);
	array1.push_back(5);
	array1.push_back(1);
	array1.push_back(2);
	array1.push_back(6);
	if (order(array1, result1) == MergeSort::sort(array1))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	std::cout << "Test2 " << std::endl;
	std::vector<int> array2;
	std::vector<int> result2;
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
	if (order(array2, result2) == MergeSort::sort(array2))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
//	std::cout << "Test3 " << std::endl;
//	std::vector<int> array3;
//	std::vector<int> result3;
//	std::ifstream file3("_bcb5c6658381416d19b01bfc1d3993b5_IntegerArray.txt");
//	if (!file3.is_open())
//  {
//		std::cout << "FAIL" << std::endl;
//  }
//	else
//	{
//		std::string line;
//		while (getline(file3, line))
//    {
//      array3.push_back(std::stoi(line, nullptr, 10));	
//    }
//		if (order(array3, result3) == MergeSort::sort(array3))
//		{
//			std::cout << "OK" << std::endl;
//		}
//		else
//		{
//			std::cout << "FAIL" << std::endl;
//		}
//	}
	return 0;
}

//
static std::vector<int>& order(const std::vector<int>& array, std::vector<int>& correct)
{
	correct = array;
	std::sort(correct.begin(), correct.end());
	return correct;
}
