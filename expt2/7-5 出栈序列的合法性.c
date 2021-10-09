#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *front;
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
LNode* createNode(int c){
    LNode* newNode=(LNode*)malloc(sizeof(LNode*));
    newNode->data=c;
    newNode->next=NULL;
    newNode->front=NULL;
    return newNode;
}
void inserttail(List L,int c){
    LNode* newNode=createNode(c);
    if(L->len==0){
        L->tail=newNode;
        L->head=newNode;
    }else{
        newNode->front=L->tail;
        L->tail->next=newNode;
        L->tail=newNode;
    }
    L->len++;
}
int gettail(List L){
    if(L->len==0) return 'z';
    return L->tail->data;
}
void outtail(List L){
    if(L->len==0){return;}
    if(L->len==1){
        L->head=NULL;
        L->tail=NULL;
        L->len=0;
    }else{
        LNode* p=L->tail->front;
        L->tail=p;
        L->len--;
        p->next=NULL;
    }
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int a[m+10];
        List L=init();
        int flag=0;
        inserttail(L,flag);
        for(int j=0;j<m;j++){
            scanf("%d",&a[j]);
        }
        int pos=0;
        for(int j=0;j<m;j++){
            if(gettail(L)>a[j]){
                printf("NO\n");
                break;
            }
            while(gettail(L)!=a[j]){
                flag++;
                inserttail(L,flag);
            }
            if(L->len>n+1){
                printf("NO\n");
                break;
            }
            else{
                outtail(L);
            }
        }
        if(gettail(L)==0){
            printf("YES\n");
        }
    }
    return 0;
}