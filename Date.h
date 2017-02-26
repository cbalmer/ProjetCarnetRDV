#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <ctime>

class Date
{
	public:
		Date();

		std::string jourSemaine() const;
		int annee() const;
		int mois() const;
		int jour() const;

		std::string str() const;

		Date& operator++();
		Date operator++(int);

		Date& operator--();
		Date operator--(int);

	private:
		time_t _time;
};

#endif