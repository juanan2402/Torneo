#include <stdio.h>

struct Equipo {
    char nombre[50];
    int puntos;
};

void ingresarEquipo(struct Equipo equipos[], int numEquipos)
{
    if (numEquipos >= 10) {
        printf("Se ha alcanzado el límite máximo de equipos.\n");
        return;
    }

    printf("Ingrese el nombre del equipo: ");
    scanf("%s", equipos[numEquipos].nombre);

    equipos[numEquipos].puntos = 0;

    printf("El equipo se ha registrado exitosamente.\n");
}

void simularPartida(struct Equipo equipos[], int numEquipos)
{
    int equipo1, equipo2;
    printf("Ingrese el número del primer equipo: ");
    scanf("%d", &equipo1);
    printf("Ingrese el número del segundo equipo: ");
    scanf("%d", &equipo2);

    // Simulación de la partida entre los equipos

    printf("La partida ha finalizado. Se actualizan los puntajes.\n");
    equipos[equipo1].puntos += 1;
    equipos[equipo2].puntos += 1;
}

void ingresarPartida(struct Equipo equipos[], int numEquipos)
{
    int equipo, puntos;
    printf("Ingrese el número del equipo: ");
    scanf("%d", &equipo);
    printf("Ingrese los puntos obtenidos en la partida: ");
    scanf("%d", &puntos);

    // Actualizar los puntos del equipo ingresado
    equipos[equipo].puntos += puntos;

    printf("Los puntos se han registrado exitosamente.\n");
}

int main()
{
    struct Equipo equipos[10];
    int numEquipos = 0;
    int opcion;

    do {
        printf("----- Menú del juego -----\n");
        printf("1. Ingresar equipo\n");
        printf("2. Simular partida\n");
        printf("3. Ingresar puntos de partida\n");
        printf("4. Salir\n");
        printf("Ingrese el número de la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarEquipo(equipos, numEquipos);
                numEquipos++;
                break;
            case 2:
                simularPartida(equipos, numEquipos);
                break;
            case 3:
                ingresarPartida(equipos, numEquipos);
                break;
            case 4:
                printf("Saliendo del juego...\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 4);

    return 0;
}
