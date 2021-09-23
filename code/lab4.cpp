#include <iostream>
#include <iomanip>
#include <cmath>

void iterMethod(double x0, double k, double eps);
void binaryMethod(double xl, double xr, double k, double eps);
void newthonMethod(double x0, double k, double eps);
void task1();
void task2();

const double k1 = 1;
const double k10 = 10;
const double eps6 = 0.000001;
const double eps8 = 0.00000001;

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

void task1()
{
    std::cout << "\t\tTASK №1\n";
    iterMethod(0, k1, eps6);
    binaryMethod(0, 1, k1, eps6);
    newthonMethod(0, k1, eps6);
    iterMethod(0, k1, eps8);
    binaryMethod(0, 1, k1, eps8);
    newthonMethod(0, k1, eps8);
}

void task2()
{
    std::cout << "\t\tTASK №2\n";
    iterMethod(0, k10, eps6);
    binaryMethod(-5, 5, k10, eps6);
    newthonMethod(0, k10, eps6);
    binaryMethod(-5, 5, k10, eps8);
    newthonMethod(0, k10, eps8);
}

void iterMethod(double x0, double k, double eps)
{
    int n = 0;
    double x = x0;
    do
    {
        x = k * cos(x);
        n++;

    } while (abs(x - k * cos(x)) > eps);

    std::cout << "Iteration method for k = " << k << " |  x: " << std::setprecision(10) << x << " n:" << n << " eps = " << eps << std::endl;
}
void binaryMethod(double xl, double xr, double k, double eps)
{
    int n = 0;
    double x;
    do
    {
        x = (xr + xl) / 2;
        n++;
        if ((x - k * cos(x)) * (xr - k * cos(xr)) < 0)
        {
            xl = x;
        }
        else
        {
            xr = x;
        }
    } while (abs(x - k * cos(x)) > eps);

    std::cout << "Binary method for k = " << k << " |  x: " << std::setprecision(10) << x << " n:" << n << " eps = " << eps << std::endl;
}
void newthonMethod(double x0, double k, double eps)
{
    int n = 0;
    double x = x0;
    do
    {
        x -= (x - k * cos(x)) / (1 + k * sin(x));
        n++;
    } while (abs(x - k * cos(x)) > eps);

    std::cout << "Newthon method for k = " << k << " |  x: " << std::setprecision(10) << x << " n:" << n << " eps = " << eps << std::endl;
}