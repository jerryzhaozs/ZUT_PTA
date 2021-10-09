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
    List a=init(),b=init(),c=init();
    int i,j,n;
    scanf("%d",&n);
    char s[4]={'h','a','b','c'};
    inserttail(a,99999);
    inserttail(b,99999);
    inserttail(c,99999);
    for(int i=n;i>=1;i--){
        inserttail(a,i);
    }
    if(n%2==1){
        s[2]='c';
        s[3]='b';
    }
    for(i=1;;i++){
        if(i%3==1){
            printf("%c -> %c\n",s[1],s[2]);
            inserttail(b,gettail(a));
            outtail(a);
            if(b->len==n+1||c->len==n+1) break;
            if(gettail(c)>gettail(a)){
                printf("%c -> %c\n",s[1],s[3]);
                inserttail(c,gettail(a));
                outtail(a);
            }else{
                printf("%c -> %c\n",s[3],s[1]);
                inserttail(a,gettail(c));
                outtail(c);
            }
        }else if(i%3==2){
            printf("%c -> %c\n",s[2],s[3]);
            inserttail(c,gettail(b));
            outtail(b);
            if(b->len==n+1||c->len==n+1) break;
            if(gettail(b)>gettail(a)){
                printf("%c -> %c\n",s[1],s[2]);
                inserttail(b,gettail(a));
                outtail(a);
            }else{
                printf("%c -> %c\n",s[2],s[1]);
                inserttail(a,gettail(b));
                outtail(b);
            }
        }else{
            printf("%c -> %c\n",s[3],s[1]);
            inserttail(a,gettail(c));
            outtail(c);
            if(b->len==n+1||c->len==n+1) break;
            if(gettail(c)>gettail(b)){
                printf("%c -> %c\n",s[2],s[3]);
                inserttail(c,gettail(b));
                outtail(b);
            }else{
                printf("%c -> %c\n",s[3],s[2]);
                inserttail(b,gettail(c));
                outtail(c);
            }
            i=0;
        }
    }
    return 0;
}