// This is a basic tutorial to how implement threads in C++ using pthreads

#include <pthread.h>
#include <iostream>

#define ROW_SIZE 2
#define COLUMN_SIZE 2

struct sum{
    int value1;
    int value2;
    int result;
}typedef struct_sum;

void * routine(void * sum) { //This is our routine that will run in different threads
    int i = (((struct_sum *) sum)->value1 + ((struct_sum *) sum)->value2);
    ((struct_sum *)sum)->result = i;
    pthread_exit(sum);
}

int main(int argc, char * argv[]) {
    int mat_1[ROW_SIZE][COLUMN_SIZE] = {{1, 2},
                                        {6, 7}};
    int mat_2[ROW_SIZE][COLUMN_SIZE] = {{3, 15},
                                        {9, 14}};
    int mat_size = sizeof(mat_1) / sizeof(int);
    int row_size = sizeof(mat_1) / sizeof(mat_1[0]);
    int column_size = sizeof(mat_1[0]) / sizeof(int);
    pthread_t threads[mat_size];
    int thread_number = 0;
    int thread_handler;
    for (int row = 0; row < row_size; row++) {
        for (int column = 0; column < column_size; column++) {
            struct_sum *result;
            result = static_cast<struct_sum *>(malloc(sizeof(struct_sum)));
            result->value1 = mat_1[row][column];
            result->value2 = mat_2[row][column];
            result->result = 0;
            thread_handler = pthread_create(&threads[thread_number], nullptr, routine, result); //Here we instantiate our threads
            if(thread_handler) return(-1); //Here we check if our thread was instantiated correctly
            thread_number++;
        }
    }
//    int mat_result[ROW_SIZE][COLUMN_SIZE];
    for (int i = 0; i < mat_size; i++)
    {
        struct_sum *result;
        pthread_join(threads[i], (void**)&result); //Here we call our threads by joining then to the main thread. By doing this we ensure that each one will run until the end.
        std::cout << result->result << "\n";
        free(result); // We have to free the allocated memory used to store our matrices
    }

    return 0;
}
