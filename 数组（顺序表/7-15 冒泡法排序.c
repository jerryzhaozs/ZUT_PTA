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
void change(List L){
    for(int i=0;i<L->len-1;i++){
        if(L->data[i]>L->data[i+1]){
            // printf("%d!\n",i);
            int t=L->data[i];
            L->data[i]=L->data[i+1];
            L->data[i+1]=t;
        }
    }
}
int main(){
    List A=init();
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int e;scanf("%d",&e);
        insert(A,e);
    }
    for(int i=0;i<k;i++){
        change(A);
    }
    pta(A);
    return 0;
}