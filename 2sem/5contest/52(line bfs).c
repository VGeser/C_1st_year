#include <stdio.h>
#include <stdlib.h>
#define N 200005
typedef struct Adj_s{
    int value;
    struct Adj_s * next;
}Adj;
Adj lists[N];
int size= sizeof(Adj);
typedef struct Queue_s{
    Adj *last,*first;
}Queue;
void CreateQueue(Queue *q){
    q->first= calloc(1,size);
    q->first->value=1;
    q->first->next=0;
    q->last=q->first;
}
void enQueue(Queue *q, int v){
    q->last->next= calloc(1,size);
    q->last->next->value=v;
    q->last->next->next=0;
    q->last=q->last->next;
}
int deQueue(Queue *q){
    int v=q->first->value;
    Adj *p=q->first;
    q->first=q->first->next;
    free(p);
    return v;
}
void BFS(Queue* queue,char *mark,int* dist){
    while (queue->first){
        int cur = queue->first->value;
        Adj *p=&lists[cur];
        while (p){
            if(!mark[p->value] && p->value){
                mark[p->value]='m';
                dist[p->value]=dist[cur]+1;
                enQueue(queue,p->value);
            }
            p=p->next;
        }
        deQueue(queue);
    }
}
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int vert,edge;
    fscanf(filein,"%d%d",&vert,&edge);
    vert++;
    char *mark= calloc(vert,1);
    mark[1]='m';//marked
    int *dist= calloc(vert, sizeof(int));
    Queue *queue = calloc(1, sizeof(Queue));
    CreateQueue(queue);
    for (int i = 0; i < edge; ++i) {
        int from,to;
        fscanf(filein,"%d%d",&from,&to);
        if(!(lists[from].value)){
            lists[from].value=to;
            lists[from].next=0;
        } else {
            Adj *p=&lists[from];
            while (p->next){
                p=p->next;
            }
            p->next= calloc(1, size);
            p->next->value=to;
        }
    }
    BFS(queue,mark,dist);
    fprintf(fileout,"%d\n",0);
    for (int i = 2; i < vert; ++i) {
        if(dist[i]){
            fprintf(fileout,"%d\n",dist[i]);
        } else {
            fprintf(fileout,"%d\n",-1);
        }
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

