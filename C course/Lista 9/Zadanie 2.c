#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int wart;
    struct n *lewe;
    struct n *prawe;
} galaz;
typedef galaz *act;

void obrocprawo(act *active);
void obroclewo(act *active);
void korzenprawo(act *active);
void korzenlewo(act *active);
void wypiszdrzewo(galaz *drzewo);
void stworzdrzewo(int n, int i, galaz *drzewo);

int main()
{

    int n = 0;
    scanf("%d", &n);
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        printf("(1)");
        return 0;
    }

    galaz *drzewo = malloc(sizeof(galaz));
    drzewo->wart = 1;
    drzewo->lewe = NULL;
    stworzdrzewo(n, 2, drzewo);
    act active = drzewo;
    scanf("%d", &n);

    while (n != 0)
    {

        if (n == 1)
        {
            korzenlewo(&active);
        }
        if (n == 2)
        {
            active = drzewo;
        }
        if (n == 3)
        {
            korzenprawo(&active);
        }
        if (n == 4)
        {
            if (drzewo == active)
            {
                obroclewo(&active);
                drzewo = active;
            }
            else
            {
                obroclewo(&active);
            }
        }
        if (n == 6)
        {
            if (drzewo == active)
            {
                obrocprawo(&active);
                drzewo = active;
            }
            else
            {
                obrocprawo(&active);
            }
        }
        scanf("%d", &n);
    }
    int m=2;
    for(int i=0;i<20;i++){m=m*2;}
    wypiszdrzewo(drzewo);
    return 0;
}

void stworzdrzewo(int n, int i, galaz *drzewo)
{
    if (i > n)
    {
        return;
    }
    galaz *nowagalaz = malloc(sizeof(galaz));
    nowagalaz->wart = i;
    nowagalaz->lewe = NULL;
    nowagalaz->prawe = NULL;
    drzewo->prawe = nowagalaz;
    stworzdrzewo(n, i + 1, nowagalaz);
}

void obroclewo(act *active)
{

    galaz *transprawe = (*active)->prawe->lewe;
    galaz *poprzkorzen = malloc(sizeof(galaz));
    poprzkorzen->wart = (*active)->wart;
    poprzkorzen->lewe = (*active)->lewe;
    poprzkorzen->prawe = transprawe;

    (*active)->wart = (*active)->prawe->wart;
    (*active)->prawe = (*active)->prawe->prawe;
    (*active)->lewe = poprzkorzen;
}

void obrocprawo(act *active)
{
    galaz *translewe = (*active)->lewe->prawe;
    galaz *poprzkorzen = malloc(sizeof(galaz));
    poprzkorzen->wart = (*active)->wart;
    poprzkorzen->prawe = (*active)->prawe;
    poprzkorzen->lewe = translewe;

    (*active)->wart = (*active)->lewe->wart;
    (*active)->lewe = (*active)->lewe->lewe;
    (*active)->prawe = poprzkorzen;
}

void korzenlewo(act *active)
{
    *active = (*active)->lewe;
}

void korzenprawo(act *active)
{
    *active = (*active)->prawe;
}

void wypiszdrzewo(galaz *drzewo)
{
    printf("(");
    if (drzewo->lewe != NULL)
    {
        wypiszdrzewo(drzewo->lewe);
    }

    printf("%d", drzewo->wart);

    if (drzewo->prawe != NULL)
    {
        wypiszdrzewo(drzewo->prawe);
    }
    printf(")");
}
