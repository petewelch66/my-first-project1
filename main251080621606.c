//编程输出所有的玫瑰花数
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sicimi(int a) //4次幂的函数 
{
	return a*a*a*a;
}
int main(int argc, char *argv[]) {
	int a,g,s,b,q;
	
	printf("所有玫瑰花数如下：\n"); 
	for (a=1000;a<10000;a++){    //遍历所有四位数 
	q=a/1000;                //千位 
	b=a/100-q*10;			 //百位 
	s=a/10-10*b-100*q;		 //十位 
	g=a-10*s-100*b-1000*q;   //个位 
	if (a==sicimi(q)+sicimi(b)+sicimi(s)+sicimi(g))  //判断是否满足玫瑰花数的条件 
	  printf("%d\n",a); //输出所有玫瑰花数 
}
	 
	return 0;
}
