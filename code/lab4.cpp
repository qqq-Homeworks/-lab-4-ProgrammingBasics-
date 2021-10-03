#include <iostream>
#include <iomanip>
#include <cmath>
#include "functions.h"

int main()
{
    task1();
    task2();

    int paragraph = 0;
    double x0, k, eps, xr, xl;
    std::cout << "\t\tMENU\n1. Simple iterations\n2. Binary method\n3. Newthon method\n";
    std::cout << "\t\tEnter number of needed method:\n";
    std::cin >> paragraph;
    switch (paragraph)
    {

    case 1:
    {
        std::cout << "x0 k eps\n";
        std::cin >> x0 >> k >> eps;
        iterMethod(x0, k, eps);
    }
    break;

    case 2:
    {
        std::cout << "xr xl k eps\n";
        std::cin >> xr >> xl >> k >> eps;
        binaryMethod(xr, xl, k, eps);
    }
    break;

    case 3:
    {
        std::cout << "x0 k eps\n";
        std::cin >> x0 >> k >> eps;
        newthonMethod(x0, k, eps);
    }
    break;

    default:
        break;
    }
    return 0;
}



