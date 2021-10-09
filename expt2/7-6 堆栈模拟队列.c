#include<stdio.h>
#include<stdlib.h>
#define MAXN 1005
typedef struct Node{int *data;}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(int*)malloc(MAXN*sizeof(int));
    return new;
}
int main(){
    List stack2=init();
    List stack1=init();
    int top1=-1,top2=-1;
    char c;
    int temp;
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    if( n1>n2 ){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    while(1){
        scanf("%c",&c);
        if( c=='T') break;
        else if( c=='A'){
            scanf("%d",&temp);
            if( top1==n1-1 && top2!=-1){
                printf("ERROR:Full\n");
            }else if( top1==n1-1){
                while( top1>-1 ){
                    stack2->data[++top2] = stack1->data[top1--];
                }stack1->data[++top1] = temp;
            }else stack1->data[++top1] = temp;
        }else if( c=='D'){
            if( top2!=-1)
                printf("%d\n",stack2->data[top2--]);
            else if( top2==-1 && top1!=-1){
                while(top1>-1){
                    stack2->data[++top2] = stack1->data[top1--];
                }printf("%d\n",stack2->data[top2--]);
            }else printf("ERROR:Empty");
        }
    }
    return 0;
}