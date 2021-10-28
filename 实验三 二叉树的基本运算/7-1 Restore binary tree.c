#include<stdio.h>
#include<stdlib.h>
char s1[1005];
char s2[1005];
typedef struct Node{
    char data;
    struct Node *lchild,*rchild;
}Node,*Tree;
Tree CreateNode(){
    Tree p = (Node *)malloc(sizeof(Node));
    p->lchild=p->rchild=NULL;
    return p;
}
Tree RestoreTree(int x,int l1,int l2){
    Tree head=CreateNode();
    head->data=s1[x];
    for(int i=l1;i<=l2;i++){
        if(s2[i]==s1[x]){
            if(i!=l1) head->lchild=RestoreTree(x+1,l1,i-1);
            if(i!=l2) head->rchild=RestoreTree(x+i-l1+1,i+1,l2);
            break;
        }
    }
    return head;
}
int MAX(int a,int b){return a>b?a:b;}
int Theight(Tree tree){
    if(tree==NULL) return 0;
    return MAX(Theight(tree->lchild),Theight(tree->rchild))+1;
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s%s",&s1,&s2);
    Tree head=RestoreTree(0,0,n-1);
    printf("%d",Theight(head));
    return 0;
}