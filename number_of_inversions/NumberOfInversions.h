#ifndef NUMBEROFINVERSIONS_H
#define NUMBEROFINVERSIONS_H

#include <vector>

class NumberOfInversions
{
public:
	NumberOfInversions();

public:
	static int inversions(std::vector<int>& array);
	
private:
	static int level;
};

#endif // NUMBEROFINVERSIONS_H
