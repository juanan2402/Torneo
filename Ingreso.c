#include <stdio.h>

void IngresarEquipos(){
    FILE *equipo;
    equipo= fopen("Equipos.txt", "r+"); 
    int finaliza;
    char termina[]="terminar";
    int numequipo=0;
    char nombre[20];
    do {
    printf("Ingrese el nombre del equipo\n");
    scanf("%s",nombre);
    finaliza=strcmp(termina, nombre);
    if (finaliza)
        numequipo = numequipo + 1;
        fprintf(equipo, "%d %s\n", numequipo, nombre);
        
    }
    while (finaliza);
    fclose(equipo);
}