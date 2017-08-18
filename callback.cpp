/*
实现一个简单的回调函数，来说明回调的基本原理；

通常情况下函数的调用顺序是：用户调用操作系统的函数，上层函数调用下层的函数；
而所谓的回调是指由操作系统调用用户编写的函数，或者由底层函数调用上层的函数；

由于操作系统的代码在用户代码之前就已经编写编译完成，因此由操作系统发起的回调一般
都必须通过将用户编写的函数的函数指针传递给操作系统，再由操作系统实现回调。 
*/


#include <stdio.h>

/*用户的函数1------这是回调函数1*/ 
void printWelcome(int len)   
{
       printf("欢迎欢迎 -- %d\n", len);
}

/*用户函数2-------这是回调函数2*/ 
void printGoodbye(int len)
{
       printf("送客送客 -- %d\n", len);
}

/*操作系统实现回调操作的函数*/ 
void callback(int times, void (* print)(int))
{
       int i;
       for (i = 0; i < times; ++i)
       {
              print(i);  //在这个位置实现回调，即操作系统回去执行用户编写的函数； 
       }
       printf("/n我不知道你是迎客还是送客!\n\n");
}

/*用户的主函数*/
int main(void)
{
       callback(10, printWelcome);  //这一步是将用户的函数指针传递给操作系统函数callback，然后由操作系统实现回调； 
       callback(10, printGoodbye);  //同上； 
       printWelcome(5);
}