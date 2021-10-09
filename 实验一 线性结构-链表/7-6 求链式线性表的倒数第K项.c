#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next,*fron;
}LNode;
typedef struct{
    int len;
    LNode *head;
    LNode *tail;
}*List,pList;
List init(){
    List L=(List)malloc(sizeof(List));
    LNode* new=(LNode*)malloc(sizeof(LNode*));
    LNode* new2=(LNode*)malloc(sizeof(LNode*));
    L->len=0;
    L->head=new;
    L->tail=new2;
    return L;
}
LNode* createNode(int data){
    LNode* newNode=(LNode*)malloc(sizeof(LNode*));
    newNode->data=data;
    newNode->next=NULL;
    newNode->fron=NULL;
    return newNode;
}
void inserttail(List L,int data){
    LNode* newNode=createNode(data);
    if(L->len==0){
        L->tail=newNode;
        L->head=newNode;
    }else{
        newNode->fron=L->tail;
        L->tail->next=newNode;
        L->tail=newNode;
    }
    L->len++;
}
int find(List L,int x){
    if(x>L->len){return -1;}
    LNode* p=L->tail;
    int cnt=0;
    while(p){
        cnt++;
        if(cnt==x) return p->data;
        p=p->fron;
    }
}
int main(){
    List list=init();
    int a;scanf("%d",&a);
    for(int i=1;i>=1;i++){
        int b;scanf("%d",&b);
        if(b<0) break;
        inserttail(list,b);
    }
    int out=find(list,a);
    if(out==-1) printf("NULL");
    else printf("%d",find(list,a));
    return 0;
}