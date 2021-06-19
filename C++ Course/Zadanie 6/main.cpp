#include <iostream>
#include <climits>
#include <cstdio>
#include "wymierna.hpp"

using namespace obliczenia;

int main()
{
    Wymierna a(9, 11);
    Wymierna b(-1, 2);
    std::cout << "a (9/11) = " << a << std::endl;
    std::cout << "b (-1/2) = " << b << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    std::cout << "a += b -> " << (a += b) << std::endl;
    std::cout << "a -= b -> " << (a -= b) << std::endl;
    std::cout << "a *= b -> " << (a *= b) << std::endl;
    std::cout << "a /= b -> " << (a /= b) << std::endl;

    std::cout << "-a = " << -a << std::endl;
    std::cout << "!b = " << !b << std::endl;

    std::cout << "zamiana b na int: " << (int)b << std::endl;
    std::cout << "zamiana b na double: " << (double)b << std::endl;
    
}