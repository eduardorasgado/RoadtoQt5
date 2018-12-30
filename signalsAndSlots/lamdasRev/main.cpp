#include <iostream>

using namespace std;

void lambdaCall();

int main()
{
    /*
     * [capture list](parameter list) ->return_type { function body }
    */
    // Giving lambda function a name
    auto presenter = [](auto name){
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

    // capture list use: we can capture variables in the same scope lambda
    // function is
    int val1 = 7;
    int val2 = 5;

    [val1, val2](){
        std::cout << " value 1 is: " << val1 << std::endl;
        std::cout << " value 2 is: " << val2 << std::endl;
    }();

    //----------------------------
    // Capture llist + return type + param list
    int c = 33;
    auto coolFunction = [c](int v1, int v2)->int{
        std::cout << "The value of c is: " << c <<std::endl;
        return c * v1 * v2;
    }(val1, val2);

    std::cout << "cool function is: " << coolFunction << std::endl;
    //----------------------------
    // Capturing by value

    auto func2 = [c](){
        std::cout << "The inner value of c is: " << c << std::endl;
    };

    for(int i = 1; i < 5; ++i)
    {
        std::cout << "The outer value of c is: " << c << std::endl;
        func2();
        ++c;
    }

    //----------------------------
    std::cout << "---------------------------" << std::endl;
    // Capturing by reference: Lambda takes a copy of the value to capture list
    // an approach to  solve a problem like this is capturing the value by reference

    int w = 10;
    // passing the w address to lambda function
    auto func3 = [&w](){
        // now inside lammbda function we can modify w value
        std::cout << "The inner value of  is: " << w << std::endl;
    };

    for(int i = 1; i < 5; ++i)
    {
        std::cout << "The outer value of c is: " << w << std::endl;
        // calling lambda function
        func3();
        ++w;
    }

    //-----------------------------
    std::cout << "---------------------------" << std::endl;
    // capturing all values in the local scope, by value an by reference
    int age = 1000;
    int oxygen = 100;
    int love = 10;

    // = insiden capture list will let you capture all you need inside lambda
    // if you want to capture by value just use = instead of &
    auto changeAll = [&](){
        std::cout << "-age value inside: " << age << " ";
        std::cout << "-oxygen value inside: " << oxygen << " ";
        std::cout << "-love value inside: " << love << "\n";
    };

    for(int i = 0; i < 5; ++i)
    {
        std::cout << "|" << age << " | " << oxygen << " | " << love << "\n";
        changeAll();
        // incrementing at the same time
        ++age; ++oxygen; ++love;
    }

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
