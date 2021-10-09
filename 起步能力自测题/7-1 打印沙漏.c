#include<stdio.h>
int main(){
	int N,i=1;
	char a;
	scanf("%d %c",&N,&a);
	while(2*i*i-1<=N) i++;//计算第一行需要输出的符号个数
	i--; 
    int sum1=2*i*i-1;
    int sum2=N-sum1;
    int sum3,j,k,m=0,s;
	for(j=i;j>=1;j--){//打印上半漏斗
		sum3=2*j-1; 
		m++;
		for(s=2;s<=m;s++) printf(" "); 
		for(k=1;k<=sum3;k++) printf("%c",a);
		printf("\n");
	}
	for(j=2;j<=i;j++){//打印下半漏斗
		sum3=2*j-1; 
		m--;
		for(s=2;s<=m;s++) printf(" ");
		for(k=1;k<=sum3;k++) printf("%c",a);
		printf("\n");
	}
	printf("%d",sum2);
	return 0;
} 