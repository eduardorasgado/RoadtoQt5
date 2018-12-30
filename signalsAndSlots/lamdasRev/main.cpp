#include <iostream>

using namespace std;

void lambdaCall();

int main()
{
    /*
     * [capture list](parameter list) ->return_type { function body }
    */
    // Giving lambda function a name
    auto presenter = [](std::string name){
        std::cout << "[LAMBDAS REVIEW]: " << name << std::endl;
    };

    // calling a variable contains a lambda function
    presenter("Eduardo");

    //-------------------------------
    lambdaCall();

    //-------------------------------
    //lambdas with params
    [](int a,int b){
        std::cout << "a + b: " << a + b << std::endl;
    }(5, 10);

    //-------------------------------
    int x = 800;
    int y = 600;
    // define a lambda that returns something
    // -> int is the return value type
    int addition = [](int a, int b) ->int {
        return a + b;
    }(x, y);

    std::cout << addition << std::endl;

    // call a lambda in the middle of another operation
    std::cout << [](int a, int b) ->int { return a * b; }(2, 3) << std::endl;

    //----------------------------

    // capture list use
    int val1 = 7;
    int val2 = 5;

    [val1, val2](){
        std::cout << " value 1 is: " << val1 << std::endl;
        std::cout << " value 2 is: " << val2 << std::endl;
    }();

    return 0;
}

void lambdaCall()
{
    /*
    * Doing something then call a lambda
    */
    // a lambda function calling himself
    // anonymous lambda
    [](){
        std::cout << "[MODERN C++]" << std::endl;
    }();
}
