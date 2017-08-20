/*
@todo：求最大子序列和的问题
采用分治法+递归的思想；
采用递归的一个基本思路就是把一个序列一份为2之后，得到的两个子序列可以继续一分为2，并且如果我们继续分下去的话，最终会有一个基本解的情况，那就是每个
自序列变成了只有一个元素的序列，这种最终情况是可以很方便的求出来的，然后再层层的往外求。
例如：{1, 2, 3}一份为2，变成{1，2 | 3}，此时左边的子序列的maxSubSum(a, 0, 1),右边的maxSubSum(a, 2, 2)。maxSubSum(a,2,2)可以很方便的求出来，
而maxSubSum(a,0,1)再分，变为了maxSubSum(a,0,0)和maxSubSum(a,1,1),这两个可以很简单的求出来，往上推，那么maxSubSum(a,0,1)就可以求出来了，
再往上推，maxSubSum(a,0,2)即{1，2 | 3}这个序列的最大子序列就可以求出来

*/



#include <iostream>
#include <vector>
//#include <stdio.h> 
using namespace std;

/*求三个数中的最大值*/
int max3(int a, int b, int c ){
	int max;
	if (a>b)
	max=a;
	else max=b;
	if (max>c)
	return max;
	else return c; 
}

/*返回最大的序列和*/
int maxSubSum( const vector< int > &a, int left, int right )  
{  
    if( left == right )  // Base case  
        if( a[left] > 0 )  
            return a[left];  
        else  
            return 0;  
    int center = ( left + right ) / 2;  
    int maxLeftSum  = maxSumRec( a, left, center );  
    int maxRightSum = maxSumRec( a, center + 1, right );  
    int maxLeftBorderSum = 0, leftBorderSum = 0;  
    for( int i = center; i >= left; i-- )  
    {  
        leftBorderSum += a[ i ];  
        if( leftBorderSum > maxLeftBorderSum )  
            maxLeftBorderSum = leftBorderSum;  
    }  
    int maxRightBorderSum = 0, rightBorderSum = 0;  
    for( int j = center + 1; j <= right; j++ )  
    {  
        rightBorderSum += a[ j ];  
        if( rightBorderSum > maxRightBorderSum )  
            maxRightBorderSum = rightBorderSum;  
    }  
    return max3( maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum );  
}  
  
/** 
 * Driver for divide-and-conquer maximum contiguous 
 * subsequence sum algorithm. 
 */  
int maxSubSum3( const vector<int> & a )  
{  
    return maxSubSum( a, 0, a.size( ) - 1 );  
} 

int main(){
	vector<int> a;
	int result;
	int b[5]={1,2,3,4,5};
	for(int i=0; i<5; i++)
	a.push_back(b[i]);
 	result=maxSubSum3(a);
 	printf("result=%d\n",result);
}
