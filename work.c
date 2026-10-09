#include <stdio.h>

//Q79: Perform diagonal traversal of a matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];

    // Read the matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Perform diagonal traversal
    for (int d = 0; d < m + n - 1; d++) {
        if (d % 2 == 0) {
            // Traverse from bottom to top
            for (int i = (d < m ? d : m - 1); i >= 0 && d - i < n; i--) {
                printf("%d ", matrix[i][d - i]);
            }
        } else {
            // Traverse from top to bottom
            for (int i = (d < n ? d : n - 1); i >= 0 && d - i < m; i--) {
                printf("%d ", matrix[d - i][i]);
            }
        }
    }

    return 0;
}



//Q80: Multiply two matrices.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
3 2
7 8
9 10
11 12
Output 1:
58 64
139 154

*/

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d", &r1, &c1);
    int matrix1[r1][c1];

    // Read the first matrix elements
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    scanf("%d %d", &r2, &c2);
    int matrix2[r2][c2];

    // Read the second matrix elements
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication not possible\n");
        return 0;
    }

    int result[r1][c2];

    // Initialize the result matrix to zero
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}