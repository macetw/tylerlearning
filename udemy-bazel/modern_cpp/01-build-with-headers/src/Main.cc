#include <iostream>

#include "Calculator.h"

int
main()
{
    Calculator calculator;
    std::cout << "3 + 2 = " << calculator.plus(3, 2) << std::endl;

    return EXIT_SUCCESS;
}
