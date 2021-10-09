#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    double *data;
    int len;
}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(double*)malloc(10005*sizeof(double));
    new->len=0;
    return new;
}
void insert(List L,double e){
    L->data[L->len]=e;
    L->len++;
}
int main(){
    List L=init();
    int n;
    double sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in;scanf("%d",&in);
        insert(L,in);
        sum+=in;
    }
    double avg=sum/n;
    double summ=0;
    for(int i=0;i<n;i++){
        summ+=(L->data[i]-avg)*(L->data[i]-avg);
    }
    summ/=n;
    printf("%.5lf",sqrt(summ));
    return 0;
}
