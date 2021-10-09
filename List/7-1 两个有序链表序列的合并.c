#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{           
    int data;          
    struct LNode *next;
}LNode,*LinkedList;   

//创建链表
LinkedList createList(){
    LinkedList  headNode=(LinkedList)malloc(sizeof(LNode));

    //初始化
    headNode->data=0;
    headNode->next=NULL;
    return headNode;
}

//创建节点
LNode* createNode(int data){
    LNode* newNode = (LinkedList)malloc(sizeof(LNode*));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//插入
void insert(LinkedList L,int data){
    LNode* newNode = createNode(data);
    newNode->next=L->next;
    L->next=newNode;

}

//获取第k个值
int get(LinkedList L,int k){
    LNode* p=L->next;
    int op=k-1;
    while(op--&&p){
        p=p->next;
    }
    return p->data;
}
void ptaout(LinkedList L){
    LNode* p=L->next;
    while(p->next!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d",p->data);
}
int main(){

    LinkedList list1=createList();
    LinkedList list2=createList();
    int whi=10;
    while(whi==10){
        int in;scanf("%d",&in);
        if(in==-1) break;
        insert(list1,in);
    }
    while(whi==10){
        int in;scanf("%d",&in);
        if(in==-1) break;
        insert(list2,in);
    }
    
    LinkedList list3=createList();
    LNode* p1=list1->next;
    LNode* p2=list2->next;
    int ok=0;
    while(p1&&p2){
        if(p1->data==p2->data){
            insert(list3,p1->data);
            insert(list3,p1->data);
            ok=1;
            p1=p1->next;
            p2=p2->next;
        }else if(p1->data>p2->data){
            insert(list3,p1->data);
            p1=p1->next;
            ok=1;
        }else{
            insert(list3,p2->data);
            p2=p2->next;
            ok=1;
        }
    }
    while(p1){
        insert(list3,p1->data);
        p1=p1->next;
        ok=1;
    }
    while(p2){
        insert(list3,p2->data);
        p2=p2->next;
        ok=1;
    }
    if(ok==0) printf("NULL");
    else ptaout(list3);
    return 0;
}