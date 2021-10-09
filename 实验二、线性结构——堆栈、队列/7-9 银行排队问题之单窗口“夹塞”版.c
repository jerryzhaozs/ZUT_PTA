#include<stdio.h>
#include<stdlib.h>
#define MAXN 10005
typedef struct person{int name;int p;int t;}person;
typedef struct Node{person *data;int len;int s_;int e_;}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(person*)malloc(MAXN*sizeof(person));
    new->len=0;
    new->e_=0;
    new->s_=0;
    return new;
}
// int mapf[10005],mapt[10005];
int toint(char *s){
    // printf("%d\n",(s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A'));
    return (s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A');
}
void outt(int k){
    printf("%c",(char)('A'+k/26/26));k%=26*26;
    printf("%c",(char)('A'+k/26));k%=26;
    printf("%c\n",(char)('A'+k));
}
int M_(int a,int b){
    return a>b?a:b;
}
int mp[20000]={0};
int vis[10005]={0};
person a[10005];
int main(){
    List L=init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int g;scanf("%d",&g);
        for(int j=0;j<g;j++){
            char s[4];
            scanf("%s",&s);
            mp[toint(s)]=i;
        }
    }
    for(int i=0;i<n;i++){
        char s[4];
        scanf("%s %d %d",&s,&a[i].t,&a[i].p);
        a[i].name=toint(s);
        if(a[i].p>60) a[i].p=60;
    }
    L->data[L->e_++]=a[0];
    vis[0]=1;
    int last=a[0].t+a[0].p;
    int sum=0;
    while(L->s_!=L->e_){
        person f=L->data[L->s_];
        L->s_++;
        outt(f.name);
        int found=0;
        for(int i=1;i<n;i++){
            if(vis[i]==1) continue;
            if(a[i].t>last) break;
            if(mp[a[i].name]==0) continue;
            if(mp[f.name]==mp[a[i].name]){
                L->data[L->e_++]=a[i];
                vis[i]=1;
                found=1;
                sum+=last-a[i].t;
                last+=a[i].p;
                break;
            }
        }
        if(found==0){
            for(int i=1;i<n;i++){
                if(vis[i]==1) continue;
                L->data[L->e_++]=a[i];
                vis[i]=1;
                sum+=M_(0,last-a[i].t);
                if(a[i].t>last) last=a[i].t;
                last+=a[i].p;
                break;
            }
        }
    }
    printf("%.1lf\n",1.0*sum/n);
    return 0;
}