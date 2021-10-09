#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int adr;
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
LNode* createNode(int adr,int data){
    LNode* newNode=(LNode*)malloc(sizeof(LNode*));
    newNode->data=data;
    newNode->adr=adr;
    newNode->next=NULL;
    newNode->fron=NULL;
    return newNode;
}
void inserttail(List L,int adr,int data){
    LNode* newNode=createNode(adr,data);
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
typedef struct node{
    int adr;
    int data;
    int next;
}node;
void gotail(List L){
    int cnt=0;
    LNode* p1=L->head;
    LNode* p2=L->tail;
    int ok=0;
    while(cnt<L->len){
        cnt++;
        node e;
        if(cnt%2==1){
            e.adr=p2->adr;
            e.data=p2->data;
            p2=p2->fron;
        }else{
            e.adr=p1->adr;
            e.data=p1->data;
            p1=p1->next;
        }
        if(ok==0) printf("%05d %d",e.adr,e.data);
        else printf(" %05d\n%05d %d",e.adr,e.adr,e.data);
        ok=1;
    }
	if(ok==0) return;
    printf(" -1");
}
void pta(List L){
    LNode* p=L->head;
    while(p){
        printf("\n%d %d %d",p->adr,p->data,p->next);
        p=p->next;
    }
}
node a[100005];
int main(){
    List l=init();
    int fa,n;
    scanf("%d%d",&fa,&n);
    int adr,data,next;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&adr,&data,&next);
        a[adr].adr=adr;
        a[adr].data=data;
        a[adr].next=next;
    }
    int to=fa;
    int whi=10;
    while(whi==10){
        inserttail(l,a[to].adr,a[to].data);
        to=a[to].next;
        if(to==-1) break;
    }
    gotail(l);
}