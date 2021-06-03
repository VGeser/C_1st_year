#include <stdio.h>
int main(){
    FILE *file = fopen("input.bin","rb");
    long A, B;
    fread(&A, 1, 4, file);
    fread(&B, 1, 4, file);
    fclose(file);
    file= fopen("output.bin","wb");
    long long C;
    C=(long long)A+B;
    if (C%2 && C<0){
        C=(C/2)-1;
    } else
        C/=2;
    A= (long) C;
    fwrite(&A,4,1,file);
    fclose(file);
    return 0;
}
