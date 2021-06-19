#include <stdio.h>
#include <stdlib.h>

char board[50][50];
int odwiedzone[50][50];
int n;

int dfs(int en,int x,int y);

int main()
{
    int e,x,y;

    scanf("%d %d %d %d",&n,&e,&x,&y);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=getchar();
            odwiedzone[i][j]=0;
            if(board[i][j]=='\n'){j--;};
            if(board[i][j]=='#'){odwiedzone[i][j]=1;}
        }
    }
   int wyn=dfs(e,x,y);

   if(wyn==-1){printf("NIE");}
   else printf("%d", wyn);

    return 0;
}


int dfs(int en,int x,int y)
{
    int a=-1,b;
    odwiedzone[x][y]=1;

    switch(board[x][y]){
case '.':
    break;
case '*':en=en+5;
    break;
case '@':
    for(int i=-3;i<4;i++)
    {

            if(y+i<0||y+i>=n){}
            else if(odwiedzone[x][y+i]==1){}
            else{
            b=dfs(en,x,y+i);
            if(a<=b){a=b;}
            }

    }
    for(int i=-3;i<4;i++)
    {


            if(x+i<0||x+i>=n){}
            else if(odwiedzone[x+i][y]==1){}
            else{
            b=dfs(en,x+i,y);
            if(a<=b){a=b;}
            }
    }



    odwiedzone[x][y]=0;

    return a;

    break;

case 'W': odwiedzone[x][y]=0; return en;
    break;
    }

    if(en==0){return -1;};




    for(int i=-1;i<2;i++)
    {
            if(y+i<0||y+i>=n){}
            else if(odwiedzone[x][y+i]==1){}
            else{
            b=dfs(en-1,x,y+i);
            if(a<=b){a=b;}
            }

    }
     for(int i=-1;i<2;i++)
    {
            if(x+i<0||x+i>=n){}
            else if(odwiedzone[x+i][y]==1){}
            else{
            b=dfs(en-1,x+i,y);
            if(a<=b){a=b;}
            }
    }

    odwiedzone[x][y]=0;

    return a;
}
