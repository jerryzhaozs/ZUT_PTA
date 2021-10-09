
#include<stdio.h>
#include<stdlib.h>
#define MAXN 100005
typedef struct Node{int *data;int len;}Node,*List;
List init(){
    List new=(List)malloc(sizeof(List));
    new->data=(int*)malloc(MAXN*sizeof(int));
    new->len=0;
    return new;
}
void insert(List L,int e){
    L->data[L->len]=e;
    L->len++;
}
void pta(List L){
    int ok=0;
    for(int i=0;i<L->len;i++){
        if(ok==0) printf("%d",L->data[i]);
        else printf(" %d",L->data[i]);
        ok=1;
    }
}
char str[20048];
int main(){
    scanf("%[^\n]",&str);
    getchar();
    scanf("%[^\n]",&str);
    getchar();
    int s[15]={0};
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ')continue;
        if(str[i]=='1') s[1]++;
        if(str[i]=='2') s[2]++;
        if(str[i]=='3') s[3]++;
        if(str[i]=='4') s[4]++;
        if(str[i]=='5') s[5]++;
        if(str[i]=='6') s[6]++;
        if(str[i]=='7') s[7]++;
        if(str[i]=='8') s[8]++;
        if(str[i]=='9') s[9]++;
        if(str[i]=='0') s[0]++;
    }
    List L=init();
    int maxx=0;
    for(int i=0;i<=9;i++){
        if(maxx<s[i]){
            L=init();
            insert(L,i);
            maxx=s[i];
            continue;
        }
        if(maxx==s[i]){
            insert(L,i);
            // printf("?%d\n",i);
            // maxx++;
            continue;
        }
    }
    printf("%d: ",maxx);
    pta(L);
    return 0;
}