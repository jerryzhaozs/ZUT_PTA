#include<stdio.h>
#include<stdlib.h>
#define MAXN 10005
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
void change(List a,List b){
    for(int i=a->len-1;i>=0;i--){
        insert(b,a->data[i]);
    }
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
    List A=init(),B=init();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int e;scanf("%d",&e);
        insert(A,e);
    }
    change(A,B);
    pta(B);
    return 0;
}