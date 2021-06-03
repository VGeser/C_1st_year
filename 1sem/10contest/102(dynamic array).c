#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#define N 1000002
typedef struct Dynamic_Array_s{
    int capability;
    int taken;
    int new_elem;
    char *strings;
}Dynamic_Array;
/*int comp(const int *i, const int *j) {
    return *i - *j;
}*/
Dynamic_Array arrays[N]={0};
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int request=0,max=0;
    int size=sizeof(char);
    fscanf(filein,"%d",&request);
    for (int i = 0; i < request; ++i) {
        int key=0;
        fscanf(filein,"%d",&key);
        max=(max>=key)?max:key;
        if (!arrays[key].new_elem){
            arrays[key].strings=malloc(32*size);
            arrays[key].capability=4;
        } else if(arrays[key].taken>=arrays[key].capability){
            arrays[key].strings=realloc(arrays[key].strings,arrays[key].capability*16*size);
            arrays[key].capability*=2;
        } fscanf(filein,"%s",&arrays[key].strings[arrays[key].new_elem]);
        arrays[key].taken++;
        arrays[key].new_elem+=8;
    }
    for (int i = 0; i <= max; ++i) {
        if (arrays[i].taken){
            int p=0;
            for (int j = 0; j < arrays[i].taken; ++j) {
                fprintf(fileout,"%d ",i);
                char temp[8];
                strncpy(temp,&arrays[i].strings[p],8);
                fprintf(fileout,"%s\n",temp);
                p+=8;
            }
        } else continue;
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

