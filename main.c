#include<stdio.h>
#include<string.h>
#include "Torneo.h"
#include "Ingreso.h"
#include "Resultados.h"


int main (){
    char equipos[100] = "Equipos.txt";
    FILE *equipo; 

    equipo = fopen("Equipos.txt", "w+");
    if (equipo == NULL)
    {
        printf("No se puede crear el archivo\n");
    }else
    {
        printf("Se ha creado el archivo, %s\n",equipos);
        fclose(equipo);
    }  
    IngresarEquipos();

    

}
