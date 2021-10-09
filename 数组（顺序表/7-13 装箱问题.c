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
int goin(List L,int e,List G){
    int i=0,ok=0;
    for(int i=0;i<L->len;i++){
        if(L->data[i]+e<=100){
            L->data[i]+=e;
            insert(G,i);
            return i;
        }
    }
    insert(L,e);
    insert(G,L->len-1);
    return L->len-1;
}
int main(){
    List A=init(),B=init(),C=init();
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        insert(A,a);
    }
    int ans=0;
    for(int i=0;i<A->len;i++){
        int k=goin(B,A->data[i],C);
        if(ans<k){ans=k;}
    }
    for(int i=0;i<A->len;i++){
        printf("%d %d\n",A->data[i],C->data[i]+1);
    }
    printf("%d",ans+1);
    return 0;
}