//NOT ACCEPTED!!!
//NOT FINISHED!!!
//NOT WORKING!!!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000002
typedef struct Tokens_s {
    int num; //количество слов в строке
    char **arr; //массив слов (каждый элемент –- строка, т.е. char*)
} Tokens;

void tokensSplit(Tokens *tokens, const char *str, const char *delims) {
    int i = 0;
    int ind1=0,ind2=0;
    char current = str[i];
    short isSep = 0, isLet = 0;
    if (tokens->arr == NULL) {
        int number = 0;
        while (current) {
            int temp = (int) current;
            if (temp == 44 || temp == 46 || temp == 58 || temp == 59) {
                if (!isSep) {
                    isSep = 1;
                    isLet = 0;
                }
            } else {
                if (!isLet) {
                    isLet = 1;
                    isSep = 0;
                    number++;
                }
            }
            current = str[++i];
        }
        tokens->num = number;
        char *good[number];
        tokens->arr=good;
    } else {
        int k=0;
        while (current) {
            int temp = (int) current;
            if (temp == 44 || temp == 46 || temp == 58 || temp == 59) {
                if (!isSep) {
                    isSep = 1;
                    isLet = 0;
                    ind2=i;
                    if (i){
                        int count=ind2-ind1;
                        char * t=malloc(count+1);
                        strncpy(t,&str[ind1],count);
                        t[count]=0;
                        tokens->arr[k]=t;
                        printf("%s\n",tokens->arr[k]);
                        k++;
                    }
                }//первое вхождение сепаратора
            } else {
                if (!isLet) {
                    isLet = 1;
                    isSep = 0;
                    ind1=i;
                } //первое вхождение буквы
            }
            current = str[++i];
        }
    }
}

//удаляет все ресурсы внутри tokens
void tokensFree(Tokens *tokens) {
    int del = 0;
    while (tokens->num) {
        free(tokens->arr[del]);
        del++;
        tokens->num--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Tokens slova = {};
    char string[N];
    scanf("%s", string);
    char separators[5] = ".,;:";
    tokensSplit(&slova, string, separators);
    printf("%d\n",slova.num);
    tokensSplit(&slova, string, separators);
    /*for (int i = 0; i < slova.num; ++i) {
        printf("%s\n",slova.arr[i]);
    }*/
    tokensFree(&slova);
    return 0;
}

