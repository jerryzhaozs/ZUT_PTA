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
void back(List L){
    char c=gettail(L);
    if(c=='a') printf("NO\n/*-?");
    if(c=='(') printf("NO\n(-?");
    if(c=='[') printf("NO\n[-?");
    if(c=='{') printf("NO\n{-?");
}dw
char transChar(char a){
    if(a=='}') return '{';
    if(a==']') return '[';
    if(a==')') return '(';
}
int main(){
    List L=init();
    while(1==1){
        char str[1024];
        scanf("%[^\n]",&str);
        getchar();
        if(str[0]=='.'&&str[1]=='\0') break;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='/'&&str[i+1]=='*'){
                inserttail(L,'a');
                i++;
                continue;
            }
            if(str[i]=='(') inserttail(L,'(');
            if(str[i]=='[') inserttail(L,'[');
            if(str[i]=='{') inserttail(L,'{');

            if(str[i]=='*'&&str[i+1]=='/'){
                char fi=gettail(L);
                if(fi=='a'){
                    outtail(L);
                    i++;
                    continue;
                }else{
                    if(L->len==0) printf("NO\n?-*/");
                    else back(L);
                    return 0;
                }
            }else if(str[i]==')'||str[i]==']'||str[i]=='}'){
                char fi=gettail(L);
                if(fi==transChar(str[i])) outtail(L);
                else{
                    if(L->len==0) printf("NO\n?-%c",str[i]);
                    else back(L);
                    return 0;
                }
            }
        }
    }
    if(L->len!=0){
        printf("NO\n");
        char la=L->tail->data;
        if(la=='a') printf("/*-?");
        else if(la=='(') printf("(-?");
        else if(la=='[') printf("[-?");
        else if(la=='{') printf("{-?");
        return 0;
    }
    printf("YES");
    return 0;
}