#include <stdio.h>

char pierwsza(int a)
{
     if(a%2==0) 
     return 0;

    for (int b=3;b*b<=a;b=b+2)
    {
        if(a%b==0)
        return 0;
    }
    return 1;

}

int main()
{
    int n;
    scanf("%d",&n);

    if(n<7||n%2==0)
    {
      printf("NIEPOPRAWNA LICZBA");
      return 0;
    }

    for(int b=3; b<n-4; b=b+2)
    {
        if(pierwsza(b))
        {
            for(int a=b;a<n;a=a+2)
            {
                if(pierwsza(a)&&pierwsza(n-(b+a)))
                {
                    printf("%d %d %d",b,a,n-(b+a));
                    return 0;
                }
            }
        
        }
    }
    return 0;
}