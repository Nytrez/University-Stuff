#include <iostream>
#include "tab_bit.hpp"
using namespace obliczenia;

auto main() -> int
{
    tab_bit tab1(32);
    tab_bit tab2(32);

    std::cout << "podaj dwie liczby w zapisie binarnym" << std::endl;
    std::cin >> tab1;
    std::cin >> tab2;

    std::cout << "tab1 = " << tab1 << std::endl;
    std::cout << "tab2 = " << tab2 << std::endl;
    std::cout << "tab1&tab2 = " << (tab1 & tab2) << std::endl;
    std::cout << "tab1^tab2 = " << (tab1 ^ tab2) << std::endl;
    std::cout << "tab1|tab2 = " << (tab1 | tab2) << std::endl;
    tab1|=tab2;
    std::cout << "tab1|=tab2 = " << tab1 << std::endl;
    tab2&=tab1;
    std::cout << "tab2&=tab1 = " << tab2 << std::endl;

    //bity sa zapisywane od najmłodszych -> najstarszych
    tab_bit test(uint64_t(15));
    std::cout << "test = " << test << std::endl;
    std::cout << "test[1] = " << test[4] << std::endl;
    std::cout << "test[2] = false" << std::endl;
    test[2] = false;
    std::cout << "test = " << test << std::endl
              << std::endl;

    tab_bit kopia(test);
    std::cout << " kopia (skopiowany test)" << kopia << std::endl;

    std::cout << std::endl
              << "zainicjowana wzorcem: " << std::endl;
    tab_bit zainicjowana({0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1});
    std::cout << zainicjowana << " rozmiar = " << zainicjowana.rozmiar() << std::endl;

    zainicjowana ^= zainicjowana;
    std::cout << "zainicjowana ^= zainicjowana = " << zainicjowana << std::endl;
    

    return 0;
}