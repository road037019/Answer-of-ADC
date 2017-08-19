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
int maxSumRec( const vector< int > &a, int left, int right )  
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
    return maxSumRec( a, 0, a.size( ) - 1 );  
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
