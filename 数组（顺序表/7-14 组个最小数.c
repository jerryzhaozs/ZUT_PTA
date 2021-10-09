#include<stdio.h>
#include<stdlib.h>
#define MAXN 100005
typedef struct Node{int *data;int len;}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(int*)malloc(MAXN*sizeof(int));
    new->len=0;
    return new;
}
void insert(List L,int e){
    L->data[L->len]=e;
    L->len++;
}
void pta(List L){
    int ok=0;
    for(int i=0;i<L->len;i++){
        if(ok==0) printf("%d",L->data[i]);
        else printf(" %d",L->data[i]);
        ok=1;
    }
}
int main(){
    List A=init();
    for(int i=0;i<10;i++){
        int a;scanf("%d",&a);
        for(int j=0;j<a;j++){
            insert(A,i);
        }
    }
    int k=0;
    for(int i=0;i<A->len;i++){
        if(A->data[i]!=0){
            k=i;
            break;
        }
    }
    if(A->len>=1){
        printf("%d",A->data[k]);
        for(int i=0;i<A->len;i++){
            if(i!=k)
                printf("%d",A->data[i]);
        }
    }
    return 0;
}