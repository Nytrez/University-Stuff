
typedef struct Wezel
{
    double info;
    struct Wezel *nast, *poprz;
} Wezel;
typedef Wezel *Lista;

void czy_pusta(Lista lst);
int dlugosc_listy(Lista lst);
void wypisz(Lista l);
Lista stworz();
Lista dodaj_na_tyl(Lista lst, double info);
Lista dodaj_na_pocz(Lista lst, double info);
Lista odjemij_z_pocz(Lista lst);
Lista odjemij_z_kon(Lista lst);

