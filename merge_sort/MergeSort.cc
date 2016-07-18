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
	for (int i : array)
	{
		std::cout << ident << i << std::endl;
	}
	//size_t n = array.size() / 2;
	//std::cout << ident << "n=" << n << std::endl;
	// base case
//	if (n == 0 || n == 1)
//	{
//		level--;
//		return result;
//	}
	level--;
	//std::sort(array.begin(), array.end());
	return array;
}
