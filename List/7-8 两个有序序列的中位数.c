#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
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
    return newNode;
}
void inserttail(List L,int data){
    LNode* newNode=createNode(data);
    if(L->len==0){
        L->tail=newNode;
        L->head=newNode;
    }else{
        L->tail->next=newNode;
        L->tail=newNode;
    }
    L->len++;
}
void insert(List L,int data){
    LNode* newNode=createNode(data);
    LNode* p=L->head;
    if(data<p->data){
        newNode->next=p;
        L->head=newNode;
        return;
    }
    while(p->next){
        if(data<p->next->data){
            newNode->next=p->next;
            p->next=newNode;
            return;
        }
        p=p->next;
    }
    L->tail=newNode;
}
int main(){
    List l1=init();
    List l2=init();
    int a;scanf("%d",&a);
    for(int i=1;i<=a;i++){
        int data;scanf("%d",&data);
        inserttail(l1,data);
    }
    for(int i=1;i<=a;i++){
        int data;scanf("%d",&data);
        inserttail(l2,data);
    }
    LNode* p1=l1->head;
    LNode* p2=l2->head;
    int cnt=0;
    int ans=0;
    while(p1&&p2){
        cnt++;
        if(p1->data<p2->data){
            if(cnt==a){
                ans+=p1->data;
                break;
            }
            p1=p1->next;
        }else{
            if(cnt==a){
                ans+=p2->data;
                break;
            }
            p2=p2->next;
        }
    }
    printf("%d",ans);
    return 0;
}