#include <stdio.h>
#include <stdlib.h>
#include "arrayaba/arrayaba.h"

struct Persona {
    char* name;
    int age;
    void* unkown;
};

struct Persona* crear_persona(char* name, int age, void* unkown) {
    struct Persona* persona = malloc(sizeof(struct Persona));

    if (persona == NULL) {
        return NULL;
    }

    persona->name = name;
    persona->age = age;
    persona->unkown = unkown;

    return persona;
};

int main(void) {

    //Array* arr = init_arr(20);
    struct Persona* per = crear_persona("test", 24, "bruh");

    printf("Nombre -> %s\n", (char*)per->unkown);

    free(per);

    /* rellenar_aleatorio(arr);

    char* array_str = tostring_array(arr);
    printf("Array -> %s\n", array_str);
    free(array_str);

    printf("Valor maximo -> %d\n", max_val(arr)); */

    return 0;
}
