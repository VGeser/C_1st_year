#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[]) {
    if (argc==1){
        fprintf(stderr,"%s","No parameters specified.");
        return 13;
    }
    unsigned char isMod=0;
    long long a,b,c=0;
    int i=1;
    if (!strcmp(argv[1],"-m")){
        isMod=1;
        c=atoi(argv[2]);
        i=3;
    } else if (argc>4 && !strcmp(argv[4],"-m")){
        isMod=1;
        c=atoi(argv[5]);
    }
    a=atoi(argv[i+1]);
    b=atoi(argv[i+2]);
    if (!isMod){
        if (!strcmp(argv[1],"sub")){
            fprintf(stdout,"%lld",a-b);
        }
        if (!strcmp(argv[1],"add")){
            fprintf(stdout,"%lld",a+b);
        }
        if (!strcmp(argv[1],"mul")){
            fprintf(stdout,"%lld",a*b);
        }
    } else {
        if (!strcmp(argv[i],"sub")){
            fprintf(stdout,"%lld",((a%c)-(b%c)+c)%c);
        }
        if (!strcmp(argv[i],"add")){
            long long ans=((a%c)+(b%c))%c;
            fprintf(stdout,"%lld",ans>=0?ans:c+ans);
        }
        if (!strcmp(argv[i],"mul")){
            long long ans =((a%c)*(b%c))%c;
            fprintf(stdout,"%lld",ans>=0?ans:c+ans);
        }
    }
    return 0;
}

