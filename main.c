
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char alumnos[5][30];
    char materia[5][30];
    float calificaciones[5][3];
    float calificacion_alta[5][3]; // llenar en 11
    float calificacion_baja[5][3]; // llenar en -1
    int cant_aprobados[3] = {0, 0, 0};
    int cant_reprobados[3] = {0, 0, 0};
    float promedios_asignatura[3] = {0, 0, 0};
    float promedios_estudiante[5] = {0, 0, 0, 0, 0};
    int auxil = -1, val, opcin, len, cont = 0;
    char nombuscar[30];

    /*Con el fin de evitar que datos residuales de la memoria
    dedicada a este arreglo interfiera con el resultado del programa*/


    do
    {
        printf("==================================================\n");
        printf("      SISTEMA DE GESTION DE CALIFICACIONES        \n");
        printf("==================================================\n");
        printf("\n");
        printf("1. Ingresar alumnos y notas\n"); // RESUELTOO!!!!1
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
            char continuar;
            printf("Ingrese el nombre de las 3 materias\n");
            // Pedir el nombre de las materias
            printf("\n");
            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese el nombre de la materia %d:\n>> ", i);
                fflush(stdin);
                fgets(materia[i], 30, stdin);

                len = strlen(materia[i]) - 1;
                materia[i][len] = '\0';
            }
            do
            {
                // Pedir el nombre del alumno
                printf("Ingrese el nombre del alumno %d: ", cont);
                fflush(stdin);
                fgets(alumnos[cont], 30, stdin);

                len = strlen(alumnos[cont]) - 1;
                alumnos[cont][len] = '\0';

                // Pedir las calificaciones
                printf("Ingrese las calificaciones del estudiante %s:\n", alumnos[cont]);
                for (int j = 0; j < 3; j++)
                {

                    do
                    {
                        printf("Ingrese la calificación para %s: ", materia[j]);
                        fflush(stdin);
                        val = scanf("%f", &calificaciones[cont][j]);
                        if (val != 1)
                        {
                            printf("Por favor, ingrese un valor correcto..\n");
                        }
                        else if (calificaciones[cont][j] < 0 || calificaciones[cont][j] > 10)
                        {
                            printf("Las calificaciones no pueden ser negativas o mayores a 10.\n");
                        }
                    } while (val != 1 || calificaciones[cont][j] < 0 || calificaciones[cont][j] > 10);
                }
                cont++;

                // Incrementar el índice del estudiante
                // ver cuantos estudiantes se ingresaron

                // Preguntar si desea continuar con otro estudiante
                printf("¿Desea ingresar otro estudiante? (s/n): ");
                fflush(stdin);
                scanf("%c", &continuar);

                while (continuar != 'N' && continuar != 'n' && continuar != 'S' && continuar != 's')
                {
                    printf("Ingrese una opcion valida\n");
                    fflush(stdin);
                    scanf("%c", &continuar);

                    if (continuar != 'N' && continuar != 'n' && continuar != 'S' && continuar != 's')
                    {
                        printf("Ingrese los valores correctos\n");
                    }
                }

            } while (continuar == 's' || continuar == 'S');

            break;

        case 2:
            int f = 0;

            printf("Ingrese el nombre del estudiante que desea obtener el promedio de notas...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < cont; i++)
            {
                if (strcmp(alumnos[i], nombuscar) == 0)
                {
                    printf("Promedio del estudiante %s\n", alumnos[i]);
                    len = strlen(alumnos[i]) - 1;
                    if (alumnos[i][len] == '\n')
                    {
                        alumnos[i][len] = '\0';
                        
                    }
                    f = 1;
                    promedios_estudiante[i] = 0;

                    for (int j = 0; j < 3; j++)
                    {
                        promedios_estudiante[i] += calificaciones[i][j] / 3;
                    }
                    printf("\n");
                    printf("El promedio es: %.2f\n", promedios_estudiante[i]);
                }
            }
            if (f == 0)
            {
                printf("No existe ningun estudiante llamado asi\n");
            }
            break;
        case 3:
            f = 0;

            printf("Ingrese el nombre de la materia que desea obtener el promedio de notas...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < 3; i++)
            {
                if (strcmp(materia[i], nombuscar) == 0)
                {
                    printf("Promedio de la materia: %s\n", materia[i]);
                    len = strlen(materia[i]) - 1;
                    if (materia[i][len] == '\n')
                    {
                        materia[i][len] = '\0';
                        
                    }
                    f = 1;
                    promedios_asignatura[i] = 0;

                    // recordar que 'cont' es la cantidad de estudiantes que se ingresaron
                    for (int j = 0; j < cont; j++)

                    {
                        promedios_asignatura[i] += calificaciones[j][i] / cont;
                        /*La variable cont se usa para hacer
                        la operación de promedio en función a los
                        alumnos que se haya ingresado.*/
                    }
                    printf("\n");
                    printf("El promedio es: %.2f\n", promedios_asignatura[i]);
                }
            }
            if (f == 0)
            {
                printf("No existe la materia buscada dentro del registro..\n");
            }

            break;
        case 4:
            
            // Hallar la calificación más alta y baja por estudiante
            float max = -1, min = 11;
            f = 0;
            printf("Ingrese el nombre del estudiante que desea obtener la calificacion mas alta y baja...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < cont; i++)
            {
                if (strcmp(alumnos[i], nombuscar) == 0)
                {
                    printf("Estudiante %s\n", alumnos[i]);
                    len = strlen(alumnos[i]) - 1;
                    if (alumnos[i][len] == '\n')
                    {
                        alumnos[i][len] = '\0';
                        
                    }
                    f = 1;

                    for (int j = 0; j < 3; j++)
                    {
                        if (calificaciones[i][j] > max)
                        {
                            max = calificaciones[i][j];
                        }
                        if (calificaciones[i][j] < min)
                        {
                            min = calificaciones[i][j];
                        }

                    }
                    calificacion_alta[i][0] = max;
                    calificacion_baja[i][0] = min;

                    printf("Clasificacion mas alta: %.2f\n", calificacion_alta[i][0]);
                    printf("Clasificacion mas baja: %.2f\n", calificacion_baja[i][0]);
                    
                }
            }
            if (f == 0)
            {
                printf("No existe ningun estudiante llamado asi\n");
            }

            break;

        default:
            break;
        }

    } while (opcin != 7);

    return 0;
}
