#include <iostream>
#include "Date.h"

int main()
{
    Date date;

    std::cout << date.str() << std::endl;
    date++;
    std::cout << date.str() << std::endl;
    ++date;
	std::cout << date.str() << std::endl;
	date--;
	--date;
	std::cout << date.str() << std::endl;
    return 0;
}
