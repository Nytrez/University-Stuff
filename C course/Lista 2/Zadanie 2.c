#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int argumenty (char c[],int u, int *z)
{
    int ile,min,max;

    ile=sscanf(c, "%d-%d", &min, &max);
    if(ile==2)
    {

    *z=1;
    if(u==max)
    {
        *z=0;
    }
       if(min<=u&&u<=max)
            return u;
    }else {
        *z=0;
    return min;
    }

    return -1;

}


int main(int argc, char *argv[])
{
  if (argc <= 1) { printf("Brak argumentow \n"); return 1; }
  int dla=strlen(argv[1]);

   char c;
   int word=1,i=1,x=0;
   int z=0;
   char g='`';


   if((c=getchar())==' ')g=c;
   else{ if(i<argc&&word==argumenty(argv[i],word,&z)) putchar(c);
                }

   while((c=getchar())!=EOF)
    {

        if (c=='\n')
        {

            printf("\n");
            word=1;
            i=1;
            z=0;
            x=0;
            if((c=getchar())==' '){g=c;}else{g='`'; if(i<argc&&word==argumenty(argv[i],word,&z)) putchar(c);}


        }else
        {
               if(i<argc&&word==argumenty(argv[i],word,&z)&&c==' '&&x==0&&g!=' ')
                {
                    if(z==0) {i=i+1;}

                   if(i==argc){}
                   else{
                        word=word+1;
                        x=1;
                    }

                }

                else if(i<argc&&c==' '&&g!=' ')
                {
                    word=word+1;
                    x=1;
                }
                else if(i<argc&&word==argumenty(argv[i],word,&z)&&x==1&&c!=' ')
                  {

                      putchar(' ');
                      putchar(c);
                      x=0;
                }

                else if(i<argc&&word==argumenty(argv[i],word,&z)&&x==0&&c!=' ')
                  {
                   putchar(c);
                }

                 g=c;
        }
     }


    return 0;
}
