#include <stdio.h>
#include <stdlib.h>

int nawias(char token, int* pozycja,int* wiersz)
{
    int lokalpos,lokalwier;
    char c;
    while((c=getchar())!=EOF){

        *pozycja+=1;
        if(c=='('||c=='{'||c=='['){
            lokalpos=*pozycja;
            lokalwier=*wiersz;
            if(nawias(c,pozycja,wiersz)==1){
                printf("%d ",lokalpos,lokalwier);
                return 1;
            }
           }
           else if(c=='\n'){
          *wiersz+=1;
          *pozycja=0;

           }
           else switch(c){
        case ')':
            if(token=='('){return 0;}
            printf("pozycja:%d wers: %d \n",*pozycja,*wiersz);
            break;
        case '}':
            if(token=='{'){return 0;}
            printf("pozycja:%d wers: %d \n",*pozycja,*wiersz);
            break;
        case ']':
            if(token=='['){return 0;}
            printf("pozycja:%d wers: %d \n",*pozycja,*wiersz);
            break;

           }
    }

return 1;

}


int main()
{
    int pozycjs=0,wiers=1;
    return nawias('\0',&pozycjs,&wiers);
}
