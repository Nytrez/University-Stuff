#include <stdio.h>
#include "zad1.c"

int main()
{

    figure *f;
    f = new_square(1.0, -1.0, -1.0);

    printf("\npole kwadratu: %f\n", areaofobject(f));

    printf("\npoczatkowy x: %f\npoczatkowy y: %f \n", f->x, f->y);
    printf("\nprzesuniecie o wektor <4,2>\n");
    move(f, 4, 2);
    printf("\nnowy x: %f\nnowy y: %f \n", f->x, f->y);

    figure *g[3];
    g[0] = new_square(0.0, 1.0, 2.0);   //pole 4
    g[1] = new_circle(2.0, 3.0, 1.0);   // pole pi
    g[2] = new_triangle(4.0, 5.0, 2.0); //pole sqrt3 
    //wiec suma około 8

    printf("\nsuma pol: %f\n\n", sumofareas(g, 3));

    return 0;
}