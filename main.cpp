#include "Data.hpp"

int main(void)
{
	Data d1;
	Data d2;
	Data d3;
	Data d4;

	d1.Add("02.12.2005");
	d2.Add("15-10-2008");
	d3.Add("1456.12.24");

	std::cout << "Enter data:";
	std::cin >> d4;


	std::cout << "Data 1: " << d1;
	std::cout << "Data 2: " << d2;
	std::cout << "Data 3: " << d3;
	std::cout << "Data 4: " << d4;

	std::cout << "Data 2 - Data 3 :" << d2 - d3 << std::endl;

	return 0;
}