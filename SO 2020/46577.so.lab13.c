// SO IS1 223A LAB13
// Wojciech Lidwin
// lw46577@zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MEM_SIZE   1000

char koniecgry(char *tablica){
char a='0';
for(int i=0; i<10;i=i+3){
if(tablica[i]==tablica[i+1]&&
tablica[i+1]==tablica[i+2]&&
tablica[i]!='-'){
a='1';
return a;
}
}
for(int i=0; i<3;i++){
if(tablica[i]==tablica[i+3]&&
tablica[i+3]==tablica[i+6]&&
tablica[i]!='-'){
a='1';
return a;
}
}
if(tablica[0]==tablica[4]&&
tablica[4]==tablica[8]&&
tablica[4]!='-')
{
a='1';
return a;
}
if(tablica[2]==tablica[4]&&
tablica[4]==tablica[6]&&
tablica[4]!='-')
{
a='1';
return a;
}
return a;
}
char koniecgry2(char *tablica){
char a='0';
if(tablica[0]!='-'&&
tablica[1]!='-'&&
tablica[2]!='-'&&
tablica[3]!='-'&&
tablica[4]!='-'&&
tablica[5]!='-'&&
tablica[6]!='-'&&
tablica[7]!='-'&&
tablica[8]!='-'){
a='1';
return a;}
return a;
}
char dla_gracza(char *tablica){
char a='0';
if(tablica[0]=='-'&&
tablica[1]=='-'&&
tablica[2]=='-'&&
tablica[3]=='-'&&
tablica[4]=='-'&&
tablica[5]=='-'&&
tablica[6]=='-'&&
tablica[7]=='-'&&
tablica[8]=='-'){
a='1';
return a;}

return a;
}
void wyswietlanie(char *tablica) 
{ 
    printf("\n\n"); 
      
    printf("\t\t\t  %c | %c  | %c  \n", tablica[0], 
                             tablica[1], tablica[2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n", tablica[3], 
                             tablica[4], tablica[5]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n\n", tablica[6], 
                             tablica[7], tablica[8]); 
} 
int main(int argc, char **argv){
if(argc != 2){

 fprintf(stderr, "Musi byc jeden argument\n");
 return 1;
}
char *end;
char *dane;
HANDLE MapFile = CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,MEM_SIZE,argv[1]);
if(MapFile==NULL){
 printf("Nie dziala CreateFileMapping \n");
 return 1;
}
dane=MapViewOfFile(MapFile,FILE_MAP_ALL_ACCESS,0,0,MEM_SIZE);
if(dane==NULL){
 printf("Nie dziala MapViewOfFile\n ");
 CloseHandle(MapFile);
 return 1;
}
int n=0;
dane[10]='0';
dane[11]='0';
dane[12]='0';
int do_while1=0;
for(int i=0; i<9;i++){
 dane[i]='-';

}



printf("Witaj graczu\n");
dane[9]='X';



while(1==1){
 wyswietlanie(dane);

if(dane[10]=='1'||dane[11]=='1'){
 if(dane[10]=='1'){
  printf("Zwyciezca jest gracz: %c\n ",dane[9]);
  break;
 }else{
  printf("Remis:\n ");
  break;
 }
}
dane[12]=dla_gracza(dane);
if(dane[12]=='0')
 printf("Gra gracz: %c\n ",dane[9]);



 printf("Podaj dane\n");
 do_while1=0;
do{
 scanf("%d",&n);
 if(n>0&&n<11&&dane[n-1]=='-'){

  do_while1=1;
  if(n==10){
    dane[10]='1';
  }
 }
}while(do_while1==0);
dane[n-1]=dane[9];
wyswietlanie(dane); 


dane[10]=koniecgry(dane);
if(dane[10]=='1'){
 wyswietlanie(dane); 
 printf("Zwyciezca jest gracz: %c\n ",dane[9]);
 break;
}
dane[11]=koniecgry2(dane);
if(dane[11]=='1'){
 wyswietlanie(dane); 
 printf("Remis: \n ");
 break;
}
if(dane[9]=='X'){
 dane[9]='O';
}else{
 dane[9]='X';
}

if(dane[9]=='X'){printf("Czekaj na 1 gracza\n ");
 while(dane[9]=='X'){

   Sleep(1);
   if(dane[10]=='1'||dane[11]=='1'){
     if(dane[10]=='1'){
         printf("Zwyciezca jest gracz: %c\n ",dane[9]);
         break;
}else{
       printf("Remis:\n ");
       break;
}
}
}

}else{ printf("Czekaj na 2 gracza\n ");
while(dane[9]=='O'){

  Sleep(1);
  if(dane[10]=='1'||dane[11]=='1'){
   if(dane[10]=='1'){
      printf("Zwyciezca jest gracz: %c\n ",dane[9]);
      break;
}else{
      printf("Remis:\n ");
      break;
}
}
}
}


wyswietlanie(dane);


}
if(!UnmapViewOfFile(dane)) {
   fprintf(stderr, "Nie dziala UnmapViewOfFile\n");
   CloseHandle(MapFile);
return 1;}
return 0;
}


