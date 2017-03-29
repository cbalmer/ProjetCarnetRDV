#include "Horaire.h"

Horaire::Horaire(int h, int m): _heure{h}, _minute{m}
{}

Horaire::Horaire()
{
	char str[10];
	time_t t = time(NULL);

	strftime(str,10,"%H %M",localtime(&t));
	std::istringstream iss(str);
	iss >> _heure >> _minute;
}

int Horaire::heure() const {return _heure;}

int Horaire::minute() const {return _minute;}

void Horaire::heure(int h)
{
	_heure = h%24;
}

void Horaire::minute(int m)
{
	_minute = m%60;
}

bool Horaire::decaleHeure(int c)
{
	bool reboucle = (_heure + c >= 24);

	_heure = (_heure += c)%24;
	return reboucle;
}

bool Horaire::decaleMinute(int c)
{
	bool ajout = (c >= 0), reboucle = false;
	c = abs(c);

	if(ajout)
	{
		_minute += c;
		reboucle = decaleHeure(_minute/60);
		_minute %= 60;
	}
	else
	{
		_minute = abs(_minute -= c);
		reboucle = decaleHeure(-(_minute/60));
		_minute %= 60;
	}

	return reboucle;
}

std::string Horaire::str() const
{
	std::ostringstream oss;
	oss << _heure << "h" << std::setfill('0') << std::setw(2) << _minute;

	return oss.str();
}

bool Horaire::operator==(Horaire const& h) const
{
	return _heure == h._heure && _minute == h._minute;
}

bool Horaire::operator<(Horaire const& h) const
{
	return _heure == h._heure? _minute < h._minute : _heure < h._heure;
}

bool Horaire::operator>(Horaire const& h) const
{
	return _heure == h._heure? _minute > h._minute : _heure > h._heure;
}

bool Horaire::operator<=(Horaire const& h) const
{
	return *this < h || *this == h;
}

bool Horaire::operator>=(Horaire const& h) const
{
	return *this > h || *this == h;
}

bool Horaire::operator!=(Horaire const& h) const
{
	return !(*this == h);
}
