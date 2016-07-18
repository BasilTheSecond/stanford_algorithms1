#include "MergeSort.h"
#include <algorithm>
#include <iostream>

//
int MergeSort::level = 0;

//
MergeSort::MergeSort()
{	
}

//
std::vector<int>& MergeSort::merge(std::vector<int>& array)
{
	level++;
	std::string ident;
	for (int i = 0; i < level; i++)
	{
		ident += " ";
	}
	std::cout << ident << "array=" << std::endl;
	for (int i : array)
	{
		std::cout << ident << i << std::endl;
	}
	size_t n = array.size() / 2;
	// base case
	if (n == 0)
	{
		level--;
		return array;
	}
	// recursion case
	std::vector<int> array1;
	std::vector<int> array2;
	size_t i = 0;
	for (; i < n; i++)
	{
		array1.push_back(array[i]);
	}
	for (; i < array.size(); i++)
	{
		array2.push_back(array[i]);
	}
	merge(array1);
	merge(array2);
	level--;
	return array;
}
