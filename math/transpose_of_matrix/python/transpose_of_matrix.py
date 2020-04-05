def transpose_matrix(matrix):
    matrix_rows_quantity = len(matrix)
    matrix_column_quantity = len(matrix[0])

    transposed_matrix = [[0] * matrix_rows_quantity for _ in range(matrix_column_quantity)]

    for row in range(matrix_rows_quantity):
        for column in range(matrix_column_quantity):
            transposed_matrix[column][row] = matrix[row][column]

    return transposed_matrix
