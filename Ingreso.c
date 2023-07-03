#include <stdio.h>

int IngresarEquipos(){
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
    if (finaliza!=0){
        numequipo = numequipo + 1;
        fprintf(equipo, " %s \n", nombre);
        }
    }
    while (finaliza);
    printf("el torneo sera de %d equipos\n", numequipo);
    fclose(equipo);
    return numequipo;
}

void vectorNombres(char nombres[][100], int numEquipos){
    FILE *equipos;
    equipos= fopen("Equipos.txt", "r+");
    
    if (equipos == NULL)
    {
        printf("No se puede leer el archivo\n");
    }else
    {
        for(int i=0; i<numEquipos; i++){
            fscanf(equipos, "%s",nombres[i]);
        }
        fclose(equipos);
    }  
    
}