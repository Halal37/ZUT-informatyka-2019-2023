// SO IS1 223A LAB11
// Wojciech Lidwin
// lw46577@zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>
double wartosc=0;
HANDLE mutex;
typedef struct {
char msg[20];
int retval;
} DATA;
DWORD WINAPI thread(LPVOID data) {
    DATA *dat = (DATA *) data;
char *end;
char *importowane=strtok(dat->msg,",");
long long int zakres=0;
long long int pierwszy=0;

if(importowane){
    zakres=strtoll(importowane,&end,10);
                                    }
importowane=strtok(NULL,",");

if(importowane){
    pierwszy=strtoll(importowane,&end,10);
                                    }

DWORD self = GetCurrentThreadId();
srand(self);
printf("Thread %ld size=%lld pierwszy=%lld\n", self,zakres, pierwszy-1);

double suma=0.0;
double zmienna=0.0;



for(long long int i=pierwszy-1;i<zakres+pierwszy-1;i++){
        zmienna=(double)pow(-1,i)/(2*(double)i+1);
        suma+=zmienna;
                                                        }
WaitForSingleObject(mutex,INFINITE);
wartosc+=suma;
ReleaseMutex(mutex);


long delay = suma;
printf("Thread %ld sum=%.20lf\n", self,suma);
dat->retval = delay;
return 0;
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

HANDLE *threads=malloc(THREADS*sizeof(HANDLE));
DWORD *thrdids=malloc(THREADS*sizeof(DWORD));
DATA *data=malloc(THREADS*sizeof(DATA));
mutex=CreateMutex(NULL,FALSE,NULL);
clock_t start_t=clock();
for(int i = 0; i < THREADS-1; i++) {
sprintf(data[i].msg,"%lld,%lld",wynik,1+wynik*i);
threads[i] = CreateThread(NULL,0,thread,data+i,0,thrdids+i);
 }

if(wynik_z_dodatkiem!=0){
    sprintf(data[THREADS-1].msg,"%lld,%lld",wynik_z_dodatkiem,1+wynik*(THREADS-1));
  threads[THREADS-1] = CreateThread(NULL,0,thread,data+THREADS-1,0,thrdids+THREADS-1);  
}else{
    sprintf(data[THREADS-1].msg,"%lld,%lld",wynik,1+wynik*(THREADS-1));
  threads[THREADS-1] = CreateThread(NULL,0,thread,data+THREADS-1,0,thrdids+THREADS-1);  
                }
 for(int i = 0; i < THREADS; i++) {
 WaitForSingleObject(threads[i], INFINITE);
 CloseHandle(threads[i]);
 }
clock_t koniec=clock();
printf("w/Threads: %.20f time=%f\n",wartosc*4,(double)(koniec-start_t)/CLOCKS_PER_SEC);

double suma=0;
double zmienna=0;
start_t=clock();
for(long long int i=0;i<sprawdzacz;i++){
        zmienna=(double)pow(-1,i)/(2*(double)i+1);
        suma+=zmienna;
                                   }

koniec=clock();
printf("wo/Threads: %.20f time=%f\n",suma*4,(double)(koniec-start_t)/CLOCKS_PER_SEC);
return 0;
}
