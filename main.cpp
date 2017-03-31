#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    //std::cout << time(NULL);return 0;
    setlocale(LC_ALL,"");
    CarnetRDV* carnet = new CarnetRDV();
    if(!CarnetRDV::initialisation())
    {
        std::cerr << "Connexion à la base de données impossible.\n";
        return 1;
    }

    if(!carnet->import())
    {
        std::cerr << "L'import s'est mal passé:\n" << mysql_error(&CarnetRDV::mysql);
        pause();
    }

    cli(carnet);

    return 0;
}
