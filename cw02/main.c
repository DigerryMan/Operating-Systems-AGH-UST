#include <stdio.h>

#ifndef DYNAMIC
    #include "collatz.h"
#endif

#ifdef DYNAMIC
    #include <dlfcn.h>
    int (*test_collatz_conjecture)(int, int);
#endif

int main(void){
    #ifdef DYNAMIC
        void* uchwyt = dlopen("./libcollatz.so", RTLD_LAZY);
        if(!uchwyt){
            printf("Blad otwarcia biblioteki");
            return 1;
        }

        
        test_collatz_conjecture = dlsym(uchwyt, "test_collatz_conjecture");

    #endif

    int maxIter, input;
    printf("Podaj maxymalny iterator: ");
    scanf("%d", &maxIter);

    printf("Podaj liczbe: ");
    scanf("%d", &input);

    int res = test_collatz_conjecture(input, maxIter);
    printf("Wynik: %d \n", res);


    #ifdef DYNAMIC
        dlclose(uchwyt);
    #endif

    return 0;
}
