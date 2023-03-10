#include <fstream>
#include <iostream>

class FileWasNotOpenedException: public std::exception {
};

int read_int_from_file(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        throw FileWasNotOpenedException();
    }
    int result;
    infile >> result;
    infile.close();
    return result;
}

int main() {
    try {
        std::cout << read_int_from_file("in.txt");
    } catch (const FileWasNotOpenedException &e) {
        std::cout << "can't open file";
    }
    return 0;
}
