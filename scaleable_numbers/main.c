#include <stdio.h>

void make_zero (int scale) {
    int size = 4 + scale;
    char zero[size][size];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            zero[i][j] = ' ';                   //befüllen mit ' '
        }
    }

    for (int i = 0; i < size; ++i) {            //den rand befüllen mit '*'
        zero[0][i] = '*';
        zero[size-1][i] = '*';
        zero[i][0] = '*';
        zero[i][size-1] = '*';
        zero[i][size-1-i] = '*';
    }

    zero[0][0] = ' ';
    zero[0][size-1] = ' ';
    zero[size-1][0] = ' ';
    zero[size-1][size-1] = ' ';

    //print_zero(zero, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%c", zero[i][j]);   //normale print-schleife
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Input scaling-size (Only whole numbers):\n");
    scanf("%d", &n);
    make_zero(n);
    return 0;
}