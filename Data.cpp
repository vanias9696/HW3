#include "Data.hpp"

Data::Data()
{
	day = 0;
	month = 0;
	year = 0;
}

Data::~Data()
{

}

std::ostream& operator << (std::ostream &s, const Data &dat)
{
	s << "Data: " << dat.getDay() << "." << dat.getMonth() << "." << dat.getYear() << std::endl;
	return s;
}

std::istream& operator >> (std::istream &s, Data &dat)
{
	string str;

	s >> str;
	dat.Add(str);
	return s;
}

long int	Data::operator-(const Data &dat)
{
	long int y1 = 0;
	long int y2 = 0;

	if (year > dat.getYear())
	{
		for (long int i = dat.getYear(); i != year; ++i)
			y1 = leap(i) == 1 ? y1 + 366 : y1 + 365;
		y2 = 0;
	}
	else
	{
		for (long int i = year; i != dat.getYear(); ++i)
			y2 = leap(i) == 1 ? y2 + 366 : y2 + 365;
		y1 = 0;
	}
	for (int i = 1; i < month; ++i)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
			y1 += 30;
		else if (i == 2)
			y1 += 28 + leap(year);
		else
			y1 += 31;
	}
	for (int i = 1; i < dat.getMonth(); ++i)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
			y2 += 30;
		else if (i == 2)
			y2 += 28 + leap(dat.getYear());
		else
			y2 += 31;
	}
	y1 += day;
	y2 += dat.getDay();
	return (y1 - y2);
}

int		leap(long int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}

int		Data::Check(void)
{
	if (month > 12)
		return (0);
	if (day > 31)
		return (0);
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (0);
	if (month == 2 && day > 29)
		return (0);
	if (month == 2 && day == 29 && year % 400 != 0 && (year % 4 != 0 || year % 100 == 0))
		return (0);
	return (1);
}

void	Data::Add(string str)
{
	if (str.length() != 10)
	{
		std::cout << "Error format" << std::endl;
		return;
	}
	else if (((str[2] == '.' && str[5] == '.') || (str[2] == '-' && str[5] == '-')) &&
			isdigit(str[0]) && isdigit(str[1]) && isdigit(str[3]) && isdigit(str[4])
			&& isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]))
	{
		day = atoi(str.c_str());
		month = atoi(str.c_str() + 3);
		year = atoi(str.c_str() + 6);
		if (Check() == 0)
		{
			std::cout << "Error format" << std::endl;
			day = 0;
			month = 0;
			year = 0;
			return ;
		}
	}
	else if (str[4] == '.' && str[7] == '.' && isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3])
		&& isdigit(str[5]) && isdigit(str[6]) && isdigit(str[8]) && isdigit(str[9]))
	{
		year = atoi(str.c_str());
		month = atoi(str.c_str() + 5);
		day = atoi(str.c_str() + 8);
		if (Check() == 0)
		{
			day = 0;
			month = 0;
			year = 0;
			std::cout << "Error format" << std::endl;
			return ;
		}
	}
}
