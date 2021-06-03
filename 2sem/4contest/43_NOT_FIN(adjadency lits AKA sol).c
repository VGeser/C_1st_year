//NOT ACCEPTED!!!
//NOT FINISHED!!!
//NOT WORKING!!!
#include <stdlib.h>
#include "sol.h"

typedef struct List_s {
    Edge value;
    struct List_s *next;
} List;
typedef struct Vert_s {
    int kol;
    List **edges;
} Vert;
int num = 0;
Vert *vertices = 0;
void newEdge(int index,Edge *edge){
    int lkol=vertices[index].kol;
    vertices[index].kol++;
    List *ptr = calloc(1,sizeof(List));
    vertices[index].edges[lkol] = ptr;
    ptr->value=*(edge);
    //ptr->next=0;
    /*if(lkol){
        vertices[index].edges[lkol-1]->next=ptr;
    }*/
    //vertices[index].last=lkol;
}

void init() {
    num = getVerticesCount();
    //list = malloc(sizeof(List));
    vertices = calloc(num, sizeof(Vert));
    for (int i = 0; i < num; ++i) {
        vertices[i].edges = malloc(sizeof(List));
        //vertices[i].last = malloc(sizeof(Edge));
        //vertices[i].last = 0;
    }
    Edge *edge = calloc(1, sizeof(Edge));
    while (readEdge(edge)) {
        newEdge(edge->from,edge);
        int newfrom=edge->to;
        int newto=edge->from;
        edge->from=newfrom;
        edge->to=newto;
        newEdge(edge->from,edge);
    }
}

int getEdgesCount(int iVertex) {
    return vertices[iVertex].kol;
}

Edge getIncidentEdge(int iVertex, int iIndex) {
    return vertices[iVertex].edges[iIndex]->value;
}

