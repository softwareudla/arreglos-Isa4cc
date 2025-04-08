#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char alumnos[5][30];
    float calificaciones[5][3];
    float calificacion_alta[5][3]; // llenar en 11
    float calificacion_baja[5][3]; // llenar en -1
    int cant_aprobados = 0, cant_reprobados = 0;
    float promedios_asignatura[3];
    float promedios_estudiante[5][3];
    int auxil = -1, val, opcin, len;

    do
    {
        printf("==================================================\n");
        printf("      SISTEMA DE GESTION DE CALIFICACIONES        \n");
        printf("==================================================\n");
        printf("\n");
        printf("1. Ingresar alumnos y notas\n");
        printf("2. Calcular el promedio de calificaciones para cada estudiante\n");
        printf("3. Calcular el promedio por asignatura\n");
        printf("4. Encontrar la calificacion mas alta y baja por estudiante\n");
        printf("5. Encontrar la calificacion mas alta y baja por asignatura\n");
        printf("6. Determinar cuantos estudiantes aprobaron o reprobaron cada asignatura\n");
        printf("7. Salir\n");
        printf("\n");
        printf("Ingrese una opcion:\n");
        printf(">> ");
        scanf("%d", &opcin);
        switch (opcin)
        {
        case 1:
            for (int i = 0; i < 5; i++) // alumnos
            {
                printf("Ingrese el nombre del alumno %d: ", i);
                fflush(stdin);
                fgets(alumnos[i], 30, stdin);

                printf("Ingrese las calificaciones del estudiante %s", alumnos[i]);
                fflush(stdin);
                len = strlen(alumnos[i]) - 1;
                alumnos[i][len] = '\0';

                // '\0'  es el caracter nulo
                // reemplaza el salto de linea por el caracter nulo

                for (int j = 0; j < 3; j++) // calificaciones por materia
                {
                    do
                    {

                        do
                        {
                            printf("Materia %d:\n", j);
                            printf(">> ");
                            fflush(stdin);
                            val = scanf("%f", &calificaciones[i][j]);
                            if (val != 1)
                            {
                                printf("Por favor ingrese un valor correcto..\n");
                            }
                        } while (val != 1);

                        if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                        {
                            printf("Las calificaciones no pueden ser negativas o mayores a 10.\n");
                        }
                        else if (calificacion_alta[i][j] < calificaciones[i][j])
                        {
                            calificacion_alta[i][j] = calificaciones[i][j];
                        }
                        else if (calificacion_baja[i][j] > calificaciones[i][j])
                        {
                            calificacion_baja[i][j] = calificaciones[i][j];
                        }

                    } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
                }
            }

            break;

        default:
            break;
        }

    } while (opcin != 7);

    return 0;
}
