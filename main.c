
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char alumnos[5][30];
    char materia[5][30];
    float calificaciones[5][3];
    float calificacion_alta[5][3]; // llenar en 11
    float calificacion_baja[5][3]; // llenar en -1
    int cant_aprobados = 0, cant_reprobados = 0;
    float promedios_asignatura[3] = {0,0,0};
    float promedios_estudiante[5] = {0,0,0,0,0};
    int auxil = -1, val, opcin, len, cont = 0;
    int i=0, j=0;

    do
    {
        printf("==================================================\n");
        printf("      SISTEMA DE GESTION DE CALIFICACIONES        \n");
        printf("==================================================\n");
        printf("\n");
        printf("1. Ingresar alumnos y notas\n");//RESUELTOO!!!!1
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
                printf("Ingrese el nombre del alumno %d: ", i);
                fflush(stdin);
                fgets(alumnos[i], 30, stdin);

                len = strlen(alumnos[i]) - 1;
                alumnos[i][len] = '\0';
                

                // Pedir las calificaciones
                printf("Ingrese las calificaciones del estudiante %s:\n", alumnos[i]);
                for (int j = 0; j < 3; j++)
                {

                    do
                    {
                        printf("Ingrese la calificación para %s: ", materia[j]);
                        fflush(stdin);
                        val = scanf("%f", &calificaciones[i][j]);
                        if (val != 1)
                        {
                            printf("Por favor, ingrese un valor correcto..\n");
                        }
                        else if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                        {
                            printf("Las calificaciones no pueden ser negativas o mayores a 10.\n");
                        }
                    } while (val != 1 || calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
                }

                i++; // Incrementar el índice del estudiante

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

            cont = i; // ver cuantos estudiantes se ingresaron
            break;

        case 2:
            char nombuscar[30];
            int f=0;

            printf("Ingrese el nombre del estudiante que desea obtener el promedio de notas...\n");
            printf(">> ");
            fflush(stdin);
            fgets(nombuscar, 30, stdin);

            len = strlen(nombuscar) - 1;
            nombuscar[len] = '\0';

            for (int i = 0; i < cont; i++)
            {
                if(strcmp(alumnos[i], nombuscar) == 0){
                    printf("Promedio del estudiante %s\n", alumnos[i]);
                    len = strlen(alumnos[i]) - 1;
                    alumnos[i][len] = '\0';
                    f=1;

                    for (int j = 0; j < 3; j++)
                    {
                        promedios_estudiante[i] += calificaciones[i][j] / 3;
                    }
                    printf("\n");
                    printf("El promedio es: %.2f\n", promedios_estudiante[i]);
                }
            }
            if (f==0)
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
