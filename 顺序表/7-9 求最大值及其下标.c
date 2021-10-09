#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_INIT_SIZE 10010
#define eps 0.0001
typedef struct{
//   int *data;
    int data[LIST_INIT_SIZE];
  int len;  //当前长度
  int listsize;  //线性表的长度
}*Array,SqList;

Array init(){
    SqList L;
    Array a=&L;
    // a->data=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    a->len=0;
    a->listsize=LIST_INIT_SIZE;
    return a;
}
void inserttail(Array L,int t){
    L->data[L->len]=t;
    L->len++;
}
void pta(Array L){
    for(int i=0;i<L->len;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

double SqrtByBisection(double n) //用二分法 
{ 
    if(n<0) //小于0的按照你需要的处理 
        return n; 
    double mid,last; 
    double low,up; 
    low=0,up=n; 
    mid=(low+up)/2; 
    do
    {
        if(mid*mid>n)
            up=mid; 
        else 
            low=mid;
        last=mid;
        mid=(up+low)/2; 
    }while(abs(mid-last) > eps);//精度控制
    return mid; 
}
float InvSqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int*)&x; 
    i = 0x5f375a86 - (i>>1); 
    x = *(float*)&i;
    x = x*(1.5f-xhalf*x*x); 
    x = x*(1.5f-xhalf*x*x); 
    x = x*(1.5f-xhalf*x*x);
 
    return 1/x;
}
int a[10005];
int main()
{
    int n;scanf("%d",&n);
    int maxx=-99999,max_=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(maxx<a[i]){
            max_=i;
            maxx=a[i];
        }
    }
    printf("%d %d",maxx,max_-1);
    return 0;
}