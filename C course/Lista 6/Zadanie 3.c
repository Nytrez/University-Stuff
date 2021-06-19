#include <stdio.h>
#include <stdlib.h>

int main()
{
    int plansza[400][400]={0};
    int y=200,x=200;
    plansza[x][y]=1;
    int kier=1;
    int ymax=200,xmax=200,xmin=200,ymin=200;
    char c;
    while((c=getchar())!='\n')
          {
              switch(c)
                 {
                 case 'F':
                     if(kier==0){
                       y++;
                       ymax++;
                       if(y>ymax){ymax=y;}
                       plansza[x][y]=1;
                          }

                     else if(kier==1){
                       x++;
                       if(xmax<x){xmax=x;}
                       plansza[x][y]=1;
                          }

                     else if(kier==2){
                       y--;
                       if(y<ymin){ymin=y;}
                       plansza[x][y]=1;
                          }

                     else if(kier==3){
                       x--;
                       if(xmin>x){xmin=x;}
                       plansza[x][y]=1;
                          }
                    break;
                 case 'L':
                     kier--;
                    break;
                 case 'R':
                     kier++;

                    break;
                 }
                kier%=4;
                if(kier==-1)
                {
                    kier=3;
                }

          }

          for(int i=ymax;i>ymin-1;i--)
          {
              for(int j=xmin;j<xmax+1;j++)
              {
                  if(plansza[j][i]==1){printf("*");}
                  else if(plansza[j][i]==0){printf(" ");}
              }
              if(i==ymin){}
              else{printf("\n");};


          }


}
