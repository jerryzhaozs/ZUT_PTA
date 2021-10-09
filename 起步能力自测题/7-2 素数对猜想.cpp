#include<iostream>
#include<cstdio>
#define maxn 100010
using namespace std;
int prime[maxn];//prime[i] 第i个素数
int visit[maxn];//visit[i] 第i个元素是被访问过
void Prime(){//素数筛
	int cnt=0;
    for (int i = 2;i <= maxn; i++) {
        if (!visit[i]) prime[++cnt] = i;
        for (int j = 1; j <=cnt && i*prime[j] <= maxn; j++) {
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main(){
	int n;cin>>n;
	Prime();
	int cnt=0;
	for(int i=1;prime[i]<=n;i++)//循环判断相邻素数之差是否为二
		if(prime[i]==prime[i-1]+2)
			cnt++;
	cout<<cnt-1;
	return 0;
}