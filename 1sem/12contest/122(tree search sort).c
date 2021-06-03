#include <stdio.h>
#include <stdlib.h>
#define N 500003
int heap[N],ans[N];
typedef struct Node_s {
    int key;
    int count;
    struct Node_s *l, *r;
} Node;

int size = sizeof(Node);
void swap(int *arr, int t1, int t2) {
    int temp = arr[t1];
    arr[t1] = arr[t2];
    arr[t2] = temp;
}

void shuffle(int r, int *arr) {
    for (int i = 0; i < r; ++i) {
        int k = rand() % (i + 1);
        swap(arr, k, i);
    }
}

Node *Find(Node *init, int elem) {
    Node *t = 0;
    if (!init){
        Node *new = malloc(size);
        new->key = elem;
        new->r = new->l = 0;
        new->count = 1;
        return new;
    }
    if (elem < init->key){
        init->l=Find(init->l,elem);
    } else{
        if (elem>init->key){
            init->r=Find(init->r,elem);
        } else{
            init->count++;
        }
    }
    return init;
}


void inorder1 (Node *node,int *arr,int *k){
    if(!node)return;
    inorder1(node->l,arr,k);
    for (int i = 0; i < node->count; ++i) {
        arr[*k]=node->key;
        *(k) = *(k) + 1;
    }
    inorder1(node->r,arr,k);

}
int main() {
    srand(228);
    FILE *filein = fopen("input.bin", "rb");
    FILE *fileout = fopen("output.bin", "wb");
    int request;
    fread(&request, 1, 4, filein);
    if (!request){
        fclose(filein);
        fclose(fileout);
        return 0;
    }
    for (int i = 0; i < request; ++i) {
        fread(&heap[i], 1, 4, filein);
    }
    shuffle(request, heap);
    Node root;
    root.l=root.r=NULL;
    root.key = heap[0];
    root.count = 1;
    for (int i = 1; i < request; ++i) {
        Find(&root, heap[i]);
    }
    int index = 0;
    inorder1(&root,ans,&index);
    fwrite(ans,4,index,fileout);
    fclose(filein);
    fclose(fileout);
    return 0;
}

