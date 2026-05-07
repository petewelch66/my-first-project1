#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[10],i,size;
	
	size=(int)(sizeof (a)/sizeof (a[0]));
	printf("Enter your numbers:");
	for (i=0;i<size;i++)
	  scanf("%d",&a[i]);
	  
	printf("In reverse order:");
	for (i=size-1;i>=0;i--)
	  printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}
