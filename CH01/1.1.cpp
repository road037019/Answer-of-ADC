/*
��дһ��������ѡ�����⡣��k=N/2�����������ʾ��ĳ������N
Ϊ��ֵͬ������ʱ�� 
�����ӡ����һ�������е�N���ֵ 
*/ 

#include<stdio.h>  
#define MAXN 1000  
int arri[MAXN];  
  
/*������x�����СΪN��������*/ 
void intsert( int x, int N) {  
    int low, mid, high;  
    low = 0; high = N - 1;  
    while (low <= high) {     //��ֹѭ����������high>low; 
        mid = (low + high)/2;  
        if (arri[mid] <= x) {  //ͨ�������λ�ü���"="�ţ�����ظ�ֵҲ��������
								//�磺����5554���ڶ����������5��������ӣ��ڶ�
								//���������4 
            high = mid- 1;  
        }  
        else if (arri[mid]>x)  
            low = mid + 1;  
    }  //���������ѭ������ȷ��Ҫ�����λ�þ����ڣ�arri[high]��arri[low]��֮��  
    
    /*�������ԣ������whileѭ�������ò�����ԭ��������ע��������arri[low]�����ܱ�x��*/ 
    while (arri[low] > x){
    	printf("ceshi\n") ;
        low++;
    } 
		  
    for (int i = N - 1; i > low; i--) {  //��arri[low]�������ֵ������� 
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
    while (flag == 1)  //���մӴ�С�ķ�ʽ���� 
    {  
        flag = 0;  
        for (int i = 0; i < k - 1; i++) {  //���ѭ����ɽ���С�������ƶ�����β 
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
