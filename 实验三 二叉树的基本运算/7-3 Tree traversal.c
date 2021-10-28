#include<stdio.h>
#include<stdlib.h>
int a[105],b[105];
typedef struct Node{
    int data;
    struct Tree *lchild,*rchild;
}*Tree,Node;

Tree create(){
    Tree p=(Node*)malloc(sizeof(Node));
    p->lchild=p->rchild=NULL;
    return p;
}

Tree find(int x, int l1, int l2){
	int i;
	Tree head = create();
	head->data = a[x];
	for (i = l1; i <= l2; i++){
		if (a[x] == b[i]){
			if(i!=l1) head->lchild=find(x-(l2-i)-1,l1,i-1);
			if(i!=l2) head->rchild=find(x-1,i+1,l2);
		}
	}
	return head;
}
void PPP(Tree p){
    if(p){
        printf(" %d",p->data);
        PPP(p->lchild);
        PPP(p->rchild);
    }
}
void main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    Tree head=find(n-1,0,n-1);
    Tree set[45];
    for(int i=0;i<=44;i++){
        set[i]=create();
    }
    int in=-1,out=0,ok=0;
    set[++in]=head;
    while(out!=in+1){
        Tree now=set[out];
        out++;
        if(ok==1) printf(" ");
        printf("%d",now->data);
        ok=1;
        if(now->lchild!=NULL){
            set[++in]=now->lchild;
        }
        if(now->rchild!=NULL){
            set[++in]=now->rchild;
        }
    }
    return 0;
}