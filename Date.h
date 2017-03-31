#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <ctime>

class Date
{
	public:
		Date();
		Date(time_t t);
		Date(int j, int m, int a);

		std::string jourSemaine() const;
		int annee() const;
		int mois() const;
		int jour() const;
         time_t d_Time() const ;
		std::string str() const;

		//avance d'un jour
		Date& operator++();
		Date operator++(int);

		//recule d'un jour
		Date& operator--();
		Date operator--(int);

		Date& operator+=(int c);
		Date& operator-=(int c);

		bool operator!=(Date const& d)const;
		bool operator==(Date const& d)const;

	private:
            time_t _time;
};

#endif
