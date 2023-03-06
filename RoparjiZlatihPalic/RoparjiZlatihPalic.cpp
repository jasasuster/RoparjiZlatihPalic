#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    std::ifstream infile(argv[1]);  // open file to read from

    int G;

    if (infile.is_open()) {   // checking whether the file is open
        while (infile >> G) {   // read line by line
            std::cout << G << "\n";
        }
    }
}
