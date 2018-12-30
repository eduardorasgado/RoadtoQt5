#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
private:
    int width;
    int length;
public:
    Rectangle(): width{5}, length{5}
    {
        std::cout << "Setting default params" << std::endl;
    }
    Rectangle(int &width, int &length): width{width}, length{length}
    { std::cout << "Rectangle was created" << std::endl; }


    ~Rectangle() { std::cout << "object was destroyed" << std::endl; }

    // declaration
    void setWidth(int width);

    void setLength(int length);
    int getArea()
    {
        return width * length;
    }
};


#endif // RECTANGLE_H
