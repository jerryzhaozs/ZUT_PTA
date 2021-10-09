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
void solve(int MAXX){
    List L=init();
    char str[1024];
    scanf("%[^\n]",&str);
    getchar();
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='S'){
            if(L->len==MAXX){
                printf("NO");
                return;
            }
            inserttail(L,1);
        }else if(str[i]=='X'){
            if(L->len==0){
                printf("NO");
                return;
            }
            outtail(L);
        }
    }
    if(L->len==0)
        printf("YES");
    else printf("NO");
}
int main(){
    int T,MAXX;
    scanf("%d%d",&T,&MAXX);
    getchar();
    int ok=0;
    while(T--){
        if(ok==1) printf("\n");
        solve(MAXX);
        if(ok==0) ok=1;
    }
    return 0;
}