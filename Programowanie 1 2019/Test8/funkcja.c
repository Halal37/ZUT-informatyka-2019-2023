#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "funkcja.h"
#define dwa 2
#define dziesiec 1000
int liczba=4,n=1,z=0,wybor;
char ch;
stworz(Figura*** geo, int ilosc) {
    srand(time(NULL));
    Figura** temp = (Figura**) malloc(sizeof(Figura*)*ilosc);
    for(int i=0; i< ilosc; i++) {
            int rozm=rand()%5+1;
        temp[i] = (Figura*) malloc(sizeof(Figura));
        temp[i]->p=(Point**)malloc(sizeof(Point*)*rozm);
    for(int j=0;j<rozm;j++){
        temp[i]->p[j]=(Point*)malloc(sizeof(Point));
        temp[i]->p[j]->x=rand()%256;
        temp[i]->p[j]->y=rand()%256;
    }
    temp[i]->size=rozm;}
    *geo = temp;
}
static char* strtok_r(
    char *str,
    const char *delim,
    char **nextp)
{
    char *ret;

    if (str == NULL)
    {
        str = *nextp;
    }

    str += strspn(str, delim);

    if (*str == '\0')
    {
        return NULL;
    }

    ret = str;

    str += strcspn(str, delim);

    if (*str)
    {
        *str++ = '\0';
    }

    *nextp = str;

    return ret;
}

dodajfigure(Figura*** geo, int *ilosc){
  int new_size = *ilosc+1;
  Figura** temp = (Figura**) malloc(sizeof(Figura*)*(new_size));
  int rozm=rand()%5+1;
  for (int i=0; i<*ilosc; ++i){
        temp[i] = (*geo)[i];
  temp[*ilosc] = (Figura*) malloc(sizeof(Figura));
  temp[*ilosc]->p=(Point**)malloc(sizeof(Point*)*rozm);
  temp[*ilosc]->size=rozm;
         for(int j=0;j<rozm;j++){
        temp[*ilosc]->p[j]=(Point*)malloc(sizeof(Point));
        temp[*ilosc]->p[j]->x=rand()%256;
        temp[*ilosc]->p[j]->y=rand()%256;
    }}
  free(*geo);
  *geo = temp;
  ++(*ilosc);
}
static void Blad(){
printf("Udalo sie pobrac dane.\n");
}
static void Blad2(){
printf("Nie mozliwe wykonanie polecenia.\n");
}

usunfigure(struct Figura*** geo, int *ilosc){
    srand(time(NULL));
    int losowa=rand()%*ilosc;
 int new_size=*ilosc-1;
 if ( new_size > 0 ) {
struct Figura** tym = (struct Figura **)malloc(sizeof(struct Figura*)*new_size);
for(int i=0; i< new_size; i++)
			tym[i] = (*geo)[i];
		int rozm = (*geo)[new_size]->size;
for(int j=0; j< rozm; j++)
			free((*geo)[new_size]->p[j]);
	free((*geo)[new_size]->p);
		free((*geo)[new_size]);
		*geo = tym;
		*ilosc = new_size;}
		else{Blad2();}

	}
dodajpunkt(Figura**geo,int ilosc){
    srand(time(NULL));
int losowa=rand()%ilosc;
int rozm=geo[losowa]->size+1;
Point** temp = (struct Point**)(malloc(sizeof(struct Point*) * (rozm)));
temp[geo[losowa]->size]= (struct Point*)(malloc(sizeof(struct Point)));

for (int i = 0; i < rozm; i++) {
				temp[i] = geo[losowa]->p[i];}
				geo[losowa]->p[geo[losowa]->size]=temp;
				++(geo[losowa]->size);
				geo[losowa]->p[geo[losowa]->size-1]->x=rand()%256;
        geo[losowa]->p[geo[losowa]->size-1]->y=rand()%256;
}


usunpunkt(Figura**geo,int ilosc){
        srand(time(NULL));
int losowa=rand()%ilosc;
        int new_size = geo[losowa]->size;

if (new_size > 0) {
        struct Point** tym = (struct Point**)(malloc(sizeof(struct Point*) * (new_size - 1)));
        if (new_size > 0) {
for (int i = 0; i < new_size - 1; i++) {
                tym[i] = geo[losowa]->p[i];
            }
}

        geo[losowa]->p = tym;
        geo[losowa]->size = new_size - 1;}
        else{Blad2();}
       }




wyswietlfigury(Figura**geo, int ilosc) {
    for(int i=0; i< ilosc; i++) {
            if(geo[i]->size==1)printf("FIGURA JEST PUNKTEM \n");
            if(geo[i]->size==2) printf("FIGURA JEST PROSTA \n");
            if (geo[i]->size>2) printf("FIGURA JEST %d-KATEM\n",geo[i]->size);
              for(int j=0; j< geo[i]->size; j++) {
        printf("%d \t %d \n", geo[i]->p[j]->x, geo[i]->p[j]->y);}

    }
}

pamiec(Figura*** geo, int *ilosc) {
    for(int i=0; i< *ilosc; i++) {
        free((*geo)[i]);
        (*geo)[i] = NULL;
    }
	free(*geo);
   *geo = NULL;
}
sortuj(struct Figura**geo,int ilosc){
    int tym=0;
  for(int i = 0; i < ilosc; i++)
    {int rozm=geo[i]->size;
    if(rozm!=1);
        for(int j = 0; j < rozm; j++)
        { for(int k=j+1;k<rozm;k++){
            if (geo[i]->p[j]->x>geo[i]->p[k]->x){
                                                            tym=geo[i]->p[j];
                                                            geo [i]->p[j]=geo[i]->p[k];
                                                           geo [i]->p[k]=tym;}

            }

        }
    }
    }
  sortuj2(struct Figura**geo,int ilosc){
    int tym=0;
  for(int i = 0; i < ilosc; i++)
    {int rozm=geo[i]->size;
    if(rozm!=1);
        for(int j = 0; j < rozm; j++)
        { for(int k=j+1;k<rozm;k++){
            if (geo[i]->p[j]->y>geo[i]->p[k]->y){
                                                            tym=geo[i]->p[j];
                                                            geo [i]->p[j]=geo[i]->p[k];
                                                           geo [i]->p[k]=tym;}

            }

        }
    }
    }
    dlugosc(struct Figura**geo,int ilosc){
    double tym=0;
    int Y=0,X=0;
    for(int i = 0; i < ilosc; i++){int rozm=geo[i]->size;
    int n=0;
    if(rozm!=1){
        for(int j = 0; j < rozm; j++){for(int k=j+1;k<rozm;k++){

            Y=geo[i]->p[k]->y-geo[i]->p[j]->y;
        X=geo[i]->p[k]->x-geo[i]->p[j]->x;
                tym=sqrt(pow(X,dwa)+pow(Y,dwa));
                n++;
               printf("Dlugosci wektora %d-figury\t od %d-punktu\t do %d-punktu\t %f\n",i+1,j+1,k+1,tym);}}
        }}
    }
   pole_trojkata(struct Figura**geo,int ilosc){
        double P=0,pol=0.5;
        int n=0,a=0,b=0,c=0,d=0;
        for(int i = 0; i < ilosc; i++){int rozm=geo[i]->size;
    if(rozm==3){
            a=geo[i]->p[1]->y-geo[i]->p[0]->y;
    b=geo[i]->p[2]->y-geo[i]->p[0]->y;
    c=geo[i]->p[1]->y-geo[i]->p[0]->y;
    d=geo[i]->p[2]->x-geo[i]->p[0]->x;
        P=pol*abs(a*b-c*d);
            n++;
    printf("Pole %d-figury %d-trojkata\t %f\n",i+1,n,P);
    }else{printf("%d Figura nie jest trojkatem\n",i+1);}
    }}
plik_zapis(Figura*const*const geo,int ilosc,char*name){
FILE *fout;
if((fout=fopen(name,"w"))!=NULL)
    {fprintf(fout,"%d",ilosc);
         for (int i=0; i<ilosc; ++i)
         {int rozm=geo[i]->size;
             fprintf(fout,"\n%d;",geo[i]->size);
             for(int j=0;j<rozm;j++){
             fprintf(fout,"%d,%d;",geo[i]->p[j]->x,geo[i]->p[j]->y);
             }
         }
         if(fclose(fout)!=NULL)
         {
             fprintf(stderr,"blad przy zamknieciu pliku do zapisu\n");
         }
    }
}
static int zmiana_int_char(char c[]) {
    int i = 0;
    i=atoi(c);
    return i;
}
odczyt_plik(Figura*** geo,int *ilosc,char*name){
FILE *fout;
if((fout=fopen(name,"r"))!=NULL){{
        char cos[dziesiec],cos2[dziesiec];
        char* pom1;
            char* pom2;
            char* war1;
            char* war2;
fgets(cos,dziesiec,fout);
int new_size=zmiana_int_char(cos);
*ilosc=new_size;
     Figura** temp = (Figura**) malloc(sizeof(Figura*)*new_size);
      for(int i=0; i< new_size; i++) {
            fgets(cos2,dziesiec,fout);
            pom1 = strtok_r(cos2, ";", &pom2);
            int rozm=zmiana_int_char(pom1);
        temp[i] = (Figura*) malloc(sizeof(Figura));
        temp[i]->p=(Point**)malloc(sizeof(Point*)*rozm);
      for(int j=0;j<rozm;j++){
     pom1 = strtok_r(NULL, ";", &pom2);
                        war1 = strtok_r(pom1, ",", &war2);
        temp[i]->p[j]=(Point*)malloc(sizeof(Point));
        temp[i]->p[j]->x=zmiana_int_char(war1);
        temp[i]->p[j]->y=zmiana_int_char(war2);
    }
    temp[i]->size=rozm;
    }
    *geo = temp;


     } fclose(fout);
            Blad();}
     else {printf("Nie mozna wczytac bazy .\n");

     }
}

static void czas(){
    time_t wsk;
    time (&wsk);
    char* zegar;
    zegar=ctime(&wsk);
    if (zegar)
        printf ("W tym dniu i o tej godzinie rozpoczyna sie twoja przygoda z tym programem: %s", zegar);
}
static void witaj(){
printf("Witaj uzytkowniku\n");}
static void opcja(){
    printf("Wybierz opcje\n");}
static void menuwyp(){
printf("Menu\n");}
static void punkt1(){
printf("1. Stworz baze figur lub wczytaj z pliku tekstowego\n");}
static void punkt2(){
printf("2. Dodaj figure\n");}
static void punkt3(){
printf("3. Usun figure\n");}
static void punkt4(){
printf("4. Dodaj punkt do figury\n");}
static void punkt5(){
printf("5. Usun punkt do figury\n");}
static void punkt6(){
printf("6. Sortuj\n");}
static void punkt7(){
printf("7. Pokaz figury\n");}
static void punkt8(){
printf("8. Pokaz dlugosci stworzonych wektorow\n");}
static void punkt9(){
printf("9. Pole trojkata\n");}
static void punkt10(){
printf("10. Zapis do pliku\n");}
static void punkt11(){
printf("11. Wczytaj z pliku\n");}
static void punkt12(){
printf("12. Autor\n");}
static void punkt0(){
printf("0. Exit\n");}
static void sortX(){
     printf("1. X\n");}
     static void sortY(){
     printf("2. Y\n");}

void menu(){
static int liczenie=0;
liczenie++;
if(liczenie==1){ witaj();
czas();}
else{printf("To twoje %d dzialanie w menu\n",liczenie);}
menuwyp();
punkt1();
punkt2();
punkt3();
punkt4();
punkt5();
punkt6();
punkt7();
punkt8();
punkt9();
punkt10();
punkt11();
punkt12();
punkt0();
opcja();
}
void minimenu(){
    sortX();
    sortY();
}
void tworcy(){
printf("Imie i Nazwisko: Wojciech Lidwin\n Indeks: lw46577\n Grupa: 125A\n");
printf("I troche Stack Overflow ;)\n");}
