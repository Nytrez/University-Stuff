#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

    if(argc<4){printf("too few  arguments\n"); return 0;}
    FILE *rfile,*wfile;
    int n=atoi(argv[2]);
    char *writefile;
    writefile=argv[1];

    if((wfile=fopen(writefile,"w"))==NULL){
        printf("couldn't open file to write\n");
        exit(1);
    }

    int i=3;
    char *readfile=NULL;

    while(i<argc){

        readfile=argv[i];
        if((rfile=fopen(readfile,"r"))==NULL){
            fprintf(wfile,"couldnt't open file to read %s\n", readfile);
            exit(1);
        }
        int lines=0;
        int totallines=1;
        int c=getc(rfile);
        int a,d;

        while(c!=EOF)
        {

            if(c=='\n'){
            totallines++;}
            a=c;
            c=getc(rfile);

        }
         if(a=='\n'){totallines--;} //jezeli plik na koncu plliku daje \n po nim EOF to zmniejszam ilosc wierszy

        rewind(rfile);
        c=getc(rfile);
        fprintf(wfile,"===%s===(%d lines)\n\n",readfile,totallines);
        while(lines!=totallines&&lines!=n&&c!=EOF){ //lines!=totallines zeby nie wypisac zbednego wiersza w przypadku \n EOF
            if(c=='\n'){
                lines++;

            }
            if(lines==n){}
            else{
            putc(c,wfile);
            }
            c=getc(rfile);
        }
        fprintf(wfile,"\n\n");
        fclose(rfile);
        i++;
    }

    fclose(wfile);
    return 0;
}
