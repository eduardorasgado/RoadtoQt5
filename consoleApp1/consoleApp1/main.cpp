#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
    std::cout << "C++ running with Qt5!"
              << std::endl;

    std::vector<std::string> words;
    words.push_back("EDUARDO");

    std::vector<std::string>::iterator i = words.begin();

    std::ostream_iterator<std::string> salida(std::cout, " ");

    std::copy(i, words.end(), salida);
    std::cout << "\n";

    return 0;
}
