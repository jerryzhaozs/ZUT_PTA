#include<stdio.h>
#include<stdlib.h>
#define MAXN 10005
typedef struct person{int name;int p;int t;}person;
typedef struct Node{int *data;int len;int s_;int e_;}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(int*)malloc(MAXN*sizeof(int));
    new->len=0;
    new->e_=0;
    new->s_=0;
    return new;
}
int main(){
    List A=init();
    List B=init();
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;scanf("%d",&a);
        if(a%2==1){
            A->data[A->e_++]=a;
        }else{
            B->data[B->e_++]=a;
        }
    }
    int ok=0;
    while(A->e_!=A->s_||B->s_!=B->e_){
        if(A->e_!=A->s_){
            if(ok==1) printf(" "); ok=1;
            printf("%d",A->data[A->s_++]);
        }
        if(A->e_!=A->s_){
            if(ok==1) printf(" "); ok=1;
            printf("%d",A->data[A->s_++]);
        }
        if(B->e_!=B->s_){
            if(ok==1) printf(" "); ok=1;
            printf("%d",B->data[B->s_++]);
        }
    }
    return 0;
}