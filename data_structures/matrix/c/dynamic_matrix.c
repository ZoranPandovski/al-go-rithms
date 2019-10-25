// Create dynamic matrices
// Implements basic operations
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    float *data;
    int rows, cols;
} matrix_t;

// Allocation and destruction
matrix_t *create_matrix(float numbers[], int rows, int cols);
void destroy_matrix(matrix_t *matrix);

// Get and set
float get_at_matrix(matrix_t *matrix, int row, int col);
void set_at_matrix(matrix_t *matrix, float value, int row, int col);

// In place operations
void scale_matrix(matrix_t *matrix, float scalar);
void add_matrix(matrix_t *lhs, matrix_t *rhs);
void subtract_matrix(matrix_t *lhs, matrix_t *rhs);

// New matrix
matrix_t *multiply_matrix(matrix_t *lhs, matrix_t *rhs);

// Display
void print_matrix(matrix_t *matrix, int spacing);

int
main(int argc, char *argv[]) {
    float numbers[] = {5, 3, 2, 4};
    float numbers_2[] = {3, 2, 1, 0};
    matrix_t *test = create_matrix(numbers, 2, 2);
    matrix_t *b = create_matrix(numbers_2, 2, 2);
    
    printf("Initial matrix: \n");
    print_matrix(test, 1);

    printf("\nScale matrix by 3: \n");
    scale_matrix(test, 3);
    print_matrix(test, 1);
    
    printf("\nAdd \n");
    print_matrix(b, 1);
    printf("to the original matrix:\n");
    add_matrix(test, b);
    print_matrix(test, 1);

    printf("\nMultiply these matrices:\n");
    matrix_t *product = multiply_matrix(test, b);
    print_matrix(product, 1);

    destroy_matrix(test);
    destroy_matrix(b);
    destroy_matrix(product);
    return 0;
}

matrix_t *
create_matrix(float numbers[], int rows, int cols) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    assert(matrix);
    
    matrix->data = (float *)calloc(rows * cols, sizeof(float));
    assert(matrix->data);

    if(numbers) {    
        int i;
        for(i = 0; i < rows * cols; i++) {
            matrix->data[i] = numbers[i];
        }
    }

    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

void
destroy_matrix(matrix_t *matrix) {
    free(matrix->data);
    free(matrix);
}

float
get_at_matrix(matrix_t *matrix, int row, int col) {
    assert(row >= 0 && row < matrix->rows);
    assert(col >= 0 && col < matrix->cols);
    return matrix->data[(row * matrix->rows) + col];
}

void
set_at_matrix(matrix_t *matrix, float value, int row, int col) {
    assert(row >= 0 && row < matrix->rows);
    assert(col >= 0 && col < matrix->cols);
    matrix->data[(row * matrix->rows) + col] = value;
}

void
scale_matrix(matrix_t *matrix, float scalar) {
    int i;
    for(i = 0; i < matrix->rows * matrix->cols; i++) {
        matrix->data[i] *= scalar;
    }
}

void
add_matrix(matrix_t *lhs, matrix_t *rhs) {
    assert(lhs->rows == rhs->rows && lhs->cols == rhs->cols);
    int i;
    for(i = 0; i < lhs->rows * lhs->cols; i++) {
        lhs->data[i] += rhs->data[i];
    }
}

void
subtract_matrix(matrix_t *lhs, matrix_t *rhs) {
    assert(lhs->rows == rhs->rows && lhs->cols == rhs->cols);
    int i;
    for(i = 0; i < lhs->rows * lhs->cols; i++) {
        lhs->data[i] -= rhs->data[i];
    }
}

matrix_t *
multiply_matrix(matrix_t *lhs, matrix_t *rhs) {
    assert(lhs->cols == rhs->rows);

    // Unoptimized implementation (naive dotproduct solution)
    matrix_t *product = create_matrix(NULL, lhs->rows, rhs->cols);
    assert(product);

    int i, j, c;
    for(i = 0; i < lhs->rows; ++i) {
        for(j = 0; j < rhs->cols; ++j) {
            float dot = 0.0;

            // Dot product of lhs row and rhs column
            for(c = 0; c < lhs->cols; ++c) {
                dot += get_at_matrix(lhs, i, c) * get_at_matrix(rhs, c, j);
            }
            set_at_matrix(product, dot, i, j);
        }
    }
    return product;
}

void 
print_matrix(matrix_t *matrix, int spacing) {
    int i, j, s;
    for(i = 0; i < matrix->rows; i++) {
        for(j = 0; j < matrix->cols; j++) {
            printf("%.2f", get_at_matrix(matrix, i, j));
            for(s = 0; s < spacing; s++) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}