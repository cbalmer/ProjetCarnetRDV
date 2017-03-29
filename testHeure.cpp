include <iostream>
#include "Horaire.h"

int main()
{
	Horaire h1{6,9}, h2{6,45};

	std::cout << (h1==h2) << std::endl;
	std::cout << (h1<h2) << std::endl;
	std::cout << (h1>h2) << std::endl;
	return 0;
}
