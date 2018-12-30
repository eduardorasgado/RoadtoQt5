#ifndef PARALLELPIPED_H
#define PARALLELPIPED_H

#include <iostream>
#include "rectangle.h"

class Parallelpiped
{
private:
    Rectangle r;
    int height;

public:
    Parallelpiped(int &w, int &l, int &h): r{w, l}, height{h}
    { std::cout << "A parallelpiped has been created" << std::endl; }

    int getVolume();
};


#endif // PARALLELPIPED_H
