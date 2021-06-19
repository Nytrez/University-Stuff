#include<stdio.h>
#include<stdlib.h>


int main()
{
    int wyn=0,n;

    scanf("%d", &n);
    if(n<138) {printf("0"); return 0;}

    for(int i=n-10;i>=0;i--)
    {
        int spierw=i,a=i,k1=2,liczs=0;

        while(spierw>1)
        {
            while((spierw%k1)==0)
            {
                spierw/=k1;
                liczs++;
            }
            k1++;
        }
        if(liczs==7)
        {
            for(int j = n-2-a;j>=8;j--)
            {
                int pierwt=j,b=j,k2=2,liczt=0;
                while(pierwt>1)
                {
                    while((pierwt%k2)==0)
                    {
                        pierwt/=k2;
                        liczt++;
                    }
                    k2++;
                }
                if(liczt==3)
                {
                    int c=n-a-b;
                    if(c<2){}
                    else{
                        int ok=0;
                        for(int k=2;k*k<=c;k++)
                        {
                            if((c%k)==0)
                            {
                                ok=1;
                            }
                        }
                        if(ok==0)
                        {
                            wyn++;
                        }
                    }
                }
            }
        }
    }

    printf ("%d",wyn);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int wyn=0,n;

    scanf("%d", &n);
    if(n<138) {printf("0"); return 0;}

    for(int i=n-10;i>=0;i--)
    {
        int spierw=i,a=i,k1=2,liczs=0;

        while(spierw>1)
        {
            while((spierw%k1)==0)
            {
                spierw/=k1;
                liczs++;
            }
            k1++;
        }
        if(liczs==7)
        {
            for(int j = n-2-a;j>=8;j--)
            {
                int pierwt=j,b=j,k2=2,liczt=0;
                while(pierwt>1)
                {
                    while((pierwt%k2)==0)
                    {
                        pierwt/=k2;
                        liczt++;
                    }
                    k2++;
                }
                if(liczt==3)
                {
                    int c=n-a-b;
                    if(c<2){}
                    else{
                        int ok=0;
                        for(int k=2;k*k<=c;k++)
                        {
                            if((c%k)==0)
                            {
                                ok=1;
                            }
                        }
                        if(ok==0)
                        {
                            wyn++;
                        }
                    }
                }
            }
        }
    }

    printf ("%d",wyn);
    return 0;

}
