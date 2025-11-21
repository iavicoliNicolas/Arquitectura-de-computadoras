#include<stdio.h>
#include<stdlib.h>

// Practica de sistemas de numeración, operaciones lógicas y unidades de medida de la información

/*
Recibe como parámetro un número entero (int nro) y un
string (char* s), y rellene el string con los caracteres 
‘1’ o ‘0’ con la representación binaria del número entero
*/
void rellenaBinarios(int nro, char* s){
    for (int i = 31; i >= 0; i--) { // Asumiento un entero de 32 bits
        s[i] = (nro & 1) ? '1' : '0';
        nro >>= 1;
    }
    s[32] = '\0'; // Añadir el carácter nulo al final del string
}

// Recibe como parámetro un número entero (int nro) y comprueba que la computadora realiza complemento a 2
void verificaComplementoADos(int nro){
    int complemento = ~nro + 1;
    printf("Número: %d, Complemento a dos: %d\n", nro, complemento);
}

/*
Realizar una función en C que recibe un byte (char), donde cada bit representa un día de
la semana (ver imágen), e imprima la descripción los días activos.
*/
void imprimeDiasActivos(char byte){
    const char* dias[] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};
    printf("Días activos: ");
    for (int i = 0; i < 7; i++) {
        if (byte & (1 << i)) {
            printf("%s ", dias[i]);
        }
    }
    printf("\n");
}

/*
Realizar una función “weekday_set” en C que reciba como parámetros: un puntero a char
y un número entero (de 0 a 6), y que configure en 1 el bit correspondiente al día de la
semana (siendo 0 domingo y 6 sábado) como en el ejercicio anterior. Del mismo modo,
escribir una función “weekday_reset”, con los mismos parámetros, para configurar el bit en
0.
*/
void weekday_set(char *byte, int dia) {
    if (dia >= 0 && dia <= 6) {
        *byte |= (1 << dia);
    }
}

void weekday_reset(char *byte, int dia) {
    if (dia >= 0 && dia <= 6) {
        *byte &= ~(1 << dia);
    }
}

int main(int argc, char const *argv[])
{

    int funcion;
    printf("Seleccione la función a ejecutar:\n1. Rellenar binarios\n2. Verificar complemento a dos\n3. Imprimir días activos y modificar días\n");
    scanf("%d", &funcion);

    switch(funcion) {
        case 1: {
            int nro;
            char binarios[33];
            printf("Ingrese un número entero: ");
            scanf("%d", &nro);
            rellenaBinarios(nro, binarios);
            printf("Representación binaria: %s\n", binarios);
            break;
        }
        case 2: {
            int nro;
            printf("Ingrese un número entero: ");
            scanf("%d", &nro);
            verificaComplementoADos(nro);
            break;
        }
        case 3:
        {
            char dias = 0;
            // Configurar días activos
            weekday_set(&dias, 0); // Domingo
            weekday_set(&dias, 1); // Lunes
            weekday_set(&dias, 3); // Miércoles

            imprimeDiasActivos(dias);

            // Restablecer un día
            weekday_reset(&dias, 1); // Restablecer Lunes
            imprimeDiasActivos(dias);
            break;
        default:
            printf("Opción no válida.\n");
            return 1;
    }
 

    return 0;
}
