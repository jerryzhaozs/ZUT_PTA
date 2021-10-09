#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{            //声明节点的类型和指向节点的指针类型
    int data;                    //节点的数据域
    int pre;
    struct LNode *next;          //节点的指针域
}LNode,*LinkedList;   

//创建链表
LinkedList createList(){
    LinkedList  headNode=(LinkedList)malloc(sizeof(LNode));

    //初始化
    headNode->data=0;
    headNode->pre=0;
    headNode->next=NULL;
    return headNode;
}

//创建节点
LNode* createNode(int data,int pre){
    LNode* newNode = (LinkedList)malloc(sizeof(LNode*));
    newNode->data=data;
    newNode->pre=pre;
    newNode->next=NULL;
    return newNode;
}

//插入newNode
void insertnewNode(LinkedList L,LNode* newNode){
    newNode->next=L->next;
    L->next=newNode;
}
//ptaout
void pta(LinkedList L){
    int ok=0;
    LNode* p=L->next;
    while(p!=NULL){
        if(ok==0){
            printf("%d %d",p->data,p->pre);
        }else{
            printf(" %d %d",p->data,p->pre);
        }
        ok=1;
        p=p->next;
    }
}
int lenn(LinkedList L){
    LNode* p=L->next;
    if(p){
        return 0;
    }
    return 1;
}
int main(){

    LinkedList list=createList();
    LinkedList ans=createList();

    int whi=10;
    int data,pre;
    while(scanf("%d%d",&data,&pre)!=EOF){
        // scanf("%d%d",&data,&pre);
        LNode* newNode=createNode(data,pre);
        insertnewNode(list,newNode);
        if(pre==0) break;
    }
    
    LNode* p=createNode(0,0);
    p=list->next;
    while(p){
        if(p->pre==0){
            p=p->next;
            continue;
        }
        LNode* newNode=createNode(p->data*p->pre,p->pre-1);
        insertnewNode(ans,newNode);
        p=p->next;
    }
    if(lenn(ans)==1)
        printf("0 0");
    else
        pta(ans);
    return 0;
}