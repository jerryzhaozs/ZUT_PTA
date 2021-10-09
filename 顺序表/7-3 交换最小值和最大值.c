#include<stdio.h>
#include<stdlib.h>
typedef struct array{
    int data[105];
    int last;
}*Array;

Array init(){
    Array newArray=(Array)malloc(sizeof(Array));
    newArray->last=0;
    return newArray;
}

void insertEnd(Array A,int d){
    A->data[A->last]=d;
    A->last++;
}
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void pta(Array A){
    for(int i=0;i<A->last;i++){
        printf("%d ",A->data[i]);
    }
}
int main(){
    Array a=init();
    int len;
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        int in;scanf("%d",&in);
        insertEnd(a,in);
    }
    int minn=0x7fffffff,min_,maxx=-0x7fffffff,max_;
    for(int i=0;i<a->last;i++){
        if(minn>a->data[i]){
            min_=i;
            minn=a->data[i];
        }
        // if(maxx<a->data[i]){
        //     max_=i;
        //     maxx=a->data[i];
        // }
    }
    swap(&a->data[min_],&a->data[0]);
    for(int i=0;i<a->last;i++){
        // if(minn>a->data[i]){
        //     min_=i;
        //     minn=a->data[i];
        // }
        if(maxx<a->data[i]){
            max_=i;
            maxx=a->data[i];
        }
    }
    swap(&a->data[max_],&a->data[a->last-1]);
    pta(a);
    return 0;
}