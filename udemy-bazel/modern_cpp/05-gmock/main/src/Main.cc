#include <cassert>
#include <iostream>

#include "ioutils/IOUtils.h"

using namespace std;

int
main(int argc, char **argv)
{
    assert(argc == 2);
    IOUtils ioutils;
    string baseDir(argv[1]);
    string filter(".*\\.(h|cc)$");
    for (auto &filename : ioutils.list(baseDir, filter)) {
        cout << "FOUND FILE " << filename << endl;
    }
    return EXIT_SUCCESS;
}
