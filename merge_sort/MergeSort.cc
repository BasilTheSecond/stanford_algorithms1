#include "MergeSort.h"
#include <algorithm>

//
MergeSort::MergeSort()
{	
}

//
std::vector<int>& MergeSort::merge(const std::vector<int>& array, std::vector<int>& result)
{
	result = array;
	std::sort(result.begin(), result.end());
	return result;
}
