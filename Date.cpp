
#include "Date.h"


Date::Date(): _time(time(NULL))
{}

Date::Date(int j, int m, int a)
{
	tm* d;//structure contenant des infos temporelles
	time_t t = time(NULL);//récupération du temps actuel

	d = localtime(&t);//initialisation de la structure tm
	/*
		ici on utilise cette fonction afin d'initialiser correctement tous les champs de la structure tm
	*/

	d->tm_year = a - 1900;
	d->tm_mon = m-1;
	d->tm_mday = j;
	/*
		on modifie certains champs de tm afin de les faire correspondre à la date voulue
	*/

	_time = mktime(d);//on récupère la date voulue sous forme de secondes écoulés depuis le 1er janvier 1970
}

std::string Date::jourSemaine() const
{
	char str[10];

	strftime(str,10,"%A",localtime(&_time));//on récupère du jour de la semaine correspondant à la date
	std::istringstream iss(str);

	std::string ret;
	iss >> ret;/*récupération du jour de la semaine via un flux sur chaine de caractères

	ici on utilise un flux
	*/
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
	char str[100] = {'\0'};

	strftime(str,100,"%A %d %B %Y",localtime(&_time));

	return std::string(str);
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

Date& Date::operator+=(int c)
{
	_time += 24*60*60*c;
	return *this;
}

Date& Date::operator-=(int c)
{
	_time -= 24*60*60*c;
	return *this;
}


bool Date::operator!=(Date const& d)const
{
    return !((*this)==d);
}

bool Date::operator==(Date const& d)const
{
    return jour() == d.jour() && mois()==d.mois() && annee()==d.annee();
}

