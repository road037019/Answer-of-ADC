/*
������һ�������е���������кͣ�ע�⣺������һ�����У����ܰ������������ȫ����
�����Ļ������Ҹ����е����ֵ�� 
*/ 

#include <iostream> 
#include <cmath>

using namespace std;

int MaxSubSum2(int a[], int size)
{
	int i,MaxSum=a[0],
	ThisSum=0;//��ֹ����ǰԪ��Ϊֹ����������кͣ� 
	int PreSum=a[0]; //PreSumָǰ������е�������к� 
	for(i=0;i<size;i++)
	{
		if(i!=0) PreSum=ThisSum;
		ThisSum+=a[i];
		if(ThisSum>MaxSum){//�¶�����Ԫ�������� 
			MaxSum=ThisSum;
		}else{ //�¶�����Ԫ��������߸��� 
			if(PreSum<a[i]){ //��ǰԪ��֮ǰ����������к�����ȵ�ǰԪ��С 
				MaxSum=a[i]; //��ô��������еĺ;�����Ϊ��ǰԪ�أ� 
				if(a[i+1]!='\0'){
			 		if(a[i+1]>=0) ThisSum=0;
			 		else ThisSum=a[i];
					//else if(a[i+1]<PreSum) ThisSum=PreSum;
					//else if(a[i+1]>PreSum) ThisSum=0;
			    }
				//ThisSum=a[i];  //���Խ�ֹ����ǰԪ�صĺ�����Ϊ��ǰԪ�أ� 
			}else if(PreSum>a[i]&&a[i+1]!='\0'){//�¶�����Ԫ��Ϊ������ǰԪ��֮ǰ����������еĺͱȵ�ǰԪ��Ҫ����ô��Ҫ���Ǿ������˶��٣����ܴ�PreSum>0,���������Ļ���ThisSum�ͱ��־ͺ� 
				if(a[i+1]>=0&&PreSum<0) ThisSum=0;//�����һԪ���ǷǸ��������ThisSum���㣻 
				else if(a[i+1]>=0&&PreSum>=0)  ThisSum=ThisSum; //ע�⣬�����ʲôҲ�������������ThisSum������������õ�ThisSum����Ϊ��ʱ��ThisSum������ֵ�� 
				else ThisSum=PreSum; //�����һԪ���Ǹ��������ThisSum��Ϊ��Ԫ��֮ǰ����������кͣ���Ϊ��Ԫ��û�д�Ԫ��֮ǰ����������кʹ� 
				//else if(a[i+1]<PreSum) ThisSum=PreSum;
				//else if(a[i+1]>PreSum) ThisSum=0;

			}else if(PreSum==a[i]&&a[i]<0&&a[i+1]!='\0'&&a[i+1]>0) ThisSum=0; //�����һ��Ԫ��Ϊ�����ڶ���Ԫ��Ϊ������� 
		} 		
	}  
	return MaxSum;
}

int main(){
	int a[5]={2,-1,2,1,-9} ;
	int result;
	result=MaxSubSum2(a,5);
	printf("result=%d\n",result);
}

/*
����������
{-2,-1,2,5,-1} 
{-2,-3,2,5,-1}
{-2,-7,-2,-5,-1}
{-2,0,-2,-5,-1}
{-2,-3,-2,-5,0}
{2,1,2,5,1} 
{-1,-2,-2,-5,-9}
{-1,2,-2,-5,-9} 
{-2,1,2,1,-9}
{-2,-1,2,1,-9}
{2,-1,2,1,-9}
*/ 
