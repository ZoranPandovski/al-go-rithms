#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * - generic quicksort implementation -
 *
 * Originally implemented in one of my projects:
 * https://github.com/aurelien-brabant/libft/blob/master/src/core/ft_quick_sort.c
 *
 * C has no support for generic programming, but void pointers can be used to
 * mimic it. This implementation of quicksort makes use of this principle and
 * shares the same prototype than the standard library `qsort` function that
 * basically does the same thing i.e sorting (any) data.
 *
 * The algorithm is a standard recursive quicksort, but things differs when it
 * comes to swapping and comparing values: a temporary buffer is used to swap
 * the values byte per byte and a compare function is provided by the caller.
 * Similarly to `strcmp`, given its return value `n`, n < 0 if element 1 is less
 * than element 2, n > 0 if element 1 is greater than element 2 and n == 0 if
 * elements compare equal.
 */

static void swap(void* el1, void* el2, size_t size_el, void* tmp_buf) {
    memcpy(tmp_buf, el1, size_el);
    memcpy(el1, el2, size_el);
    memcpy(el2, tmp_buf, size_el);
}

static void* partition(void* low, void* high, size_t size_el,
                       int (*cmp)(void*, void*), void* tmp_buf) {
    void* max;
    void* pivot;

    pivot = low;
    max = high;
    while (low < high) {
        while (low <= max && cmp(low, pivot) <= 0)
            low = (uint8_t*)low + size_el;
        while (cmp(high, pivot) > 0) high = (uint8_t*)high - size_el;
        if (low < high) swap(low, high, size_el, tmp_buf);
    }
    swap(pivot, high, size_el, tmp_buf);
    return (high);
}

static void qsort_int(void* low, void* high, size_t size_el,
                      int (*cmp)(void*, void*), void* tmp_buf) {
    void* part;

    if (low < high) {
        part = partition(low, high, size_el, cmp, tmp_buf);
        qsort_int(low, (uint8_t*)part - size_el, size_el, cmp, tmp_buf);
        qsort_int((uint8_t*)part + size_el, high, size_el, cmp, tmp_buf);
    }
}

void gqsort(void* arr, size_t nb_el, size_t size_el, int (*cmp)(void*, void*)) {
    void* tmp_buf =
        malloc(size_el); /* a temporary buffer is used to store the
                            swapped element temporarily. While allocation is
                            done on the heap, it could be on the stack but would
                            require the use of variable length arrays*/

    void* high =
        (uint8_t*)arr + (nb_el - 1) * size_el; /* last element of the array */
    qsort_int(arr, high, size_el, cmp, tmp_buf);

    free(tmp_buf);
}

/**
 * COMPILED with `gcc generic_quicksort.c -o gqsort`
 *
 * TESTING
 *
 * To test this generic quicksort, the program must be provided arguments:
 * - the first argument must be either the string 'int' or 'string' which refers
 * to the data type that will be sorted (just in case, by 'string' I mean
 * pointer to char).
 * - The remaining arguments are the actual values that will be sorted. At least
 * one value must be provided to proceed. Integers are obtained by parsing the
 * strings using atoi so be aware of atoi's known limitations.
 * Strings are sorted lexicographically.
 *
 * Whichever datatype is chosen, gqsort will handle the sorting part.
 * The sorted data will then be displayed on the standard output, one element
 * per line.
 *
 * EXAMPLES
 *
 * $> ./gqsort int 12 -5 4 3 2 8
 * -5
 *  2
 *  3
 *  4
 *  8
 *  12
 *
 *  $> ./gqsort string 'hello' 'world' 'World' 'heLLo'
 *  World
 *  heLLo
 *  hello
 *  world
 */

int cmp_strings(void* v1, void* v2) {
    return strcmp(*(const char**)v1, *(const char**)v2);
}

int cmp_ints(void* p1, void* p2) {
    int n1 = *(int*)p1, n2 = *(int*)p2;

    return n1 - n2;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(
            stderr,
            "Usage: ./gqsort <int|string> <element> <element> [...elements]\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "string") == 0) {
        gqsort(argv + 2, argc - 2, sizeof(*argv), &cmp_strings);

        for (int i = 2; i != argc; ++i) {
            puts(argv[i]);
        }

    } else if (strcmp(argv[1], "int") == 0) {
        int* ints = malloc(sizeof(*ints) * (argc - 2));

        for (int i = 2; i != argc; ++i) {
            ints[i - 2] = atoi(argv[i]);
        }

        gqsort(ints, argc - 2, sizeof(*ints), &cmp_ints);

        for (int i = 2; i != argc; ++i) {
            printf("%d\n", ints[i - 2]);
        }

        free(ints);

    } else {
        fprintf(stderr, "gqsort error: unrecognized data type\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
