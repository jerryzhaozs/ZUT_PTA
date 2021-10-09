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
void change(List L){
    int n=L->len;
    int i=0,cnt=0;
    while(n>1){
        if(L->data[i]==0){
            cnt++;
        }
        if(cnt==3){
            L->data[i]=1;
            n--;
            cnt=0;
        }
        i++;
        i%=L->len;
    }
}
int main(){
    List L=init();
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        insert(L,0);
    }
    change(L);
    int k=0;
    for(int i=0;i<L->len;i++){
        if(L->data[i]==0){
            k=i;
            break;
        }
    }
    printf("%d",k+1);
    return 0;
}