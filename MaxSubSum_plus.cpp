/*
找任意一个序列中的最大子序列和，注意：是任意一个序列，可能包含负数，如果全部是
负数的话，就找负数中的最大值； 
*/ 

#include <iostream> 
#include <cmath>

using namespace std;

int MaxSubSum2(int a[], int size)
{
	int i,MaxSum=a[0],
	ThisSum=0;//截止到当前元素为止的最大子序列和； 
	int PreSum=a[0]; //PreSum指前面的序列的最大序列和 
	for(i=0;i<size;i++)
	{
		if(i!=0) PreSum=ThisSum;
		ThisSum+=a[i];
		if(ThisSum>MaxSum){//新读进的元素是正数 
			MaxSum=ThisSum;
		}else{ //新读进的元素是零或者负数 
			if(PreSum<a[i]){ //当前元素之前的最大子序列和如果比当前元素小 
				MaxSum=a[i]; //那么最大子序列的和就设置为当前元素； 
				if(a[i+1]!='\0'){
			 		if(a[i+1]>=0) ThisSum=0;
			 		else ThisSum=a[i];
					//else if(a[i+1]<PreSum) ThisSum=PreSum;
					//else if(a[i+1]>PreSum) ThisSum=0;
			    }
				//ThisSum=a[i];  //所以截止到当前元素的和设置为当前元素； 
			}else if(PreSum>a[i]&&a[i+1]!='\0'){//新读进的元素为负，当前元素之前的最大子序列的和比当前元素要大，那么就要考虑究竟大了多少，可能大到PreSum>0,如果大于零的话，ThisSum就保持就好 
				if(a[i+1]>=0&&PreSum<0) ThisSum=0;//如果下一元素是非负数，则把ThisSum清零； 
				else if(a[i+1]>=0&&PreSum>=0)  ThisSum=ThisSum; //注意，这儿是什么也不做，即这儿的ThisSum还是用上面算好的ThisSum，因为此时的ThisSum还是正值； 
				else ThisSum=PreSum; //如果下一元素是负数，则把ThisSum改为此元素之前的最大子序列和（因为此元素没有此元素之前的最大子序列和大） 
				//else if(a[i+1]<PreSum) ThisSum=PreSum;
				//else if(a[i+1]>PreSum) ThisSum=0;

			}else if(PreSum==a[i]&&a[i]<0&&a[i+1]!='\0'&&a[i+1]>0) ThisSum=0; //处理第一个元素为负，第二个元素为正的情况 
		} 		
	}  
	return MaxSum;
}

int main(){
	int a[5]={-2,1,2,-1,9};
	int result;
	result=MaxSubSum2(a,5);
	printf("result=%d\n",result);
}

/*
测试用例：
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
{2,-1,2,-1,9}
{2,-1,2,-1,-9} 
{-2,1,2,-1,9}
*/ 
