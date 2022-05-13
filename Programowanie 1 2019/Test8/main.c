#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funkcja.h"
int main()
{extern wybor,liczba,z,n,ch;
struct Figura**fig=NULL;
	do {menu();

		scanf("%d", &wybor);
ch = getchar();
system("cls");
    switch (wybor) {
		case 1:if (fig == NULL){
		    stworz(&fig,liczba);

}
		    else{printf("Juz istnieje\n");
		}
		system("cls");
break;


		case 2: if (fig != NULL) {dodajfigure(&fig,&liczba);

		}
		else{printf("Nie mozna wykonac\n");
		}
		system("cls");
break;


		case 3: if (fig != NULL){usunfigure(&fig,&liczba);
		}
else{printf("Nie mozna wykonac\n");
		}
		system("cls");
break;


		case 4: if (fig != NULL){dodajpunkt(fig,liczba);
}
else{printf("Nie mozna wykonac\n");
		}
		system("cls");
break;

		case 5: if (fig != NULL){usunpunkt(fig,liczba);
}
else{printf("Nie mozna wykonac\n");
		}
		system("cls");
break;
case 6: if (fig!= NULL){
    printf("Wzgledem jakiej zmiennej chcesz sortowac\n");

		minimenu();
		scanf("%d",&z);
		system("cls");
		if(z==1){
    sortuj(fig,liczba);}
    else if(z==2){
     sortuj2(fig,liczba);
    }
    else{printf("Podana zla wartosc\n");
    }}
		else{printf("Nie mozna wykonac\n");
		}

break;
		case 7: if (fig!= NULL){wyswietlfigury(fig, liczba);
		}
		else{printf("Nie mozna wykonac\n");
		}

break;
case 8: if (fig!= NULL){dlugosc(fig,liczba);

    }
		else{printf("Nie mozna wykonac\n");
		}

break;

case 9: if (fig!= NULL){pole_trojkata(fig,liczba);
    }
		else{printf("Nie mozna wykonac\n");
		}

break;
case 10: if (fig!= NULL){plik_zapis(fig,liczba,"tekst.txt");
   }
		else{printf("Nie mozna wykonac\n");
		}

break;

case 11:if (fig == NULL){
odczyt_plik(&fig,&liczba,"tekst.txt");
}
else{printf("Nie mozna wykonac\n");
		}

break;
case 12: tworcy();
break;
		case 0:
		    if (fig!= NULL) pamiec(&fig,&liczba);
			n = 0;

			break;

		default:
			printf("Podana zla wartosc\n");
			while (( ch = getchar()) != '\n');
			break;

		}
	} while (n!=0);

    return 0;
}
