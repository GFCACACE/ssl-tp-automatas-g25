#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//TT
    size_t estados[][4] = {
        {1,4,4,4},
        {4,2,4,4},
        {2,2,0,4}
    };

    //Declaro estados finales
    size_t estado_final=0;
    size_t cant_estados_finales=1;

    //Declaro alfabeto
    size_t alfabeto[][50]={
        "0",
        "1234567",
        "$"
    };
    size_t cant_alfabeto=3;


    int main(void){

        printf("%c",alfabeto[1][5]);



        return 0;
    }


