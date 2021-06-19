#include "klasy.hpp"

using namespace std;

punkt::punkt()
{
    x = 0;
    y = 0;
}

punkt::punkt(const punkt &p)
{
    this->x = p.x;
    this->y = p.y;
}

punkt::punkt(double xx, double yy)
{
    this->x = xx;
    this->y = yy;
}


void punkt::print()
{
    cout << this->x << " " << this->y << endl;
}

double punkt::rzedna()
{
    return this->x;
}

double punkt::odcieta()
{
    return this->y;
}

void punkt::obroc(punkt a, double alfa)
{
    double a_x = a.rzedna();
    double a_y = a.odcieta();

    double t_x = this->x;
    double t_y = this->y;
    double kat = alfa * M_PI / 180;

    this->x = t_x * cos(kat) - t_y * sin(kat);
    this->y = t_x * sin(kat) + t_y * cos(kat);

    this->przesuniecie(a_x, a_y);
}

void punkt::przesuniecie(double x, double y)
{
    this->x += x;
    this->y += y;
}

//################################ ODCINEK


Odcinek::Odcinek()
{
    punkt a = punkt(0, 0), b = punkt(1, 1);
    this->p1 = a;
    this->p2 = b;
}

Odcinek::Odcinek(const Odcinek &o)
{
    this->p1 = o.p1;
    this->p2 = o.p2;
}

Odcinek::Odcinek(punkt a, punkt b)
{
    this->p1 = a;
    this->p2 = b;

    if (a.rzedna() == b.rzedna() and a.odcieta() == b.odcieta())
    {
        throw invalid_argument("nie można utworzyć odcinka o długości 0");
    }
}


void Odcinek::print()
{
    this->p1.print();
    this->p2.print();
}

double Odcinek::dlugosc()
{
    return odleglosc(this->p1, this->p2);
}

bool Odcinek::czy_na_odcinku(punkt p)
{
    double odleglosc1 = odleglosc(p, this->p1);
    double odleglosc2 = odleglosc(p, this->p2);

    if(odleglosc1 + odleglosc2 - this->dlugosc() == 0) return true;
    else return false;
}

punkt Odcinek::srodek_odcinka()
{
    punkt p1 = this->p1;
    punkt p2 = this->p2;

    double x = (p1.rzedna() + p2.rzedna()) / 2;
    double y = (p1.odcieta() + p2.odcieta()) / 2;
    punkt wynik = punkt(x, y);

    return wynik;
}

void Odcinek::przesuniecie(double x, double y)
{
    this->p1.przesuniecie(x, y);
    this->p2.przesuniecie(x, y);
}

void Odcinek::obrot(punkt p, double alfa)
{
    this->p1.obroc(p, alfa);
    this->p2.obroc(p, alfa);
}

bool Odcinek::rownolegle(Odcinek o, Odcinek m)
{
    punkt o_first = o.p1;
    punkt o_second = o.p2;

    punkt m_first = m.p1;
    punkt m_second = m.p2;

    double odc_1 = (o_first.odcieta() - o_second.odcieta()) / (o_first.rzedna() - o_second.rzedna());
    double odc_2 = (m_first.odcieta() - m_second.odcieta()) / (m_first.rzedna() - m_second.rzedna());

    return odc_1 == odc_2;
}

bool Odcinek::prostopadle(Odcinek o, Odcinek m)
{
    punkt o_first = o.p1;
    punkt o_second = o.p2;

    punkt m_first = m.p1;
    punkt m_second = m.p2;

    double odc_1 = (o_first.odcieta() - o_second.odcieta()) / (o_first.rzedna() - o_second.rzedna());
    double odc_2 = (m_first.odcieta() - m_second.odcieta()) / (m_first.rzedna() - m_second.rzedna());

    return (odc_1 == -odc_2) or (-odc_1 == odc_2);
}

punkt Odcinek::punkt_przeciecia(Odcinek o, Odcinek m)
{

    if (rownolegle(o, m))
        throw invalid_argument("Odcinki sa rownolegle!");

    punkt o_p = o.p1;
    punkt o_k = o.p2;

    punkt m_p = m.p1;
    punkt m_k = m.p2;

    double ax1 = (o_p.odcieta() - o_k.odcieta()) / (o_p.rzedna() - o_k.rzedna());
    double b1 = o_p.odcieta() - ax1 * o_p.rzedna();

    double ax2 = (m_p.odcieta() - m_k.odcieta()) / (m_p.rzedna() - m_k.rzedna());
    double b2 = m_p.odcieta() - ax1 * m_p.rzedna();

    double x = (ax1 - ax2) / (b2 - b1);
    double y = ax1 * x + b1;

    punkt p = punkt(x, y);

    if (o.czy_na_odcinku(p) and o.czy_na_odcinku(p))
    {
        return punkt(x, y);
    }
    else
    {
        throw invalid_argument("odcinki sa rozłączne");
    }
}

//############################# TROJKAT

trojkat::trojkat()
{
    punkt a = punkt(0, 0), b = punkt(1, 0), c = punkt(0, 1);
    p1 = a;
    p2 = b;
    p3 = c;
}

trojkat::trojkat(punkt a, punkt b, punkt c)
{

    double a_x = a.rzedna(), a_y = a.odcieta();
    double b_x = b.rzedna(), b_y = b.odcieta();
    double c_x = c.rzedna(), c_y = c.odcieta();

    if ((a_x == b_x && a_x == c_x && b_x == c_x) || (a_y == b_y && a_y == c_y && b_y == c_y))
        throw invalid_argument("wszystkie wierzcholki sa takie same!");

    if ((a_x == b_x && a_y == b_y) || (b_x == c_x && b_y == c_y) || (a_x == c_x && a_y == c_y))
        throw invalid_argument("Wierzcholki nachodza na siebie!");

    p1 = a;
    p2 = b;
    p3 = c;
}

void trojkat::print()
{
    this->p1.print();
    this->p2.print();
    this->p3.print();
}

double trojkat::pole(trojkat t)
{
    punkt a = t.p1, b = t.p2, c = p3;
    double a_x = a.rzedna(), a_y = a.odcieta();
    double b_x = b.rzedna(), b_y = b.odcieta();
    double c_x = c.rzedna(), c_y = c.odcieta();

    double pole_t = 0.5 * (a_x * b_y + b_x * c_y + c_x * a_y - c_x * b_y - a_x * c_y - b_x * a_y);
    return pole_t;
}

double trojkat::obwod(trojkat t)
{
    punkt a = t.p1, b = t.p2, c = p3;
    double odleglosc1 = odleglosc(a, b);
    double odleglosc2 = odleglosc(b, c);
    double odleglosc3 = odleglosc(b, c);

    return odleglosc1 + odleglosc2 + odleglosc3;
}

punkt trojkat::srodek(trojkat t)
{
    punkt a = t.p1, b = t.p2, c = p3;
    double a_x = a.rzedna(), a_y = a.odcieta();
    double b_x = b.rzedna(), b_y = b.odcieta();
    double c_x = c.rzedna(), c_y = c.odcieta();

    double x = (a_x + b_x + c_x) / 3;
    double y = (a_y + b_y + c_y) / 3;

    punkt p = punkt(x, y);
    return p;
}

double trojkat::znak(punkt p1, punkt p2, punkt p3)
{
    return (p1.rzedna() - p3.rzedna()) * (p2.odcieta() - p3.odcieta()) - (p2.rzedna() - p3.rzedna()) * (p1.odcieta() - p3.odcieta());
}

bool trojkat::czy_w_srodku(punkt p)
{
    double d1, d2, d3;
    bool minus, plus;

    d1 = znak(p, this->p1, this->p2);
    d2 = znak(p, this->p2, this->p3);
    d3 = znak(p, this->p3, this->p1);

    minus = (d1 < 0) or (d2 < 0) or (d3 < 0);
    plus = (d1 > 0) or (d2 > 0) or (d3 > 0);

    return !(minus and plus);
}

bool trojkat::zawiera(trojkat t1, trojkat t2)
{
    punkt a1 = t1.p1;
    punkt b1 = t1.p2;
    punkt c1 = t1.p3;

    punkt a2 = t2.p1;
    punkt b2 = t2.p2;
    punkt c2 = t2.p3;

    return (!t1.czy_w_srodku(a1) and !t1.czy_w_srodku(b1) and !t1.czy_w_srodku(c1) and !t2.czy_w_srodku(a2) and !t2.czy_w_srodku(b2) and !t2.czy_w_srodku(c2));
}

void trojkat::przesuniecie(double x, double y)
{
    this->p1.przesuniecie(x, y);
    this->p2.przesuniecie(x, y);
    this->p3.przesuniecie(x, y);
}

void trojkat::obrot(punkt p, double alfa)
{
    this->p1.obroc(p, alfa);
    this->p2.obroc(p, alfa);
    this->p3.obroc(p, alfa);
}





