#ifndef DATA_H
# define DATA_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct dt
{
	int num;
	int	day;
	int month;
	int year;
	dt	*next;
};

class Data
{
	public:
		Data();
		~Data();
		int Add(string str);
		int Change(int num, string str);
		dt	*D;

	private:
		int	DMY(string str);
		int	YMD(string str);
		int	nDMY(int n, string str);
		int	nYMD(int n, string str);
};

#endif

std::istream& operator >> (std::istream &s, Data &dat);
std::ostream& operator << (std::ostream &s, const Data &dat);