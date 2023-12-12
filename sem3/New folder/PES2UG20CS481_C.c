#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "PES2UG20CS481_H.h"

void main() {
    int mat[SIZE][SIZE], row = 10, col = 10;
    queue *q = initialise();
    readmatrix(row,col, mat);
    ROW *top = multilist(mat, row, col);
    q = findpath(top,q);
    write(q);
}