#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){
    char * cadena="-1455464";
    char *octal="015$";
    int d,o;
    d= caracterComoEntero(cadena);
    printf("%d\n",d);
    o = automataOctal(octal);// 0 si es aceptado, -1 si es rechazado
    printf("Resultado del Autómata Octal: %d", o);
    return 0;
}

/*Punto 1*/
//Autómata Octal
int automataOctal(char *cadena){

    //TT
    size_t estados[][3] = {
    //  0,   [1-7],     $
        {1,     4,      4},//0
        {4,     2,      4},//1
        {2,     2,      0},//2
        {4,     4,      4} //4
    };

    //Declaro estado final
    size_t estado_final=0;
    //Declaro estado inicial
    size_t estado_inicial = 0;
    //inicio analizando la cadena
    size_t estado = estado_inicial;
    int i;
    char c;
    int largo_cadena=strlen(cadena);
    for(i=0;i<largo_cadena;i++){
        //Caracter donde está parado
        c=cadena[i];
        //Hace la transición respecto a cuál caracter del alfabeto se está procesando
        if(c=='0') estado = estados[estado][0];
        else if(c >= '1' && c <='7') estado = estados[estado][1];
        else if(c == '$') estado = estados[estado][2];
        //Si no pertenece al alfabeto va directo a estado de rechazo
        else estado = 4;

        //Si se rechaza, ya salimos del autómata y lo declaramos inválido
        if(estado == 4) return -1;
    }

    //Si no acabó en un estado final, el autómata se rechaza por estar incompleto
    if(estado == estado_final) return 0;
    else return -1;
}











/*Punto 2*/
//Para cuando se ejecute esta función, ya asumimos que pasa por el autómata anteriormente, por eso no controlamos
//que esté bien escrito.
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
            nroResultante = nroResultante * 10 + cadena[i] - '0';
        }else{//Si es otro caracter lo borro
            break;
        }
        i++;
    }
    return signo * nroResultante;//Multiplico el signo por el número que compusimos a partir de la cadena
}

