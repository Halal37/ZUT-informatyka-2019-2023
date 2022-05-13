#ifndef FUNKCJA_H_INCLUDED
#define FUNKCJA_H_INCLUDED
#define FSIZE 20
typedef struct Point{
int x,y;
}Point;
typedef struct Figura{
unsigned short size;
struct Point**p;
}Figura;
extern void stworz(Figura***,int);
extern void dodajfigure(Figura***,int*);
extern void usunpunkt(Figura**,int);
extern void dodajpunkt(Figura**,int);
extern void wyswietlfigury(Figura**, int );
extern void usunfigure(Figura***, int*);
extern void sortuj(Figura**,int);
extern void sortuj2(Figura**,int);
extern void dlugosc(Figura**,int);
extern void pole_trojkata(Figura**,int);
extern void plik_zapis(Figura*const*const,int,char*);
extern void odczyt_plik(Figura***,int*,char*);
void menu();
void minimenu();
void tworcy();
extern void pamiec(struct Figura***, int *);
//void graficznie(Figura**,int);
#endif // FUNKCJA_H_INCLUDED
