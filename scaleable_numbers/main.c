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
        zero[0][i] = '*';                       //Rand oben befüllen mit '*'
        zero[size-1][i] = '*';                  //Rand unten
        zero[i][0] = '*';                       //Rand links
        zero[i][size-1] = '*';                  //Rand rechts
        zero[i][size-1-i] = '*';                //diagonale
    }

    zero[0][0] = ' ';                           //Ecke links oben befüllen mit ' '
    zero[0][size-1] = ' ';                      //Ecke rechts oben
    zero[size-1][0] = ' ';                      //links unten
    zero[size-1][size-1] = ' ';                 //rechts unten

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
