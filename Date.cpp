
#include "Date.h"


Date::Date(): _time(time(NULL))
{}

std::string Date::jourSemaine() const
{
	char str[10];

	strftime(str,10,"%A",localtime(&_time));
	std::istringstream iss(str);

	std::string ret;
	iss >> ret;

	return ret;
}

int Date::annee() const
{
	char str[5];
	strftime(str,5,"%Y",localtime(&_time));
	std::istringstream iss(str);

	int y;
	iss >> y;

	return y;
}

int Date::mois() const
{
	char str[3];
	strftime(str,3,"%m",localtime(&_time));
	std::istringstream iss(str);

	int m;
	iss >> m;

	return m;
}

int Date::jour() const
{
	char str[3];
	strftime(str,3,"%d",localtime(&_time));
	std::istringstream iss(str);

	int j;
	iss >> j;

	return j;
}

std::string Date::str() const
{
	char str[100];

	strftime(str,100,"%A %d %B %Y",localtime(&_time));
	std::istringstream iss(str);

	std::string ret, b;
	iss >> ret;
	ret += " ";
	iss >> b;
	ret += b;
	ret += " ";
	iss >> b;
	ret += b;
	ret += " ";
	iss >> b;
	ret += b;

	return ret;
}

Date& Date::operator++()
{
	_time += 24*60*60;
	return *this;
}

Date Date::operator++(int)
{
	return ++(*this);
}

Date& Date::operator--()
{
	_time -= 24*60*60;
	return *this;
}

Date Date::operator--(int)
{
	return --(*this);
}



