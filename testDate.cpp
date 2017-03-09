#include <iostream>
#include "Date.h"

int main()
{
	std::setlocale(LC_ALL, "");
	Date d(8,4,1996);

	std::cout << d.str() << std::endl;
}