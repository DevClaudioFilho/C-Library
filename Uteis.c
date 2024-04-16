
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>//necessário p/ função time()

int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int Factorial(int N)
{
    if (N == 0) return 1;
    return N * Factorial(N-1);
}

int LerInteiro(char *txt)
{
    int x;
    printf("%s : ", txt);
    scanf("%d", &x);
    return x;
}


#if defined(_WIN32) || defined(_WIN64)
    const char* OS = "Windows";
#else
    #ifdef __unix__
        const char* OS = "Unix";
    #else
        const char* OS = "Unknown";
    #endif
#endif

void limparTerminal() {
    if (OS == "Windows") {
        system("cls");
    } else if (OS == "Unix") {
        system("clear");
    } else {
        printf("OS not supported for screen clearing.\n");
    }
    return;
}
