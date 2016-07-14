#include <iostream>
#include "Karatsuba.h"

// To test large integer multiplication
// use: http://www.javascripter.net/math/calculators/100digitbigintcalculator.htm

int main()
{
	std::cout << "Test1 " << std::endl;
	const std::string x1("5678");
	const std::string y1("1234");
	const std::string result1("7006652");
	if (Karatsuba::multiply(x1, y1) == result1)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	std::cout << "Test2 " << std::endl;
	const std::string x2("56");
	const std::string y2("1234");
	const std::string result2("69104");
	if (Karatsuba::multiply(x2, y2) == result2)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	std::cout << "Test3 " << std::endl;
	const std::string x3("5");
	const std::string y3("12345678");
	const std::string result3("61728390");
	if (Karatsuba::multiply(x3, y3) == result3)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	std::cout << "Test4 " << std::endl;
	const std::string x4("5678912345678");
	const std::string y4("12345678");
	const std::string result4("70110023209965279684");
	if (Karatsuba::multiply(x4, y4) == result4)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
	return 0;
}
