#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void axtw(int rozm,int lg2res,int a, int b, int n, char pole[256][257])
{
    int res=pow(2,lg2res);
    int piksel=rozm/res;

    char poleZmien[256][257]={0};
    if(n<0){
        n*=-1;

        for(int i=0;i<rozm;i++)
        {
            for(int j=a*piksel;j<b*piksel+piksel;j++)
            {
                poleZmien[i][j]=pole[i][j];
            }
        }
        for(int i=0;i<rozm;i++)
        {
            int shift = n*piksel+i;
            if(shift>=rozm)
            {
                shift=shift-rozm;
            }

            for(int j=a*piksel;j<b*piksel+piksel;j++)
            {
                pole[i][j]=poleZmien[shift][j];
            }
        }
    }else if(n>0){
      for(int i=a*piksel;i<b*piksel+piksel;i++)
      {
        for(int j=0;j<rozm;j++){
          poleZmien[i][j]=pole[i][j];
        }
    }

    for(int i=a*piksel;i<b*piksel+piksel;i++)
    {
        for(int j=0;j<rozm;j++){

            int shift=n*piksel+j;
        if(shift>=rozm){
            shift=shift-rozm;
        }
        pole[i][j]=poleZmien[i][shift];

       }
     }
  }
}

void dgtw(int rozm,int lg2res,int a, int b, int n, char pole[256][257])
{
    int res=pow(2,lg2res);
    int piksel=rozm/res;

    char poleZmien[256][257]={0};

    int pKol,kWier;

    while(a<=b){
        int x=a;

        if(a<=0){
            x*=-1;
            x*=piksel;
            kWier=rozm;

            pKol=-1*piksel;
        }else{
        kWier=rozm-a*piksel;
        pKol=a*piksel-piksel;
        x=0;
        }


        for(int i=x;i<kWier;i++)
        {
            if(i%piksel==0){
                pKol+=piksel;
            }
            for(int j=pKol;j<pKol+piksel;j++)
            {
                poleZmien[i][j]=pole[i][j];
            }
        }

        x=a;
        if(a<=0)
        {
            x*=-1;
            x*=piksel;
            kWier=rozm;
            pKol=-1*piksel;
        }else
        {
        kWier=rozm-a*piksel;
        pKol=a*piksel-piksel;
        x=0;
        }

        int zamWier=0,zamKol=0,initW=x,initK=pKol+piksel,ostKol=rozm-x;
        for(int i=x;i<kWier;i++)
        {
            if(i%piksel==0)
            {
                pKol+=piksel;
            }
            zamWier=i+n*piksel;
            if(zamWier>=kWier)
            {
                        zamWier=initW+(zamWier-kWier);
                        }
                    for(int j=pKol;j<pKol+piksel;j++){
                        zamKol=j+n*piksel;
                        if(zamKol>=ostKol)
                        {
                            zamKol=initK+(zamKol-ostKol);
                        }
                        pole[i][j]=poleZmien[zamWier][zamKol];
                    }
        }
        a++;
    }
}


int main()
{
    char pole[256][257]={0};
    int c=0,lg2img=0,numTss=0;
    scanf("[lg2img: %d][numTss: %d]\n",&lg2img,&numTss);

    int i=0, j=0;

    int rozm = pow(2,lg2img);
    while(i<rozm)
    {
        c=getchar();

        if(j==rozm)
        {
            pole[i][j]='\0';
            i++;
            j=0;
        }else{
        pole[i][j]=c;
        j++;
        }
    }

    char slw[5]={0};
    int lg2res,n,a,b;

    while(numTss>0)
    {
        scanf("%s %d [%d %d] %d",slw,&lg2res,&a,&b,&n);

        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        if(rozm>1)
        {
            if(!strcmp(slw,"AxTw"))
            {
                axtw(rozm,lg2res,a,b,n,pole);
            }else
            {
                dgtw(rozm,lg2res,a,b,n,pole);
            }
        }
        numTss--;
    }
    int p=0;
    for(int h=0;h<100;h++)
    {
      p=p+100;
    }

    for(int i=0;i<rozm;i++)
    {
        for(int j=0;j<rozm;j++)
        {
            printf("%c",pole[i][j]);
        }
        printf("\n");
    }

    return 0;
}
