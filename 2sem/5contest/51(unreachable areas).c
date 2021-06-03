#pragma comment (linker,"/STACK:50000000")
#include <stdio.h>
#include <stdlib.h>
char *matr=0;
void DFS(int cur,int d){
    matr[cur]='p';//path
    if(((cur+d)< d*d) && matr[cur+d]=='b'){//down
        DFS(cur+d,d);
    } if((cur+1)%d!=0 && matr[cur+1]=='b'){//right
        DFS(cur+1,d);
    }if (cur%d!=0 && matr[cur-1]=='b'){//left
        DFS(cur-1,d);
    }if(cur>=d && matr[cur-d]=='b'){//up
        DFS(cur-d,d);
    }
}
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int dim;
    fscanf(filein,"%d",&dim);
    matr = malloc(dim*dim);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            char cur=0;
            fscanf(filein,"%c",&cur);
            if(cur==10){
                fscanf(filein,"%c",&cur);
            }
            if(cur=='*'){
                matr[i*dim+j]='w';//wall
            } else {
                matr[i*dim+j]='b';//blank
            }
        }
    }
    int enter;
    for (int i = 0; i < dim; ++i) {
        if(matr[i]=='b')
            enter=i;
    }
    DFS(enter,dim);
    int unreach=0;
    for (int i = 0; i < dim*dim; ++i) {
        if(matr[i]=='b'){
            unreach++;
            DFS(i,dim);
        }
    }
    fprintf(fileout,"%d",unreach);
    fclose(filein);
    fclose(fileout);
    free(matr);
    return 0;
}

