#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc <= 1) { printf("Brak argumentow \n"); return 1; }
  int dla=strlen(argv[1]);

   char c;
   int x,y;

   while((c=getchar())!=EOF)
    {
     if(x==1&&c!=' '&&y==0)
     {
        for(int i=0;i<dla;i++)
            {
                if (argv[1][i]==c)
                c=argv[2][i];
        }
        putchar(' ');
        putchar(c);
        x=0;
        y=0;
        }

     else if (c==' ')
     {
         x=1;
     }
     else if(c=='.'&&x==0)
     {
         y=1;
         putchar('.');
     }
     else if(c=='.'&&x==1)
     {
         y=1;
         x=0;
         putchar(' ');
         putchar('.');
     }
     else if(y==1&&c>='A'&&c<='Z')
     {
         for(int i=0;i<dla;i++)
            {
                if (argv[1][i]==c)
                c=argv[2][i];
        }

        putchar(' ');
        putchar(' ');
        putchar(c);
        y=0;
        x=0;
     }
     else if(x==1&&c!=' '&&y==1)
     {
        for(int i=0;i<dla;i++)
            {
                if (argv[1][i]==c)
                c=argv[2][i];
        }
        putchar(' ');
        putchar(c);
        x=0;
        y=0;
        }
        else

       {
        for(int i=0;i<dla;i++)
            {
                if (argv[1][i]==c)
                c=argv[2][i];
        }
        putchar(c);
        x=0;
       }

      }

    return 0;
}
