#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)
    const char* OS = "Windows";
#else
    #ifdef __unix__
        const char* OS = "Unix";
    #else
        const char* OS = "Unknown";
    #endif
#endif

void clearScreen() {
    if (OS == "Windows") {
        system("cls");
    } else if (OS == "Unix") {
        system("clear");
    } else {
        printf("OS not supported for screen clearing.\n");
    }
}