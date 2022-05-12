// SO IS1 223A LAB10
// Wojciech Lidwin
// lw46577@zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
double wartosc=1;
pthread_mutex_t mymutex;
void *thread(void *data) {

char *msg = (char *) data;
char *end;
char *importowane=strtok(msg,",");
long long int zakres=0;
long long int pierwszy=0;

if(importowane){
    zakres=strtoll(importowane,&end,10);
                                    }
importowane=strtok(NULL,",");

if(importowane){
    pierwszy=strtoll(importowane,&end,10);
                                    }
pthread_t self = pthread_self();
srand(self);
printf("Thread %ld size=%lld pierwszy=%lld\n", self,zakres, pierwszy);

double suma=1.0;
double zmienna=1.0;

for(long long int i=pierwszy;i<zakres+pierwszy;i++){
    zmienna=4.0*(double)i*(double)i;
    suma*=zmienna/(zmienna-1.0);
                                                        }

pthread_mutex_lock(&mymutex);
wartosc*=suma;
pthread_mutex_unlock(&mymutex);


long delay = suma;
printf("Thread %ld prod=%.20lf\n", self,suma);

return (void *)delay;   
                                                    }



int main(int argc, char **argv){

if(argc != 3){

    fprintf(stderr, "Maja byc 2 argumenty\n");
return 1;
                                                }
char *end;
long long sprawdzacz=strtoll(argv[1], &end, 10);

if(!sprawdzacz){

    fprintf(stderr, "Podana dana 1 nie jest liczba\n");
return 2;
                                                        }
char *end2;
int sprawdzacz2=strtol(argv[2], &end2, 10);

if(!sprawdzacz2){

    fprintf(stderr, "Podana dana 2 nie jest liczba\n");
return 2;
                                                        }           

if((sprawdzacz < 1) || (sprawdzacz > 1000000001)){

    fprintf(stderr, "Liczba1 mniejsza od 1 lub wieksza od 1000000000\n");
return 3;
                                                    }

if((sprawdzacz2 < 1) || (sprawdzacz2 > 101)){

    fprintf(stderr, "Liczba2 mniejsza od 1 lub wieksza od 100\n");
return 3;
                                                                }

if(sprawdzacz<sprawdzacz2){
    fprintf(stderr, "Watkow nie moze byc wiecej niz wyrazow ciagu\n");
return 4;
                                                            }


long long int wynik;
long long int wynik_z_dodatkiem=0;
long long int argument=strtoll(argv[1], &end, 10);
int argument2=strtol(argv[2], &end2, 10);

if((argument%argument2)==0){
        wynik=argument/argument2;
}
else{
        wynik=argument/argument2;
        wynik_z_dodatkiem=wynik+(argument%argument2);
}

int THREADS=sprawdzacz2;
pthread_t threads[THREADS];
char data[THREADS][40];

clock_t start_t=clock();
for(int i = 0; i < THREADS-1; i++) {
            sprintf(data[i],"%lld,%lld",wynik,1+wynik*i);
            pthread_create(threads + i, NULL, thread, data[i]);
                                 }


if(wynik_z_dodatkiem!=0){
        sprintf(data[THREADS-1],"%lld,%lld",wynik_z_dodatkiem,1+wynik*(THREADS-1));
        pthread_create(threads + THREADS-1, NULL, thread, data[THREADS-1]);
    }   
    else{
            sprintf(data[THREADS-1],"%lld,%lld",wynik,1+wynik*(THREADS-1));
            pthread_create(threads + THREADS-1, NULL, thread, data[THREADS-1]);
                }


for(int i = 0; i < THREADS; i++) {
            long retval;
            pthread_join(threads[i], (void *)&retval);

    }

clock_t koniec=clock();
printf("w/Threads: %.20f time=%f\n",wartosc*2,(double)(koniec-start_t)/CLOCKS_PER_SEC);

double suma=1;
double zmienna=1;

start_t=clock();
for(long long int i=1;i<sprawdzacz+1;i++){
        zmienna=4*(double)i*(double)i;
        suma*=zmienna/(zmienna-1);
                                   }

koniec=clock();
printf("wo/Threads: %.20f time=%f\n",suma*2,(double)(koniec-start_t)/CLOCKS_PER_SEC);

return 0;
}
