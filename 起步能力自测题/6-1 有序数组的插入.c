bool Insert( List L, ElementType X ){
	int ok=1;
    if(L->Last+1==MAXSIZE) return false;//如果顺序表已经满了就返回false
    for (int i=0; i<=L->Last; i++) {//遍历顺序表
        if(L->Data[i]==X) return false;//如果该元素已经存在返回false
        else if (L->Data[i]<X) {//在顺序表中找到插入位置
            for (int j=L->Last; j>=i; j--) {//后续的元素全部右移一位
                L->Data[j+1]=L->Data[j];
            }
            L->Data[i]=X;
            L->Last=L->Last+1;
			ok=1;
            break;
        }else if(i==L->Last&&L->Data[L->Last]>X){//若遍历到表尾仍为最小元素则在表尾插入
            L->Last=L->Last+1;
            L->Data[L->Last]=X;
            return true;
        }
	}
    return true;
}