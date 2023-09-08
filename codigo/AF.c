#include <stdio.h>
#include <math.h>


// int cantidadCaracteres=11;
// //Realizo la TT mediante size_t (generar una matriz)
// size_t estadosTT[][cantidadCaracteres]={

// }



int main(void){
    char * cadena="-1455464";
    int d;
    d= caracterComoEntero(cadena);
    printf("%d",d);

    return 0;
}



//Función que convierte caracter a entero.
int caracterComoEntero(char* cadena)//ingresa el caracter en formato int (nos dará su número equivalente de la tabla ASCII)
{
    int i=0;
    int nroResultante=0;
    int signo=1;
     if(cadena[i]=='-'){//Contemplé el caso del número negativo
            signo=-1;
            i++;
        }
    while (cadena[i] != '\0')//Mientras la cadena no termine
    {
       
        if(cadena[i]>='0' && cadena[i]<='9'){//si es un caracter entre 0 y 9 lo sumamos a la composición
            nroResultante = nroResultante * 10 + cadena[i] - 48;
        }else{//Si es otro caracter lo borro
            break;
        }
        i++;
    }
    return signo * nroResultante;//Multiplico el signo por el número que compusimos a partir de la cadena
}

