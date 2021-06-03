#include <stdio.h>
#include <stdlib.h>
#define N 100001

int charfindor(char ref,const char *src){
    int cnt=0,num=0;
    char current=src[num];
    while (current){
        if (current==ref)cnt++;
        num++;
        current=src[num];
    }
    return cnt;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int requests=0,id=0;
    short oper=0;
    char *pointers [N]={};
    scanf("%d",&requests);
    for (int i = 0; i < requests; ++i) {
        int length,id1=0,intsymb;
        scanf("%hd",&oper);
        switch (oper) {
            case 0:
                scanf("%d",&length);
                pointers[id]=malloc(length+1);
                scanf("%s",pointers[id]);
                id++;
                break;
            case 1:
                scanf("%d",&id1);
                free(pointers[id1]);
                id1=0;
                break;
            case 2:
                scanf("%d",&id1);
                printf("%s\n",pointers[id1]);
                id1=0;
                break;
            case 3:
                scanf("%d",&id1);
                intsymb=getchar();
                if (intsymb<33 || intsymb>126){
                    intsymb=getchar();
                }
                printf("%d\n",charfindor((char)intsymb,pointers[id1]));
                break;
            default:
                exit(1);
        }
    }
    for (int i = 0; i < requests; ++i) {
        free(pointers[requests]);
    }
    return 0;
}

