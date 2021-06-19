#include<stdio.h>
#include<math.h>


int num[10]={};
int dl=0;



int check(int a,int b)
{
 int x,y,i,ct1=0,ct2=0;
 int num1[10]={0};

    while(a!=0)
      {
      x=a%10;
      ct1++;
      num1[x]++;
      a/=10;
      }

    if(ct1!=dl/2)return 0;
      while(b!=0)
       {
        y=b%10;
        ct2++;
        num1[y]++;
        b/=10;
       }

    if(ct2!=dl/2)return 0;
       for(i=0;i<10;i++)
       {
       if(num[i]!=num1[i])return 0;
       }

return 1;
}

int leng(int a)
{
    int wam =0;
    while (a>0)
    {
        wam+=1;
        a/=10;
    }
    return wam;
}


int main()
{
int flag=0,a,x,n,t,ite=1;
scanf("%d",&t);

dl=leng(t);

for(int f=0;f<dl;f++)
{
    ite=ite*10;
}


for(t=t+1;t<ite;t++)
{
for(int h=0;h<10;h++)
{
  num[h]=0;
}
    x=t;
     while(x!=0)
       {
       a=x%10;
       num[a]++;
       x/=10;
       }

  n=sqrt(t);

    for(int i=1;i<=n;i++)
    {
       if(t%i==0)
        {
          if(check(i,t/i)){printf("%d %d %d \n",t,i,t/i); return 0;}
        }
    }
}
printf("BRAK WAMPIRYCZNEJ");
return 0;
}
