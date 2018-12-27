#ifndef DATA_H
# define DATA_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class Data
{
	public:
		Data();
		~Data();
		void	Add(string str);
		int		getDay() const 		{return (day);};
		int		getMonth() const	{return (month);};
		int		getYear() const		{return (year);};
		long int        operator-(const Data &dat);
	private:
		int 	day;
		int 	month;
		int 	year;
		int		Check(void);
};

#endif

std::istream& operator >> (std::istream &s, Data &dat);
std::ostream& operator << (std::ostream &s, const Data &dat);
int		leap(long int year);
