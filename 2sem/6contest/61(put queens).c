#include <stdio.h>
#include <stdlib.h>

char vertical[13], diag_p[26], diag_m[26];

int diager(r, c, rows) {
    int min = r - c;
    if (min >= 0) {
        return min;
    } else {
        return (rows - 1) - min;
    }
}

char *matr;
char exist = 0;

void var(int row, int column, int i) {
    if (i == row) {
        exist = 1;
        return;
    }
    for (int j = 0; j < column; ++j) {
        int temp = diager(i, j, row);
        if (matr[i * column + j] == 'b' && !vertical[j] && !diag_p[i + j] && !diag_m[temp]) {
            matr[i * column + j] = 'q';//queen
            vertical[j] = 1;
            diag_p[i + j] = 1;
            diag_m[temp] = 1;
            //break;
            var(row, column, i + 1);
            if (exist)return;
            matr[i * column + j] = 'b';//queen
            vertical[j] = 0;
            diag_p[i + j] = 0;
            diag_m[temp] = 0;
        }
    }
}

int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    short row, column;
    fscanf(filein, "%hd%hd", &row, &column);
    matr = malloc(row * column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            char cur = 0;
            fscanf(filein, "%c", &cur);
            if (cur == 10) {//new line
                fscanf(filein, "%c", &cur);
            }
            if (cur == '.') {
                matr[i * column + j] = 'p';//prohibited
            } else {
                matr[i * column + j] = 'b';//blank
            }
        }
    }
    var(row, column, 0);
    if (exist) {
        fprintf(fileout, "%s", "YES\n");
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matr[i * column + j] == 'q') {
                    fprintf(fileout, "%c", 'X');
                } else {
                    fprintf(fileout, "%c", '.');
                }
            }
            fprintf(fileout, "%c", '\n');
        }
    } else {
        fprintf(fileout, "%s", "NO");
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

