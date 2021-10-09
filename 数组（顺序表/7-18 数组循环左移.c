#include<stdio.h>
#include<stdlib.h>
#define MAXN 1005
typedef struct Node{int *data;int len;}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(int*)malloc(MAXN*sizeof(List));
    new->len=0;
    return new;
}
void insert(List L,int e){
    L->data[L->len]=e;
    L->len++;
}
void move(List L){
    int temp=L->data[0];
    for(int i=0;i<L->len-1;i++){
        L->data[i]=L->data[i+1];
    }
    L->data[L->len-1]=temp;
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
    List L=init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int e;scanf("%d",&e);
        insert(L,e);
    }
    for(int i=0;i<m;i++){
        move(L);
    }
    pta(L);
    return 0;
}