#include<iostream>
#include<map>
using namespace std;
map<int,int> mp1,mp2;
int main(){
	string s;
	int a[205]={0},add[205]={0};
	cin>>s;
	int cnt=0;
	for(int i=s.size()-1;i>=0;i--) a[++cnt]=s[i]-'0';//字符串转数字
	
	for(int i=1;i<=cnt;i++) mp1[a[i]]++;//获取每个数字的出现次数
	int len=cnt;
	int ok=0;
	for(int i=1;i<=cnt;i++){//进行乘法操作
		a[i]*=2;
		if(a[i]>=10){
			a[i]-=10;
			add[i+1]+=1;
			if(i==cnt){
				len=cnt+1;
				cout<<"No\n";
				ok=1;
			}
		}
	}
	for(int i=1;i<=len;i++){//检查运算后的答案每个数字的出现次数
		a[i]+=add[i];
		mp2[a[i]]++;
	}
	if(ok!=1)
        for(int i=0;i<=9;i++){
            if(mp1[i]!=mp2[i]){
                cout<<"No\n";
                ok=2;
                break;
            }
        }
	if(ok==0)
		cout<<"Yes\n";
	for(int i=len;i>=1;i--)
		cout<<a[i];
}