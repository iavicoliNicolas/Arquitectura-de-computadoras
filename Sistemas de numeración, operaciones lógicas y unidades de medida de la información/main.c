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
void wee

int main(int argc, char const *argv[])
{
    
    return 0;
}
