#include <stdio.h>
#include <stdlib.h>

#define N 1000002

typedef struct List_s {
    char value[8];
    struct List_s *pointer;
    struct List_s *next;
} List;
int size = sizeof(List);
List lists[N] = {0};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int request = 0, max = 0;
    scanf("%d", &request);
    for (int i = 0; i < request; ++i) {
        int key = 0;
        scanf("%d", &key);
        max = (key > max) ? key : max;
        if (lists[key].value[0]==0) {
            scanf("%s",lists[key].value);
        } else {
            List *p;
            if (!lists[key].pointer){
                p=&lists[key];
            } else{
                p=lists[key].next;
            }
            /*while (p && p->pointer){
                p=p->pointer;
            }*/
            p->pointer=malloc(size);
            lists[key].next=p->pointer;
            scanf("%s",p->pointer->value);
            p->pointer->pointer=NULL;
        }
    }
    for (int i = 0; i <= max; ++i) {
        if (lists[i].value[0]==0)continue;
        List *p=&lists[i];
        if (!p->pointer && p->value[0]){
            printf("%d ",i);
            printf("%s\n",p->value);
            continue;
        }
        while (p){
            printf("%d ",i);
            printf("%s\n",p->value);
            p=p->pointer;
        }
    }
    return 0;
}

