#include "Data.hpp"

int main(void)
{
	Data Data;

	Data.Add("02.05.1995");
	Data.Add("15-10-2008");
	Data.Add("1456.12.24");

	//std::cin >> Data;

	std::cout << Data;
	Data.Change(1, "11.10.1946");
	std::cout << Data;

	return 0;
}