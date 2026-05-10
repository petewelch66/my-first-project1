#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap1(int a,int b)
{
	int c;
	c=a;a=b;b=c;
	printf("swap1中的a=%d,b=%d",a,b);
}
void swap2(int *a,int *b)
{
	int c;
	c=*a;*a=*b;*b=c;
}
void main(int argc, char *argv[]) {
	int x=100,y=800;
	swap1(x,y);
	printf("\n调用swap1后x=%d,y=%d",x,y);
	x=100;y=800;
	swap2(&x,&y);
	printf("\n调用swap2后x=%d,y=%d",x,y);
}
