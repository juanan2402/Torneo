#include<stdio.h>
#include<string.h>
#include "Ftorneo.h"
const char equipos[100] = {"Equipos.txt"};
crearArchivo(equipos);

int main (){
    int finaliza;
    char termina[]="terminar";
    int numequipo=0;
    char nombre[20];
    char equipos[100];
    do {
    printf("Ingrese el nombre del equipo\n");
    scanf("%s",nombre);
    finaliza=strcmp(termina, nombre);
    if (finaliza==0)
        numequipo = numequipo + 1;
        guardarNombresArchivo(equipos, nombre);
    }
    while (finaliza!=0);

}
