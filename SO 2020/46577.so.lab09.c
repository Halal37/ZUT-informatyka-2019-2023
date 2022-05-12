// SO IS1 223A LAB09
// Wojciech Lidwin
// lw46577@zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <process.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
int main(int argc, char** argv) {

		if (argc != 2) {

			fprintf(stderr, "Musi byc jeden argument\n");
			return 1;
		}
	char* end;
	int sprawdzacz = strtol(argv[1], &end, 10);
	if (!sprawdzacz) {

		fprintf(stderr, "Podana dana nie jest liczba\n");
		return 2;
	}

	if ((sprawdzacz < 1) || (sprawdzacz > 13)) {

		fprintf(stderr, "Liczba mniejsza od 1 lub wieksza od 13\n");
		return 3;
	}
	else {

		if ((sprawdzacz == 1) || (sprawdzacz == 2)) {

			return 1;
		}
		else {
			STARTUPINFO si;
            STARTUPINFO si2;
			PROCESS_INFORMATION pi[2];
			

			memset(&si, 0, sizeof(si));
            si.cb = sizeof(si);
			memset(&si2, 0, sizeof(si2));
			si2.cb = sizeof(si2);

			memset(&pi[0], 0, sizeof(pi[0]));
			memset(&pi[1], 0, sizeof(pi[1]));


			int argument = strtol(argv[1], &end, 10);
			char argument1 = argument - 1;
			char argument2 = argument - 2;
			int status;
			int status2;
			char zmienna[100];
			char zmienna2[100];
			sprintf_s(zmienna,sizeof(zmienna), "%s %d",argv[0], argument1);
			sprintf_s(zmienna2,sizeof(zmienna2), "%s %d",argv[0], argument2);

			

			bool pierwszy=CreateProcessA(NULL, zmienna, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi[0]);
        if(pierwszy){

                bool drugi=CreateProcessA(NULL, zmienna2, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi[1]) ;
        if(drugi){
                            
                WaitForSingleObject(pi[1].hProcess, INFINITE);
                GetExitCodeProcess(pi[1].hProcess, &status2);
                CloseHandle(pi[1].hProcess);
                CloseHandle(pi[1].hThread);

                WaitForSingleObject(pi[0].hProcess, INFINITE);
			    GetExitCodeProcess(pi[0].hProcess, &status);
                CloseHandle(pi[0].hProcess);
                CloseHandle(pi[0].hThread);

                    printf("%d %d %d %d\n", GetCurrentProcessId(), pi[0].dwProcessId, argument1, status);
					printf("%d %d %d %d\n", GetCurrentProcessId(), pi[1].dwProcessId, argument2, status2);
				    printf("%d         %d\n", GetCurrentProcessId(), status + status2);
					printf("\n");
					return status + status2;
                    }
              }
			}
		}
}
