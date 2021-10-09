#include<stdio.h>
#include<stdlib.h>
typedef struct Array{
    int data[105];
    int last;
}*Array;

Array init(){
    Array newArray=(Array)malloc(sizeof(Array));
    newArray->last=0;
    return newArray;
}

void insert(Array a,int d){
    a->data[a->last]=d;
    a->last++;
}
void pta(Array A){
    for(int i=0;i<A->last;i++){
        printf("%d ",A->data[i]);
    }
}
int main(){
    int len;
    int A[15]={0};
    int B[15]={0};
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        int in;scanf("%d",&A[i]);
        A[i-1]=A[i]-A[i-1];
    }
    int cnt=0;
    if(len==2){
        printf("%d\n",A[1]);
    }else if(len==3){
        printf("%d %d\n",A[1],A[2]);
    }else if(len==4){
        printf("%d %d %d\n",A[1],A[2],A[3]);
    }else if(len==5){
        printf("%d %d %d\n%d\n",A[1],A[2],A[3],A[4]);
    }else if(len==6){
        printf("%d %d %d\n%d %d\n",A[1],A[2],A[3],A[4],A[5]);
    }else if(len==7){
        printf("%d %d %d\n%d %d %d\n",A[1],A[2],A[3],A[4],A[5],A[6]);
    }else if(len==8){
        printf("%d %d %d\n%d %d %d\n%d\n",A[1],A[2],A[3],A[4],A[5],A[6],A[7]);
    }else if(len==9){
        printf("%d %d %d\n%d %d %d\n%d %d\n",A[1],A[2],A[3],A[4],A[5],A[6],A[7],A[8]);
    }else if(len==10){
        printf("%d %d %d\n%d %d %d\n%d %d %d\n",A[1],A[2],A[3],A[4],A[5],A[6],A[7],A[8],A[9]);
    }
    // int cnt=0;
    // for(int i=0;i<B->last;i++){
    //     cnt++;
    //     if(cnt==4){
    //         cnt=0;
    //         printf("\n");
    //     }
    //     printf("%d ",B->data[i]);
    // }
    return 0;
}