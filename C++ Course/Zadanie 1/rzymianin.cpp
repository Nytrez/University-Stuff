
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string roman_numeral(int number)
{

    const vector<pair<int, string>> rzym = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    int i = 12;
    string roman = "";
    while (number > 0)
    {
        int div = number / rzym[i].first;
        number = number % rzym[i].first;
        while (div--)
        {
            roman += rzym[i].second;
        }
        i--;
    }

    return roman;
}

int main(int argc, char *argv[])
{
    cout << endl;

    string str;
    size_t pos;
    int value;

    for (int i = 1; i < argc; i++)
    {
        try
        {
            str = argv[i];
            value = stoi(str, &pos, 10);
            if (pos == str.size())
            {
                if (value > 0 && value < 4000)
                {
                    cout << roman_numeral(value) << endl;
                }
                else
                {
                    clog << argv[i] << " - out of range argument\n";
                }
            }
        }
        catch (const invalid_argument &)
        {
            clog <<  argv[i] <<" - invalid argument\n";
        }
        catch (const out_of_range &)
        {
            clog << argv[i] << " - argument out of int range \n";
        }
    }

    cout << endl;

    return 0;
}