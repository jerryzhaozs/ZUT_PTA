#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int flag;
typedef double ElementType;
typedef struct{
	ElementType data[maxn];
	int e_;
}List,*pL;
ElementType gettail(pL L){
	double out;
	if(L->e_==-1){
		flag=1;
		return 0;
	}
	else out=L->data[L->e_--];
	return out;
}
void insert(pL L,ElementType e){
	L->data[++L->e_]=e;
}
int main(){
    pL L=(List *)malloc(sizeof(List));
    char str[30];
    gets(str);
    // getchar();
    L->e_=-1;
    int len=strlen(str);
    for(int i=len-1;i>=0;i--){
        // printf("!");
        if(str[i]==' ') continue;
        // printf("!");
        int weishu=1;
        double in=0;
        if(str[i]>='0'&&str[i]<='9'){
            in=(str[i]-'0')*weishu;
            i--;
            while(str[i]>='0'&&str[i]<='9'){
                weishu*=10;
                in+=(str[i]-'0')*weishu;
                i--;
            }
            if(str[i] == '.'){
                in=in/(weishu*10);
                i--;
                weishu=1;
                while(str[i]>='0'&&str[i]<='9'){
                    in+=(str[i]-'0')*weishu;
                    weishu*=10;
                    i--;
                }
            }
            if(str[i]=='-') insert(L,(-1)*in);
            else insert(L,in);
        }
        else if(str[i]=='-'||str[i]=='+'||str[i]=='*'||str[i]=='/'){
            double a,b;
            a=gettail(L);
            b=gettail(L);
            if(flag==1){
                printf("ERROR\n");
                return 0;
            }
            double ans=0;
            char ha=str[i];
            if(ha=='+'){ans=a+b;}
            if(ha=='-'){ans=a-b;}
            if(ha=='*'){ans=a*b;}
            if(ha=='/'){
                if(b==0){
                    printf("ERROR\n");
                    return 0;
                }
                ans=a/b;
            }
            // printf("%d %d -> %d",a,b,ans);
            insert(L,ans);
        }
    }
    if(L->e_!=0){
        printf("ERROR\n");
        return 0;
    }
    printf("%.1lf\n",gettail(L));
    return 0;
}