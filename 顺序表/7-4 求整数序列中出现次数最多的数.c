#include <stdio.h>
#include <stdlib.h>
// const int N = 1005;
int A[1005]={0};
int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;

    return low;
}

void quick_sort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }

    return;
}

int main(void){
    
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        int in;scanf("%d",&in);
        A[i]=in;
    }

    
    quick_sort(A,0,len-1);

    // for(int i=0; i<len; i++)
    //     printf("%d ", A[i]);
    // printf ("\n");

    int now,nownum=0;
    int ans,ansnum=0;
    now=A[0];
    nownum=1;
    for(int i=1;i<len;i++){
        if(A[i]!=now){
            // printf("! ");
            if(nownum>ansnum){
                ansnum=nownum;
                ans=now;
                // printf("%d->%d",ans,ansnum);
            }
            nownum=1;
            now=A[i];
        }else{
            // printf("? ");
            nownum++;
        }
    }
    if(nownum>ansnum){
        ansnum=nownum;
        ans=now;
    }
    printf("%d %d",ans,ansnum);
    return 0;
}

