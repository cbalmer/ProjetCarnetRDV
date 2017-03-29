#ifndef Heure_h
#define Heure_h

#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

///Structure uniquement utilisée pour l'ajout d'une durée à un horaire via les opérateurs
struct Duree
{
	int h, m;
	Duree(int ch, int cm): h{ch}, m{cm} {}
};


class Horaire
{
	public:
		//heure actuelle
		Horaire();
		//heure manuelle
		Horaire(int h, int m);

		int heure() const;
		int minute() const;

		void heure(int h);
		void minute(int m);

		//décale l'heure (renvoit true si l'horaire à rebouclé)
		bool decaleHeure(int c);
		bool decaleMinute(int c);

		//renvoie l'horaire sous forme d'une chaine de type "HHhMM";
		std::string str() const;

		bool operator==(Horaire const& h) const;
		bool operator<(Horaire const& h)const;
		bool operator>(Horaire const& h)const;
		bool operator<=(Horaire const& h)const;
		bool operator>=(Horaire const& h)const;
		bool operator!=(Horaire const& h)const;


	private:
		int _heure, _minute;
};

#endif
