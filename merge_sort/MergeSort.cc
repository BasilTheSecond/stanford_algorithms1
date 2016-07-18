#include "MergeSort.h"
#include <algorithm>

//
int MergeSort::level = 0;

//
MergeSort::MergeSort()
{	
}

//
std::vector<int>& MergeSort::merge(const std::vector<int>& array, std::vector<int>& result)
{
	level++;
	std::string ident;
	for (int i = 0; i < level; i++)
	{
		ident += " ";
	}
	result = array;
	//std::cout << ident << std::endl;
	// base case
	if (0)
	{
		level--;
		return result;
	}
	level--;
	return result;
}
