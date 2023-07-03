#include<stdio.h>
#include <stdlib.h>
#include <time.h>

 void Aleatorio(int numEquipos,char  nombres[][100]){
    int e1 = 0, e2 = 0;
    FILE *result;

    result = fopen("partidos.txt", "w+");

    if (result == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }else{
        srand(time(NULL));
        for (int i = 0; i < numEquipos; i++)
        {
            for (int j = 0; j < numEquipos; j++)
            {
                if(i != j){
                    //Generates and adds the results for each game using the rand function, max goals set at 10
                    e1 = rand() % 11;
                    e2 = rand() % 11;
                    fprintf(result, "%s %s %d %d\n",nombres[i], nombres[j], e1, e2);
                }
            }
        }

        fclose(result);
    }

 }
 void Ingreso(int numEquipos,char  nombres[][100]){
    int e1 = 0, e2 = 0;
    FILE *result;

    result = fopen("partidos.txt", "w+");

    if (result == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }else{
        for (int i = 0; i < numEquipos; i++)
        {
            for (int j = 0; j < numEquipos; j++)
            {
                //If guarantees the team cannot play against itself
                if(i != j){
                    //Manually asks for each game result, using nested for loops to act as a matrix array
                    printf("Ingrese el resultado del partido %s - %s\n",nombres[i],nombres[j]);
                    printf("%s: \n", nombres[i]);
                    scanf("%d", &e1);
                    printf("%s:\n ", nombres[j]);
                    scanf("%d", &e2);
                    printf("\n");
                    fprintf(result, "%s %s %d %d\n",nombres[i], nombres[j], e1, e2);
                }
            }
        }

        fclose(result);
    }

 }
 