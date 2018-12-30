#include <iostream>
#include <memory>
#include "rectangle.h"
#include "parallelpiped.h"

template< typename T>
inline void print(T A) { std::cout << A << std::endl; }

template <typename T>
inline std::string stringify(T A) { return std::to_string(A); }


std::shared_ptr<Rectangle> getRectangle(int&, int&);

int main()
{
    int w = 10;
    int l = 20;
    int h = 10;

    // Creating rectangles
    auto myRect = getRectangle(w, l);

    print("Second time we need area: "+ stringify(myRect->getArea()));

    Rectangle r2;
    print(r2.getArea());

    // Creating para...
    Parallelpiped p1{w, l, h};

    print("The parallelpiped  volume is: " + stringify(p1.getVolume()));

    return 0;
}

std::shared_ptr<Rectangle> getRectangle(int &w, int &l)
{
    auto myRectangle = std::make_shared<Rectangle>(w, l);
    print(myRectangle->getArea());

    return myRectangle;
}
