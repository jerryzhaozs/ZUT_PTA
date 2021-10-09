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
void pta(List L){
    int ok=0;
    for(int i=0;i<L->len;i++){
        if(ok==0) printf("%d",L->data[i]);
        else printf(" %d",L->data[i]);
        ok=1;
    }
}
int find(List L,int e){
    for(int i=0;i<L->len;i++){
        if(L->data[i]==e){
            return 1;
        }
    }
    return 0;
}
List out(List L){
    List new=init();
    for(int i=0;i<L->len;i++){
        if(find(new,L->data[i])) continue;
        insert(new,L->data[i]);
    }
    return new;
}
int main(){
    List A=init(),B=init(),C=init();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int e;scanf("%d",&e);
        insert(A,e);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int e;scanf("%d",&e);
        insert(B,e);
    }
    A=out(A);
    B=out(B);
    for(int i=0;i<A->len;i++){
        int ok=0;
        for(int j=0;j<B->len;j++){
            if(A->data[i]==B->data[j]){
                ok=1;
                break;
            }
        }
        if(ok==0){
            insert(C,A->data[i]);
        }
    }
    
    for(int i=0;i<B->len;i++){
        int ok=0;
        for(int j=0;j<A->len;j++){
            if(A->data[j]==B->data[i]){
                ok=1;
                break;
            }
        }
        if(ok==0){
            insert(C,B->data[i]);
        }
    }
    // pta(A);printf("\n");
    // pta(B);printf("\n");
    pta(C);
    return 0;
}