#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
int main(){
    List L=init();
    for(int i=0;i<1010;i++){
        insert(L,0);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int o;scanf("%d",&o);
            L->data[o]++;
        }
    }
    int maxx=0,max_;
    for(int i=0;i<1001;i++){
        if(maxx<=L->data[i]){
            max_=i;
            maxx=L->data[i];
        }
    }
    printf("%d %d",max_,maxx);
    return 0;
}