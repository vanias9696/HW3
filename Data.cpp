#include "Data.hpp"

Data::Data()
{
	D = NULL;
}

Data::~Data()
{
	dt *tmp;
	while(D != NULL)
	{
		tmp = D->next;
		delete D;
		D = tmp;
	}
}

int	Data::YMD(string str)
{
	if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3])
		&& isdigit(str[5]) && isdigit(str[6]) && isdigit(str[8]) && isdigit(str[9]))
	{
		if (str[5] > '1' || (str[5] == '1' && str[6] > '2') || (str[5] == '0' &&
		str[6] == '0') || str[8] > '3' || (str[8] == '3' && str[9] > '1') || (str[8] == '0' && str[9] == '0'))
		{
			std::cout << "Error format" << std::endl;
			return (0);
		}
		dt *temp = new dt;
		temp->year = atoi(str.c_str());
		temp->month = atoi(str.c_str() + 5);
		temp->day = atoi(str.c_str() + 8);
		temp->num = D == 0 ? 1 : (D->num + 1);
		temp->next = D;
		D = temp;
		return(1);
	}
	std::cout << "Error format" << std::endl;
	return (0);
}

std::ostream& operator << (std::ostream &s, const Data &dat)
{
	dt *tmp;

	tmp = dat.D;
	while(tmp != 0)
	{
		s << "Number " << tmp->num << " : " << tmp->day << "." << tmp->month << "." << tmp->year << std::endl;
		tmp = tmp->next;
	}
	return s;
}



std::istream& operator >> (std::istream &s, Data &dat)
{
	dt *temp = new dt;
	std::cout << "Input year:\n";
	std::cin >> temp->year;
	std::cout << "Input month:\n";
	std::cin >> temp->month;
	std::cout << "Input day:\n";
	std::cin >> temp->day;
	temp->num = dat.D == NULL ? 1 : dat.D->num + 1;
	temp->next = dat.D;
	dat.D = temp;
	return s;
}

int	Data::DMY(string str)
{
	if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[3]) && isdigit(str[4])
		&& isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]))
	{
		if (str[3] > '1' || (str[3] == '1' && str[4] > '2') || (str[3] == '0' &&
		str[4] == '0') || str[0] > '3' || (str[0] == '3' && str[1] > '1') || (str[0] == '0' && str[1] == '0'))
		{
			std::cout << "Error format" << std::endl;
			return (0);
		}
		dt *temp = new dt;
		temp->day = atoi(str.c_str());
		temp->month = atoi(str.c_str() + 3);
		temp->year = atoi(str.c_str() + 6);
		temp->num = D == 0 ? 1 : (D->num + 1);
		temp->next = D;
		D = temp;
		return(1);
	}
	std::cout << "Error format" << std::endl;
	return (0);
}

int	Data::Add(string str)
{
	if (str.length() != 10)
		;
	else if ((str[2] == '.' && str[5] == '.') || (str[2] == '-' && str[5] == '-'))
		return(DMY(str));
	else if (str[4] == '.' && str[7] == '.')
		return(YMD(str));
	std::cout << "Error format" << std::endl;
	return (0);
}

int	Data::nYMD(int n, string str)
{
	if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3])
		&& isdigit(str[5]) && isdigit(str[6]) && isdigit(str[8]) && isdigit(str[9]))
	{
		if (str[5] > '1' || (str[5] == '1' && str[6] > '2') || (str[5] == '0' &&
		str[6] == '0') || str[8] > '3' || (str[8] == '3' && str[9] > '1') || (str[8] == '0' && str[9] == '0'))
		{
			std::cout << "Error format" << std::endl;
			return (0);
		}
		if (D->num < n || n < 1)
		{
			std::cout << "This number does not exist." << std::endl;
			return (0);
		}
		dt *temp = D;
		temp->year = atoi(str.c_str());
		temp->month = atoi(str.c_str() + 5);
		temp->day = atoi(str.c_str() + 8);
		return(1);
	}
	std::cout << "Error format" << std::endl;
	return (0);
}

int	Data::nDMY(int n, string str)
{
	if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[3]) && isdigit(str[4])
		&& isdigit(str[6]) && isdigit(str[7]) && isdigit(str[8]) && isdigit(str[9]))
	{
		if (str[3] > '1' || (str[3] == '1' && str[4] > '2') || (str[3] == '0' &&
		str[4] == '0') || str[0] > '3' || (str[0] == '3' && str[1] > '1') || (str[0] == '0' && str[1] == '0'))
		{
			std::cout << "Error format" << std::endl;
			return (0);
		}
		if (D->num < n || n < 1)
		{
			std::cout << "This number does not exist." << std::endl;
			return (0);
		}
		dt *temp = D;
		while(temp->num != n)
			temp = temp->next;
		temp->day = atoi(str.c_str());
		temp->month = atoi(str.c_str() + 3);
		temp->year = atoi(str.c_str() + 6);
		return(1);
	}
	std::cout << "Error format" << std::endl;
	return (0);
}

int	Data::Change(int num, string str)
{
	if (str.length() != 10)
		;
	else if ((str[2] == '.' && str[5] == '.') || (str[2] == '-' && str[5] == '-'))
		return(nDMY(num, str));
	else if (str[4] == '.' && str[7] == '.')
		return(nYMD(num, str));
	std::cout << "Error format" << std::endl;
	return (0);
}

