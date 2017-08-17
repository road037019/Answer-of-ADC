/*
编写一个程序解决选择问题。令k=N/2，画出表格显示你的程序对于N
为不同值的运行时间 
程序打印的是一个数组中第N大的值 
*/ 

#include<stdio.h>  
#define MAXN 1000  
int arri[MAXN];  
  
/*将数据x插入大小为N的数组中*/ 
void intsert( int x, int N) {  
    int low, mid, high;  
    low = 0; high = N - 1;  
    while (low <= high) {     //终止循环的条件是high>low; 
        mid = (low + high)/2;  
        if (arri[mid] <= x) {  //通过在这个位置加上"="号，会把重复值也算入其中
								//如：序列5554，第二大的数还是5；如果不加，第二
								//大的数就是4 
            high = mid- 1;  
        }  
        else if (arri[mid]>x)  
            low = mid + 1;  
    }  //经过上面的循环，会确定要插入的位置就是在（arri[high]，arri[low]）之间  
    
    /*经过测试，这儿的while循环好像用不到，原因如上条注释所讲，arri[low]不可能比x大*/ 
    while (arri[low] > x){
    	printf("ceshi\n") ;
        low++;
    } 
		  
    for (int i = N - 1; i > low; i--) {  //将arri[low]后面的数值集体后移 
        arri[i] = arri[i - 1];  
    }  
    arri[low] = x;  
}  
  
int main() {  
    int k,n;  
    scanf("%d", &n);  
    k = n / 2;  
    for (int i = 0; i < k; i++) {  
        scanf("%d", &arri[i]);  
    }  
    int flag=1;  
    while (flag == 1)  //按照从大到小的方式排序， 
    {  
        flag = 0;  
        for (int i = 0; i < k - 1; i++) {  //这个循环完成将最小的数据移动到队尾 
            if (arri[i] < arri[i + 1]) {  
                flag = 1;  
                int t = arri[i + 1];  
                arri[i + 1] = arri[i];  
                arri[i] = t;  
            }  
        }  
    }  
    for (int i = k; i < n; i++){  
        int t;  
        scanf("%d", &t);  
        if (t > arri[k - 1])  
            intsert(t, k);  
    }  
    printf("k biggest:%d", arri[k - 1]);  
}  
