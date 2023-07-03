#include <stdio.h>
void Ranking(int numEquipos, char nombres[][100], int puntos[100])
{
    //Using the Results from the Puntaje function, the for loops arrange the teams in descending order
    char sAux[100];
    int aux;
    FILE *Puntos;
    
    Puntos = fopen("puntos.txt", "w+");

    if (Puntos == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }
    else
    {
        for (int i = 0; i < numEquipos - 1; i++)
        {
            for (int j = i + 1; j < numEquipos; j++)
            {
                if (puntos[i] < puntos[j])
                {
                    //The points are exchanged using an aux variable
                    aux = puntos[j];
                    puntos[j] = puntos[i];
                    puntos[i] = aux;
                    //strcpy function is caled to rearrange the strings, using an Aux string
                    strcpy(sAux, nombres[j]);
                    strcpy(nombres[j], nombres[i]);
                    strcpy(nombres[i], sAux);
                }
            }
        }
        for (int i = 0; i <numEquipos; i++)
        {
            //Adds the new order to the Puntos file
            fprintf(Puntos, "%s %d\n", nombres[i], puntos[i]);
        }
        fclose(Puntos);
    }
    
}

int posEquipo(char nombres[][100], int x, char equipo[100])
{
    //Finds the placement of each team called, ensures points are added to the correct team
    int  pos= 0;
    for (int i = 0; i < x; i++)
    {
        if (strcmp(nombres[i], equipo)== 0)
        {
            //if the name matches the one in the array, the position is stored
            pos = i;
        }
    }

    return pos;
}
void Puntaje(int numEquipos, char nombres[][100])
{
    int puntos[100];
    int e1 = 0, e2 = 0;
    char nombre1[100], nombre2[100];
    for(int i=0; i<numEquipos; i++){
        puntos[i]=0;
    }
    FILE *Partidos;
    FILE *Puntos;

    Partidos = fopen("Partidos.txt", "r+");
    Puntos = fopen("Puntos.txt", "r+");

    if (Partidos == NULL || Puntos == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }
    else
    {
        //finds the data in the file to be used until no more data can be pulled
        while (fscanf(Partidos, "%s %s %d %d", nombre1, nombre2, &e1, &e2) == 4)
        {
            if (e1 > e2)
            {
                //if the goals scored are higher, the team is awarded 3 points
                puntos[posEquipo(nombres, numEquipos, nombre1)] += 3;
            }
            else if (e2 > e1)
            {
                puntos[posEquipo(nombres, numEquipos, nombre2)] += 3;
            }
            else
            {
                //both points get 1 poitn for stalemate
                puntos[posEquipo(nombres, numEquipos, nombre1)] += 1;
                puntos[posEquipo(nombres, numEquipos, nombre2)] += 1;
            }
        }

        
    
        

        fclose(Partidos);
        fclose(Puntos);
    }
    //Ranking function called to arrange the teams
    Ranking(numEquipos, nombres, puntos);

}

void ImprimirResultados(){
    //This functions gets the results and points from each game and prints them in a table
    char e1[100], e2[100];
    int g1=0, g2=0, p1=0, p2=0;

    FILE *Partidos;
    FILE *Puntos;
    Partidos = fopen("partidos.txt", "r+");
    Puntos = fopen("Puntos.txt", "r+");
    if (Partidos == NULL|| Puntos== NULL)
    {
        printf("No se puede leer algun archivo\n");
    }
    else
    {
        printf("______Tabla de resultados:______\n");
        printf("_______________GOLES_______________\n");
        printf("|       Partido        |    Resultado   |\n");
        while (fscanf(Partidos, "%s %s %d %d", e1, e2, &p1, &p2) == 4)
        {
            printf("____________________________________\n");
            printf("|%-5s - %-14s|%5d-%-5d|\n",e1, e2, p1, p2);
        }

        printf("\n \n");
        printf("_______PUNTOS_______\n");
        printf("|  Equipo  |Puntaje|\n");
        while (fscanf(Puntos, "%s %d", e1, &p1) == 2)
        {
            printf("___________________\n");
            printf("|%-10s|%7d|\n",e1, p1);
        }
        //indents are used for centering in each variable
        fclose(Partidos);
        fclose(Puntos);
    }
}