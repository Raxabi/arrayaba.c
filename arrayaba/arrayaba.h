/**
 * Array handling / manipulation ported from Java to C.
 *
 * Since the code contained on this project is very simple,
 * I suppose that everyone is capable to compile this to a library (static or dynamic)
 * In any case, I will put compilation instructions soon!.
 *
 * Feels free of get the source code, to your personal or enterprise use,
 * improve the code and making a pull request to this repository
 * or give recommendation or report potential errors in this lib
 *
 * Enjoy my simply and dirty work, its my first 'project', (try of project xd) in c :) (coded in nvim btw xddd)
 *
 * Glossary:
 *  Array: Refers to a struct that contains 2 members (respectively):
 *      - an int array (declared as pointer: `int*`)
 *      - the length of that int array
 *  array: Refers to the array inside of an `Array` struct
 *  Array->arr: Refers to the same as 'array'
 *
 *  Coded by Raxabi at https://github.com/Raxabi/arrayaba.c
 */

#ifndef _ARRAYABA_H_
#define _ARRAYABA_H_

#include <stddef.h>

typedef struct Array {
    int* arr;
    size_t length;
} Array;

/**
 * Initializes an `Array` struct, allocating memory for them -
 * which will take as much as `sizeof(Array)` returns using `malloc`
 * 
 * Also allocate memory for the internal int array that will be managed
 */
Array* init_arr(size_t length);

/**
 * Free's the memory allocated for `arr` and the internal array
 * that an `Array` struct handles
 *
 * Array->arr and Array itself
 */
void free_arr(Array* arr);

/**
 * Fills the array `Array->arr` with `Array->length', it means will be filled from 0 to `Arraey->length`
 */
void rellenar_struct(Array* arr);

/**
 * Fills the internal array asking for every array position value
 *
 * * Recommended for arrays with few length's
 */
void rellenar_manual(Array* arr);

/**
 * Fills the internal array `Array->arr` with random numbers from 0 to `Array->length` - 1
 */
void rellenar_aleatorio(Array* arr);

/**
 * Returns the string representation of the `Array->arr`, similar to toString method in java
 * !!remember to free the returned char pointer!!
 */
char* tostring_array(Array* arr);

/**
 * Returns the higher value in the array
 */
int max_val(Array* arr);

/**
 * Returns the lowest value in the array
 */
int min_val(Array* arr);

/**
 * Returns the sum of all the elements in the array
 */
int sum(Array* arr);

/**
 * Mess up the array changing one random position of the array by the first position
 */
void desordenar(Array* arr);

#endif // _ARRAYABA_H_
