#ifndef DATE_H
#define DATE_H

#include <string>
#include <map>

class Date
{

	public:static Date aujourdhui();

	public:
		Date();
		Date(int jour, int mois, int annee);

		std::string nomJour() const;
		int annee() const;
		int mois() const;
		int jour() const;

		std::string affiche() const;

	private:static std::map<int,string> nomJour;
	private:
		int _annee;
		int _mois;
		int _jour;
		int _jourSemaine;
};

#endif