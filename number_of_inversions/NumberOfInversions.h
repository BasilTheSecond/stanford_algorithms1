#ifndef NUMBEROFINVERSIONS_H
#define NUMBEROFINVERSIONS_H

#include <vector>
#include <cstdint>

class NumberOfInversions
{
public:
	NumberOfInversions();

public:
	static uint64_t inversions(std::vector<int>& array);
	
private:
	static int level;
};

#endif // NUMBEROFINVERSIONS_H
