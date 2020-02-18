#include <iostream>

#include "searchbar/SearchBar.h"

int
main()
{
    SearchBar searchBar;
    std::cout << searchBar.process(10, 2000, 0) << std::endl;
    return EXIT_SUCCESS;
}
