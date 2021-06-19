#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//definicja struktury
//nie trzeba pamietac koordynatow poniewaz boki sa rownolegle do osi ukladu wspolrzednych, wiec majac srodek oraz dlugosc boku, mamy jednoznacznie wyglad figury

typedef struct figure
{

  char typfig;  //typ figury (koło, trójkąt rownoboczny, kwadrat)
  float x;      // wspolrzedna x srodka figury
  float y;      // wspolrzedna y srodka figury
  float radius; // promień/długość boku

} figure;



//inicjowanie figur

figure *new_square(float x, float y, float radius)
{ //stworz nowy kwadrat

  figure *square = calloc(1, sizeof(struct figure));

  if (radius < 0)
  {
    printf("\nblad, dlugosc boku mniejsza niz 0\ndlugosc zmieniona na 0");
    radius = 0;
  }

  square->typfig = 's';
  square->x = x;
  square->y = y;
  square->radius = radius;

  return square;
}

figure *new_circle(float x, float y, float radius)
{ //stworz nowe koło

  if (radius < 0)
  {
    printf("\nblad, promien mniejszy niz 0\npromien zmieniony na 0");
    radius = 0;
  }

  figure *circle = calloc(1, sizeof(struct figure));

  circle->typfig = 'c';
  circle->x = x;
  circle->y = y;
  circle->radius = radius;

  return circle;
}

figure *new_triangle(float x, float y, float radius)
{ //stwórz nowy trójkąt

  if (radius <= 0)
  {
    printf("\nblad, dlugosc boku mniejsza od 0\ndlugosc zmieniona na 0");
    radius = 0;
  }

  figure *triangle = calloc(1, sizeof(struct figure));

  triangle->typfig = 't';
  triangle->x = x;
  triangle->y = y;
  triangle->radius = radius;

  return triangle;
}


//definicja 3 funkcji z zadania


float areaofobject(figure *object)
{ //oblicz pole figur

  float area;
  switch (object->typfig)
  {

  case 's':
    area = object->radius * object->radius; // a * a
    return area;
    break;

  case 'c':
    area = M_PI * object->radius * object->radius; // pi * a * a
    return area;
    break;

  case 't':
    area = (sqrt(3) * object->radius * object->radius) / 4; //(a*a*sqrt3)/4, z wzoru na trojkat rownoboczny
    return area;
    break;
  }
}

void move(figure *object, float x, float y)
{ //przesun środek figury o x i y

  object->x += x;
  object->y += y;
}

float sumofareas(figure *object[], int size) //sumowanie pol pokolei odwolujac sie do funkcji liczacej pola
{
  float sum = 0;

  for (int i = 0; i < size; i++)
  {
    sum += areaofobject(object[i]);
  }

  return sum;
}
