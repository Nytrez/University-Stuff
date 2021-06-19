#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_SIZE 1024
int RAM[RAM_SIZE];
bool if_free[RAM_SIZE];
char variables2[RAM_SIZE];

int find_empty();
void fill_up(int a, int b);
int find_value(char a);
void exit(int status);
void end_now();
void scan_statement(char* statement);
int eval(const char* begin, const char* end, bool lvalue);


int main()
{
    for(int i=0;i<RAM_SIZE;i++)
        if_free[i]=0;

    char* statement = malloc(79*sizeof(char));
    int dl=0;
    scan_statement(statement);
    do
    {

    if (strcmp(statement, "exit(0);") == 0)break;
    dl = strlen(statement);
    if (statement[0] == 'p' && dl>15) 
    {

        printf("%d", eval(&statement[15], &statement[dl-2], 1));
        scan_statement(statement);
        if (strcmp(statement, "exit(0);") == 0)break;
        putchar('\n');

    }
    else
    {
        int i=1;
        while(statement[i]!='=' && i<250)
            i++;
        i--;

                if(statement[0]=='i' && statement[1]=='n' && statement[2]=='t')
                {
                    eval(&statement[0], &statement[dl-1], 0);
                }else
                    RAM[eval(&statement[0], &statement[i], 0)] = eval(&statement[i+3], &statement[dl-1], 1);

                scan_statement(statement);
    }

            for(int i=1;i<RAM_SIZE;i++)
            if(if_free[i]==0 && RAM[i]!=0)
            {
            end_now();
            }
            if(RAM[0]!=0)end_now();

    }while(1);

    return 0;
}

int eval(const char* begin, const char* end, bool lvalue) {

    if('0' <= *begin && *begin <= '9' && '0' <= end[-1] && end[-1] <= '9' && lvalue==1)
    {
        int l=atoi(begin);
        return l;
    }
    if(*begin=='-')
    {
        int l=atoi(begin);
        return l;
    }
    if(*begin == '*') {
        if(lvalue==0)
        {
            int wrt=eval(&begin[1], &end[0], 1);
            if(if_free[wrt]==0)end_now();
            return wrt;
        }
        else
        {
            int wrt=eval(&begin[1], &end[-1], 1);
            if(if_free[wrt]==0)end_now();
            return RAM[wrt];
        }
    }

    if(end[-1] == ']') {
        if(lvalue==0)
        {
            if(begin[0]=='i' && begin[1]=='n' && begin[2]=='t')
            {
                int wolne = find_empty();
                variables2[wolne] = begin[4];
                int i=1;
                while(begin[i]!='[')
                    i++;
                int wrt=eval(&begin[i+1], &end[-1], 1);
                fill_up(wolne, wolne+wrt-1);
                return 0;
            }
            else
            {
                int bilans=1;
                int i=2;
                int z=0;
                int zwroc=0;
                int tmp=0;
                int wrt;
                while(begin[i]!=end[0])
                {
                if(begin[i]=='[')
                    bilans++;
                if(begin[i]==']')
                {
                    bilans--;
                }

                if(bilans==0 && tmp==1)
                {
                    if(if_free[RAM[zwroc]]==0)end_now();
                    zwroc=RAM[zwroc]+eval(&begin[z], &begin[i], 1);
                    z=i+2;
                }
                if(bilans==0 && tmp==0)
                {

                wrt=eval(&begin[2], &begin[i], 1);
                int place_found = find_value(begin[0]);
                zwroc=place_found+wrt;
                z=i+2;
                tmp=1;
                }
                i++;
                }
                if(if_free[zwroc]==0)end_now();
                return zwroc;
            }
        }
        else
        {

                int bilans=0;
                int i=0;
                int z=0;
                int zwroc=0;
                int tmp=0;
                int wrt;
                while(1)
                {

                if(begin[i]=='[')
                    bilans++;
                if(begin[i]==']')
                {
                    bilans--;

                    if(bilans==0 && tmp==1)
                {
                    if(if_free[RAM[zwroc]]==0)end_now();
                    zwroc=RAM[zwroc]+eval(&begin[z], &begin[i], 1);
                    z=i+2;
                }
                if(bilans==0 && tmp==0)
                {
                wrt=eval(&begin[2], &begin[i], 1);
                int place_found = find_value(begin[0]);
                zwroc=place_found+wrt;

                z=i+2;
                tmp=1;
                }

                }

                if(begin[i]==end[0])break;
                i++;
                }
                if(if_free[zwroc]==0)end_now();
                return RAM[zwroc];

        }

    }

    if(begin[0] == '(') {
        if(lvalue==1)
            {
                int bilans=1;
                char znak;
                int k;
                int i=1;
                while(bilans!=0)
                {
                    if((begin[i]=='+' || begin[i]=='-') && bilans==1)
                    {
                        znak=begin[i];
                        k=i;
                    }
                    if(begin[i]=='(')
                        bilans++;
                    if(begin[i]==')')
                        bilans--;
                    i++;
                }
                int wart1 = eval(&begin[1], &begin[k], 1);
                int wart2 = eval(&begin[k+1], &begin[i-1], 1);

                if(znak=='+')
                    return wart1+wart2;
                else
                    return wart1-wart2;

            }
    }

    if('a' <= *begin && *begin <= 'z') {
                return find_value(*begin);
    }
    return 0;
}


void scan_statement(char* statement) {
    char c = getchar();
    while(isspace(c))
        c = getchar();
    while(true) {
        *statement++ = c;
        if(c == ';')
            break;
        c = getchar();
    }
    *statement = '\0';
}

int find_value(char a)
{
    for(int i=1;i<RAM_SIZE;i++)
        if(variables2[i]==a) return i;
    end_now();
    return 1;
}


int find_empty()
{
    for(int i=1;i<RAM_SIZE;i++)
    {
        if(if_free[i]==0)return i;
    }
    end_now();
    return 1;
}

void fill_up(int a, int b)
{
    for(int i=a;i<=b;i++)
    {
        if_free[i]=1;
    }
}

void end_now(){
printf("Segmentation fault");
exit(0);
}
