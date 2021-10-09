#include <stdio.h>
#include <math.h>
int main(){
	int A[10005];
	int n,c;
	scanf("%d%d",&n,&c);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	c%=n;//取模，获取右移数组长度的整数倍后的偏移量
	int cnt=0;
	for(i=n-c+1;i<=n;i++){//向右移动，右侧到数组尾输出元素
		cnt++;
		if(cnt==n) printf("%d",A[i]);
		else printf("%d ",A[i]);
	}
	for(int i=1;i<=n-c;i++){//数组头到左侧输出元素
		cnt++;
		if(cnt==n) printf("%d",A[i]);
		else printf("%d ",A[i]);
	}
    return 0;
}