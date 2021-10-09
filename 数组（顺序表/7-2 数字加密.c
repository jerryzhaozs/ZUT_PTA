#include<stdio.h>
#include<stdlib.h>
typedef struct array{
    int data[4];
    int last;
}*Array;

void go(Array A){
    int i=0;
    while(i<A->last){
        printf("%d",A->data[i]);
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

void getin(Array A){
    int in;
    scanf("%d",&in);
    int in1=in/1000;
    insertEnd(A,in1);
    in%=1000;

    in1=in/100;
    insertEnd(A,in1);
    in%=100;

    in1=in/10;
    insertEnd(A,in1);
    in%=10;

    insertEnd(A,in);
}
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void change(Array A){
    for(int i=0;i<4;i++){
        A->data[i]+=9;
        A->data[i]%=10;
        

        // int t=A->data[0];
        // A->data[0]=A->data[2];
        // A->data[2]=t;

        // t=A->data[1];
        // A->data[1]=A->data[3];
        // A->data[3]=t;
        // printf("\n%d%d%d%d\n",A->data[0],A->data[1],A->data[2],A->data[3]);
    }
    swap(&(A->data[0]),&(A->data[2]));
    swap(&(A->data[1]),&(A->data[3]));
}
int main(){
    Array a=init();
    getin(a);
    change(a);
    printf("The encrypted number is ");
    go(a);
    // int a=10,b=20;
    // swap(&a,&b);
    // printf("a=%d b=%d",a,b);
    return 0;
}