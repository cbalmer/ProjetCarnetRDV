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

		//avance d'un jour
		Date& operator++();
		Date operator++(int);

		//recule d'un jour
		Date& operator--();
		Date operator--(int);

		Date& operator+=(int c);
		Date& operator-=(int c);

	private:
		time_t _time;
};

#endif
