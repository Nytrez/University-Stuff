#include <bits/stdc++.h>
#include "klasy.hpp"


using namespace std;

int main()
{
	punkt a = punkt(3,4), b = punkt(1,2), c = punkt(9,6);

	cout << "punkt a: ";
	a.print();
	cout << "punkt c: ";
	c.print();
	cout << "punkt b: ";
	b.print();


	cout << "przesuniecie punktu a o <8,8>: ";
	a.przesuniecie(8,8);
	a.print();
	cout << endl;
	cout <<"odleglosc punktu a od punktu b" << odleglosc(a,b) << endl;
	cout << endl;



	cout <<"Odcinek o: \n";
	Odcinek o = Odcinek(a,b);
	o.print();
	cout << "Dlugosc odcinka: " << o.dlugosc() << endl;
	cout << "czy punkt c lezy na odcinku?: ";
	if(o.czy_na_odcinku(c)){
	    cout<<"tak" << endl;
    }else {
    cout<<"nie"<<endl;
    }
    cout << "czy punkt <2,3> lezy na odcinku?: ";
    if(o.czy_na_odcinku(punkt(2,3))){
	    cout<<"tak" << endl;
    }else {
    cout<<"nie"<<endl;
    }
	cout << "Srodek odcinka o: ";
    o.srodek_odcinka().print();
    punkt p = o.srodek_odcinka();
    cout << "obrot wzgledem b o 90 stopni "<<endl;
    o.obrot(b,90);
    o.print();
	cout << endl;


	
	cout << "trojkat t: \n";
	trojkat t = trojkat(punkt(0,0), punkt(5,0), punkt(5,10));
	t.print();
	cout << "Czy punkt (1,1) w trojkacie?: ";
	if(t.czy_w_srodku(punkt(1,1))){
	    cout<<"tak" << endl;
    }else {
    cout<<"nie"<<endl;
    }
	trojkat t2 = trojkat(punkt(4,0), punkt(10,0), punkt(10,100));
	cout << "Czy t zawiera t1?: ";
	if(t.zawiera(t, t2)){
	    cout<<"tak" << endl;
    }else {
    cout<<"nie"<<endl;
    }

    return 0;
}
