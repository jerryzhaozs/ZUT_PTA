#include<stdio.h>
#include<stdlib.h>
typedef struct BiThrNode{
    int data;
    struct BiThrNode *lchild,*rchild;      /*左右孩子指针*/
    int LTag,RTag;               /*左右标志*/
}BiThrNode,*BiThrTree;
BiThrTree pre=NULL;
BiThrTree createTree(){
    BiThrTree newNode=(BiThrNode *)malloc(sizeof(BiThrNode));
    scanf("%d",&newNode->data);
    newNode->LTag=-1;
    newNode->RTag=-1;
    if(newNode->data==-1){
        return NULL;
    }
    newNode->lchild=createTree();
    newNode->rchild=createTree();
    return newNode;
}
void pta(BiThrTree now){
    if(now!=NULL){
        printf("编号为：%d ",now->data);
        if(now->lchild==NULL) printf("前驱?%d ",now->LTag);
        else printf("前驱?%d : %d ",now->LTag,now->lchild->data);
        if(now->rchild==NULL) printf("后继?%d \n",now->RTag);
        else printf("后继?%d : %d\n",now->RTag,now->rchild->data);
        if(now->LTag==0||now->LTag==-1)
        pta(now->lchild);
        if(now->RTag==0||now->RTag==-1)
        pta(now->rchild);
    }
}
void InThreading(BiThrTree p){
    if(p==NULL) return;
    InThreading(p->lchild);
    printf("-> %d pre=",p->data);
    if(pre==NULL) printf("NULL\n");
    else printf("%d\n",pre->data);
    if(!p->lchild){
        p->LTag=1;
        p->lchild=pre;
    }else{
        p->LTag=0;
    }
    if(pre!=NULL){
        if(!pre->rchild){
            pre->RTag=1;
            pre->rchild=p;
        }else{
            pre->RTag=0;
        }
    }
    pre=p;
    InThreading(p->rchild);
}
BiThrTree get(BiThrTree p){
    while(p->lchild!=NULL){
        p=p->lchild;
    }
    return p;
}
void InOrderTraverse_Thr(BiThrTree p){
    while(p){
        while(p->LTag==0&&p->lchild!=NULL) p=p->lchild;
        printf("%d ",p->data);
        while(p->RTag==1&&p->rchild!=NULL){
            p=p->rchild;
            printf("%d ",p->data);
        }
        p=p->rchild;
    }
}
int main(){
    BiThrTree tree=createTree();
    InThreading(tree);
    pta(tree);
    printf("\n");
    InOrderTraverse_Thr(tree);
    return 0;
}