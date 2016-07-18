#include "NumberOfInversions.h"
#include <algorithm>
#include <iostream>

//
int NumberOfInversions::level = 0;

//
NumberOfInversions::NumberOfInversions()
{	
}

//
int NumberOfInversions::inversions(std::vector<int>& array)
{
	level++;
	std::string ident;
	for (int i = 0; i < level; i++)
	{
		ident += "-";
	}
//	std::cout << ident << "unsorted=" << std::endl;
//	for (int i : array)
//	{
//		std::cout << ident << i << std::endl;
//	}
	size_t n = array.size();
	size_t n_2 = n / 2;
	// base case
	if (n_2 == 0)
	{
//		std::cout << ident << "sorted=" << std::endl;
//		for (int i : array)
//		{
//			std::cout << ident << i << std::endl;
//		}
		level--;
		return 0;
	}
	// recursion case
	std::vector<int> array1;
	std::vector<int> array2;
	size_t i = 0;
	for (; i < n_2; i++)
	{
		array1.push_back(array[i]);
	}
	for (; i < n; i++)
	{
		array2.push_back(array[i]);
	}
	int x = NumberOfInversions::inversions(array1);
	int y = NumberOfInversions::inversions(array2);
	int z = 0;
	// Merge
	array.clear();
	for (size_t i = 0, j = 0, k = 0; i < n; i++)
	{
		if ((j < array1.size()) && (array1[j] < array2[k]))
		{
			array.push_back(array1[j++]);
		}
		else if (k < array2.size())
		{
			array.push_back(array2[k++]);
		}
	}
//	std::cout << ident << "sorted=" << std::endl;
//	for (int i : array)
//	{
//		std::cout << ident << i << std::endl;
//	}
	level--;
	return x + y + z;
}
