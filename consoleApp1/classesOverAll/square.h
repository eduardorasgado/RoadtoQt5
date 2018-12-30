#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square(int& side): Rectangle{side, side}
    { std::cout << "Square class created" << std::endl; }
};

#endif // SQUARE_H
