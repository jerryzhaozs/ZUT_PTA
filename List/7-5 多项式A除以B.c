#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
    double data;
    int pre;
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
LNode* createNode(double data,int pre){
    LNode* newNode=(LNode*)malloc(sizeof(LNode*));
    newNode->data=data;
    newNode->pre=pre;
    newNode->next=NULL;
    return newNode;
}
void inserttail(List L,double data,int pre){
    LNode* newNode=createNode(data,pre);
    if(L->len==0){
        L->tail=newNode;
        L->head=newNode;
    }else{
        L->tail->next=newNode;
        L->tail=newNode;
    }
    L->len++;
}
void pta(List L){
    int ok=0;
    LNode* p=L->head;
    while(p){
        if(p->data<0.05&&p->data>=-0.05){
            p=p->next;
            continue;
        }
        if(ok==0) printf("%d %.1lf",p->pre,p->data);
        else printf(" %d %.1lf",p->pre,p->data);
        p=p->next;
        ok=1;
    }
}
void cuthead(List l){
    l->head=l->head->next;
    l->len--;
}
List Multiplication(List L,double xi,int zhi){
    List out=init();
    LNode* p=L->head;
    while(p){
        inserttail(out,p->data*xi,p->pre+zhi);
        p=p->next;
    }
    return out;
}
List summ(List list1,List list2){
    List sumans=init();
    int whi=10;
    LNode* p1=list1->head;
    LNode* p2=list2->head;
    while(whi==10){
        if(p1&&p2){
            if(p1->pre==p2->pre){
                if(p1->data-p2->data>=0.01||p1->data-p2->data<=-0.01){
                    inserttail(sumans,p1->data-p2->data,p1->pre);
                }
                p1=p1->next;
                p2=p2->next;
            }else if(p1->pre>p2->pre){
                inserttail(sumans,p1->data,p1->pre);
                p1=p1->next;
            }else{
                inserttail(sumans,(-1)*p2->data,p2->pre);
                p2=p2->next;
            }
        }else{
            break;
        }
    }
    if(p1)
        while(p1){
            inserttail(sumans,p1->data,p1->pre);
            p1=p1->next;
        }
    if(p2)
        while(p2){
            inserttail(sumans,(-1)*p2->data,p2->pre);
            p2=p2->next;
        }
    return sumans;
}
int getLenght(List L){
    LNode* p=L->head;
    int cnt=0;
    while(p){
        if(p->data>=0.05||p->data<-0.05) cnt++;
        p=p->next;
    }
    return cnt;
}
int main(){
    List list1=init();
    List list2=init();
    List ans=init();
    int a;scanf("%d",&a);
    for(int i=1;i<=a;i++){
        double data;int pre;
        scanf("%d %lf",&pre,&data);
        inserttail(list1,data,pre);
    }
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        double data;int pre;
        scanf("%d %lf",&pre,&data);
        inserttail(list2,data,pre);
    }
    int whi=10;
    while(whi==10){
        if(list1->head==NULL){break;}
        if(list1->head->pre<list2->head->pre) break;
        LNode* new=createNode(0,0);
        double data=(list1->head->data)/(list2->head->data);
        int pre=(list1->head->pre)-(list2->head->pre);
        inserttail(ans,data,pre);
        List subnum=init();
        subnum=Multiplication(list2,data,pre);
        cuthead(list1);
        cuthead(subnum);
        if(subnum->len==0) break;
        list1=summ(list1,subnum);
    }
    int lenn1=getLenght(ans),lenn2=getLenght(list1);
    if(lenn1!=0){
        printf("%d ",lenn1);
        pta(ans);
    }else printf("0 0 0.0");
    printf("\n");
    if(lenn2!=0){
        printf("%d ",lenn2);
        pta(list1);
    }else printf("0 0 0.0");
    return 0;
}