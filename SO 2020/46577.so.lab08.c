// SO IS1 223A LAB08
// Wojciech Lidwin
// lw46577@zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main(int argc, char **argv){

for(int i=0; i<argc; i++)

if(argc != 2){

fprintf(stderr, "Musi byc jeden argument\n");
return 1;
}
char *end;
int sprawdzacz=strtol(argv[1], &end, 10);
if(!sprawdzacz){

fprintf(stderr, "Podana dana nie jest liczba\n");
return 2;
}

if((sprawdzacz < 1) || (sprawdzacz > 13)){

fprintf(stderr, "Liczba mniejsza od 1 lub wieksza od 13\n");
return 3;
}
else{

if((sprawdzacz==1) || (sprawdzacz==2)){

return 1;
}else{

int argument=strtol(argv[1], &end, 10);
char argument1=argument-1;
char argument2=argument-2;

pid_t drugi;
pid_t pierwszy;
pierwszy=fork();

int status;
int status2;
char zmienna[10];
char zmienna2[10];

sprintf(zmienna,"%d",argument1);
sprintf(zmienna2,"%d",argument2);

if(pierwszy == 0){

execl(argv[0],argv[0],zmienna, NULL);
fprintf(stderr,"Rodzaj blendu: %s\n",strerror(errno));


}else{
drugi=fork();
if(drugi ==0){
execl(argv[0],argv[0],zmienna2, NULL);
fprintf(stderr,"Rodzaj bledu: %s\n",strerror(errno));

}else{
int dziecko2=wait(&status2);
int dziecko=wait(&status);

printf("%d %d %d %d\n",getpid(),dziecko,argument1,WEXITSTATUS(status));
printf("%d %d %d %d\n",getpid(),dziecko2,argument2,WEXITSTATUS(status2));
printf("%d        %d\n",getpid(),WEXITSTATUS(status)+WEXITSTATUS(status2));
printf("\n");

return WEXITSTATUS(status)+WEXITSTATUS(status2); 
}
}
}
}
return 0;}
