#include<stdio.h>
#include<string.h>

int main (){
    int finaliza;
    char termina[]="cerrar";
    int numequipo=0;
    char nombre[20];
    char equipos[100];
    do {
    printf("Ingrese el nombre del equipo\n");
    scanf("%s",nombre);
    finaliza=strcmp(termina, nombre);
    if (finaliza!=0)
        numequipo = numequipo + 1;
    }
    while (finaliza!=0);


}
