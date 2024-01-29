#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrayaba.h"

Array* init_arr(size_t length) {
    Array* array = malloc(sizeof(Array));
    srand(time(NULL));

    array->length = length;
    array->arr = malloc(sizeof(int) * length);

    return array;
}

void free_arr(Array *arr) {
    free(arr->arr);
    free(arr);
    arr = NULL;
}

void rellenar_struct(Array* arr) {
    for (size_t i = 0; i < arr->length; i++) {
        arr->arr[i] = i;
    }
};

void rellenar_manual(Array* arr) {
    for (int i = 0; i < arr->length; i++) {
        printf("Introduce el numero para el valor %d", i);
        scanf("%d", &arr->arr[i]);
    }
}

void rellenar_aleatorio(Array* arr) {
    for (int i = 0; i < arr->length; i++) {
        arr->arr[i] = rand() % 20;
    }
}

char* tostring_array(Array* arr) {
    int allocated_mem = 2 + arr->length + ((arr->length - 1) * 2);
    printf("Memoria para el string array -> %d\n", allocated_mem);

    // each char that belongs to the `arr_string` will take up atleast 5 bytes
    // among squeare backets ([, ]) ints placeholders (%d), commas and white spaces
    char* idx_val = malloc(5);
    char* arr_string = malloc(allocated_mem);
    arr_string[0] = '\0';

    for (int i = 0; i < arr->length; i++) {
        if (i == 0) {
            sprintf(idx_val, "[%d, ", arr->arr[i]);
        } else if (i == arr->length - 1) {
            sprintf(idx_val, "%d]", arr->arr[i]);
        } else {
            sprintf(idx_val, "%d, ", arr->arr[i]);
        }
        strcat(arr_string, idx_val);
    }
    free(idx_val);

    return arr_string;
}

int max_val(Array* arr) {
    int max = 0;
    for (int i = 0; i < arr->length; i++) {
        if (arr->arr[i] > max) {
            max = arr->arr[i];
        }
    }

    return max;
}

int min_val(Array* arr) {
    int min = max_val(arr);
    for (int i = 0; i < arr->length; i++) {
        if (arr->arr[i] < min) {
            min = arr->arr[i];
        }
    }

    return min;
}

int sum(Array* arr) {
    int sum = 0;
    for (int i = 0; i < arr->length; i++) {
        sum += arr->arr[i];
    }

    return sum;
}

void desordenar(Array* arr) {
    int posicionRandom = rand() % 20;
    int aux = arr->arr[0];
    arr->arr[0] = arr->arr[posicionRandom];
    arr->arr[posicionRandom] = aux;
}
