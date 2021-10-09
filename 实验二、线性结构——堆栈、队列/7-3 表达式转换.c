#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    char data;
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
LNode* createNode(char c){
    LNode* newNode=(LNode*)malloc(sizeof(LNode*));
    newNode->data=c;
    newNode->next=NULL;
    newNode->front=NULL;
    return newNode;
}
void inserttail(List L,char c){
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
char gettail(List L){
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
    List L=init();
    char in[30];
    scanf("%s",&in);
    int ok=0;
    int is=1;
    for(int i=0;in[i];i++){
        if(in[i]=='('){
            inserttail(L,in[i]);
            is=1;
            continue;
        }
        if(in[i]==')'){
            while(2>1){
                if(gettail(L)=='('){
                    outtail(L);
                    break;
                }
                if(ok==1) printf(" ");
                ok=1;
                printf("%c",gettail(L));
                outtail(L);
            }
            is=0;
            continue;
        }
        if(is==1){/////////////////////////////////////////是数字
            if(ok==1) printf(" ");
            ok=1;
            if(in[i]=='-'){
                printf("-");
                i++;
                while((in[i]>='0'&&in[i]<='9')||in[i]=='.'){
                    printf("%c",in[i]);
                    i++;
                }
                i--;
                is=0;
                continue;
            }else if(in[i]=='+'){
                // printf("-");
                i++;
                while((in[i]>='0'&&in[i]<='9')||in[i]=='.'){
                    printf("%c",in[i]);
                    i++;
                }
                i--;
                is=0;
                continue;
            }else{
                while((in[i]>='0'&&in[i]<='9')||in[i]=='.'){
                    printf("%c",in[i]);
                    i++;
                }
                i--;
                is=0;
                continue;
            }
        }
        if(is==0){
            if(in[i]=='+'||in[i]=='-'){
                while(3>2){
                    if(L->len==0) break;
                    if(gettail(L)!='*'&&gettail(L)!='/') break;
                    if(gettail(L)=='*'||gettail(L)=='/'){
                        if(ok==1) printf(" ");
                        ok=1;
                        printf("%c",gettail(L));
                        outtail(L);
                    }
                }
                if(gettail(L)=='-'||gettail(L)=='+'){
                    if(ok==1) printf(" ");
                    ok=1;
                    printf("%c",gettail(L));
                    outtail(L);
                }
                inserttail(L,in[i]);
            }
            if(in[i]=='*'||in[i]=='/'){
                
                if(gettail(L)=='*'||gettail(L)=='/'){
                    if(ok==1) printf(" ");
                    ok=1;
                    printf("%c",gettail(L));
                    outtail(L);
                }
                inserttail(L,in[i]);
            }
            is=1;
            continue;
        }
    }
    while(L->len>=1){
        if(ok==1) printf(" ");
        ok=1;
        printf("%c",gettail(L));
        outtail(L);
    }
    return 0;
}