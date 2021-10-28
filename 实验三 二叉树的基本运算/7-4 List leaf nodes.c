#include<stdio.h>
#include<stdlib.h>

char s1[1005];
char s2[1005];
typedef struct Node{
    int data;
    struct Node *lchild,*rchild;
}Node,*Tree;
Tree CreateNode(){
    Tree p = (Node *)malloc(sizeof(Node));
    p->lchild=p->rchild=NULL;
    return p;
}
int is[15]={0};
int main(){
    int n;
    char ch;
    scanf("%d",&n);
    scanf("%c",&ch);
    Tree set[15];
    for(int i=0;i<=14;i++){
        set[i]=CreateNode();
    }
    for(int i=0;i<n;i++){
        set[i]->data=i;
        char str[5];
        gets(str);
        char l=str[0];
        char r=str[2];
        

        if(l!='-'){
            is[(int)l-48]=1;
            set[i]->lchild=set[(int)l-48];
        }
        if(r!='-'){
            is[(int)r-48]=1;
            set[i]->rchild=set[(int)r-48];
        }
    }
    int sta=-1;
    for(int i=0;i<n;i++){
        if(is[i]==0){
            sta=i;
            break;
        }
    }
    Tree io[105];
    int in=-1,out=0;
    io[++in]=set[sta];
    int ok=0;

    while(out!=in+1){
        Tree now=io[out];
        out++;
        if(now->lchild==NULL&&now->rchild==NULL){
            if(ok==1){printf(" ");}
            printf("%d",now->data);
            ok=1;
        }
        if(now->lchild!=NULL){
            io[++in]=now->lchild;
        }
        if(now->rchild!=NULL){
            io[++in]=now->rchild;
        }
    }
    return 0;
}