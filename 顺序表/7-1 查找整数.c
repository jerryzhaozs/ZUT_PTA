#include<stdio.h>
#include<stdlib.h>
typedef struct array{
    int data[105];
    int last;
}*Array;

void go(Array A){
    int i=0;
    while(i<A->last){
        printf("%d ",A->data[i]);
        i++;
    }
}
Array init(){
    Array newArray=(Array)malloc(sizeof(Array));
    newArray->last=0;
    return newArray;
}

void insertEnd(Array A,int d){
    A->data[A->last]=d;
    A->last++;
}
int find(Array A,int k){
    for(int i=0;i<A->last;i++){
        if(k==A->data[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    Array a1=init();
    
    int len,at;
    scanf("%d%d",&len,&at);
    for(int i=1;i<=len;i++){
        int in;scanf("%d",&in);
        insertEnd(a1,in);
    }

    int ans=find(a1,at);
    if(ans==-1) printf("Not Found");
    else printf("%d",ans);
    return 0;
}