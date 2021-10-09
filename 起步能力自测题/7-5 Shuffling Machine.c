#include <stdio.h>
void out(int x){//输出，方便存储数据
	if(x==1) printf("S1");
	if(x==2) printf("S2");
	if(x==3) printf("S3");
	if(x==4) printf("S4");
	if(x==5) printf("S5");
	if(x==6) printf("S6");
	if(x==7) printf("S7");
	if(x==8) printf("S8");
	if(x==9) printf("S9");
	if(x==10) printf("S10");
	if(x==11) printf("S11");
	if(x==12) printf("S12");
	if(x==13) printf("S13");
	
	if(x==14) printf("H1");
	if(x==15) printf("H2");
	if(x==16) printf("H3");
	if(x==17) printf("H4");
	if(x==18) printf("H5");
	if(x==19) printf("H6");
	if(x==20) printf("H7");
	if(x==21) printf("H8");
	if(x==22) printf("H9");
	if(x==23) printf("H10");
	if(x==24) printf("H11");
	if(x==25) printf("H12");
	if(x==26) printf("H13");
	
	if(x==27) printf("C1");
	if(x==28) printf("C2");
	if(x==29) printf("C3");
	if(x==30) printf("C4");
	if(x==31) printf("C5");
	if(x==32) printf("C6");
	if(x==33) printf("C7");
	if(x==34) printf("C8");
	if(x==35) printf("C9");
	if(x==36) printf("C10");
	if(x==37) printf("C11");
	if(x==38) printf("C12");
	if(x==39) printf("C13");
	
	if(x==40) printf("D1");
	if(x==41) printf("D2");
	if(x==42) printf("D3");
	if(x==43) printf("D4");
	if(x==44) printf("D5");
	if(x==45) printf("D6");
	if(x==46) printf("D7");
	if(x==47) printf("D8");
	if(x==48) printf("D9");
	if(x==49) printf("D10");
	if(x==50) printf("D11");
	if(x==51) printf("D12");
	if(x==52) printf("D13");
	
	if(x==53) printf("J1");
	if(x==54) printf("J2");
}
int main ()
{
	int ans[55];
	int ans2[55];
	for(int i=1;i<=54;i++){ans[i]=i;}
	int b[55];
	int bb[55];
	int w;
	scanf("%d",&w);
	for(int i=1;i<=54;i++){//记录变换规则
		scanf("%d",&bb[i]);
		b[bb[i]]=i;
	}
	while(w--){
		for(int i=1;i<=54;i++){//进行变换
			ans2[bb[i]]=ans[i];
		}
		for(int i=1;i<=54;i++){//将新数组转为旧数组
			ans[i]=ans2[i];
		}
	}
	for(int i=1;i<=54;i++){
		out(ans[i]);
		if(i!=54) printf(" ");
	}
    return 0;
}