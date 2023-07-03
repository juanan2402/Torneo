//Taller Torneo de Futbol
//Integrantes: Thommy Calderon, Nicolás Cajas, Juan Serrano

#include<stdio.h>
#include<string.h>
#include "Torneo.h"
#include "Ingreso.h"
#include "Resultados.h"


int main (){
    int numEquipos, opcion;
    char nombres[100][100];
    char equipos[100] = "Equipos.txt";
    //File Creation
    FILE *equipo;
    FILE *puntos;

    equipo = fopen("Equipos.txt", "w+");
    if (equipo == NULL)
    {
        printf("No se puede crear el archivo\n");
    }else
    {
        printf("Se ha creado el archivo Equipos.txt\n");
        fclose(equipo);
    } 


    puntos = fopen("Puntos.txt", "w+");
        if (equipo == NULL)
        {
            printf("No se puede crear el archivo\n");
        }else
        {
            printf("Se ha creado el archivo Puntos.txt\n");
            fclose(puntos);
        } 


    //Main Menu
    printf("\n-- Bienvenido al simulador de partidas --\n");
    printf("Ingresa los nombres sin espacios de los equipos a participar, una vez ingresados todos, escribir la palabra 'terminar'\n");
    numEquipos = IngresarEquipos();
    vectorNombres(nombres, numEquipos);

        printf("\n1. Ingresar manualmente los datos de los partidos\n");
        printf("2. Simular los datos aleatoriamente\n");
        scanf("%d", &opcion);
    switch(opcion){
        case 1:
            Ingreso(numEquipos,nombres);
        break;
        case 2:
            Aleatorio(numEquipos, nombres);
        break; 

    }
    // Score calculation
    Puntaje(numEquipos, nombres);

    ImprimirResultados();
    

    

}
