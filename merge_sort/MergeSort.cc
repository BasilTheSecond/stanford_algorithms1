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
std::vector<int>& MergeSort::sort(std::vector<int>& array)
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
	size_t n = array.size();
	size_t n_2 = n / 2;
	// base case
	if (n_2 == 0)
	{
		level--;
		return array;
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
	sort(array1);
	sort(array2);
	// Merge
	array.clear();
	for (size_t i = 0; i < n; i++)
	{
		
	}
	level--;
	return array;
}
