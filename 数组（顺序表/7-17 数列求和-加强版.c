#include<stdio.h>
#include<stdlib.h>

#define MAXN 200100
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
void pta(List L){
    int ok=0;
    for(int i=L->len-1;i>=0;i--){
        if(L->data[i]==-1){
            continue;
        }
        if(ok==0) printf("%d",L->data[i]);
        else printf("%d",L->data[i]);
        ok=1;
    }
}
int main(){
    List L=init();
    List add=init();
    for(int i=0;i<200010;i++){
        insert(L,-1);
        insert(add,0);
    }
    int n,k;
    scanf("%d%d",&k,&n);
    if(n==0){printf("0");return 0;}
    for(int i=0;i<n;i++){
        L->data[i]=k*(n-i)+add->data[i];
        // printf("%d !\n",L->data[i]);
        if(L->data[i]>=10){
            add->data[i+1]+=L->data[i]/10;
            L->data[i]%=10;
        }
    }
    if(add->data[n]!=0){
        L->data[n]=add->data[n];
    }
    pta(L);
    return 0;
}