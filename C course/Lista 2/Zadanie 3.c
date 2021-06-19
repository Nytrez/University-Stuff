#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int odwrot(char *s) {
   int length, c;
   char *begin, *end, temp;

   length = strlen(s);
   begin  = s;
   end    = s;

   for (c = 0; c < length - 1; c++)
      end++;

   for (c = 0; c < length/2; c++)
   {
      temp   = *end;
      *end   = *begin;
      *begin = temp;

      begin++;
      end--;
   }
   return 0;
}

int pote(int x, int y) {
	if(y == 0) {
		return 1;
	}

	for(int i=0; i<y-1; i++) {
		x *= 2;
	}

	return (int)x;
}


int main() {
	char code[7] = {0};
	char tekst[127] = { 0 };

	scanf("%s", code);
	scanf("%s",tekst);

	int textlen = strlen(tekst);
	if(strcmp(code, "encode") == 0){
        char bin[64][8] = { 0 };

        for(int i=0; i < textlen; i++) {
            int x = tekst[i];

            for(int k=0; k < 7; k++) {
                int p = pote(2, 6-k);
                int num = (x/p) % 2;

                bin[i][k] = num + '0';
            }
            bin[i][7] = '\0';
        }


        int dopel = 0;
        for(int k=0; k<7; k++){
            int mod8 = strlen(tekst) % 8;

            if(mod8 > 0) {
                int wel8 = 8;
                while(strlen(tekst)/wel8 >= 1) {
                    wel8 += 8;
                }
                dopel = wel8 - (strlen(tekst) % wel8);
            }

            char seq[65] = {0};

            for(int i=0; i<textlen; i++) {
                seq[i] = bin[i][6-k];
            }

            for(int i=strlen(tekst); i<textlen + dopel ; i++) {
                seq[i] = '0';
            }


            
            for(int i=0; i<textlen; i+= 4) {
                char bite[5] = {0};
                memcpy(bite, &seq[i], 4);


                int num = strtol(bite, NULL, 2);



                if(num < 10) {
                    printf("%d", num);
                }else {
                    if(num == 10) {
                        printf("%s", "A");
                    }else if(num == 11) {
                        printf("%s", "B");
                    }else if(num == 12) {
                            printf("%s", "C");
                    }else if(num == 13) {
                            printf("%s", "D");
                    }else if(num == 14) {
                            printf("%s", "E");
                    }else if(num == 15) {
                            printf("%s", "F");
                    }
                }
               
            }

        }
	}else if(strcmp(code, "decode") == 0){
		char seq[508] = {0};
		int DIV = strlen(tekst)/7;
		for(int i=0; i<textlen; i+=DIV) {
			char single[DIV+1];
			memcpy(single, &tekst[i], DIV);
			single[DIV] = '\0';


			for(int j=0; j<DIV; j++) {
				char one[2] = { 0 };
				sprintf(one, "%c", single[j]);

				int num = strtol(one, NULL, 16);
				char binary[2] = {0};
				char subseq[5] = {0};

				if(num == 0){
					strcat(subseq, "0000");
				}

				while(num > 0){
					sprintf(binary, "%d", num%2);
					strcat(subseq, binary);

					num = num/2;
				}

				while(strlen(subseq) < 4) {

					strcat(subseq, "0");
				}

				odwrot(subseq);

				strcat(seq, subseq);
			}
		}

        
		DIV = strlen(seq)/7;
		
		int COUNT = DIV-1;
		char kolu[7][449] = {0};

		int index = 0;
		int seqlen = strlen(seq);
		for(int i=0; i<seqlen; i+=DIV){
			char col[9] = {0};
			memcpy(col, &seq[i], DIV);
			col[8] = '\0';
			memcpy(kolu[index], &seq[i], DIV);
			kolu[index][sizeof(kolu[index]) -1] = '\0';

			int c = 0;
			for(int k=7; k>=0; k--) {
				char num[2] = {0};
				sprintf(num, "%c", col[k]);
				num[1] = '\0';

				if(strcmp(num, "0") == 0){
					c += 1;
				}else {
					if(c< COUNT) {
						COUNT = c;

					}
					break;
				}
			}
			index += 1;
		}
		
		char letter[8] = {0};
		for(int i=0; i<DIV-COUNT; i++){

			for(int k=0; k<7; k++) {
				letter[6-k] = kolu[k][i];
			}

			char word = strtol(letter, NULL, 2);
			
			putchar(word);
		}

	}


	return 0;
}
