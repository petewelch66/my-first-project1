#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long a,fact=1;
	float sum=0.0;
	int i=1;
	scanf("ld",&a);
	
	while (i<=a)
	{
		fact=fact*i;
		sum=sum+1.0/fact;
		i++;
	}
	
	printf("%f",sum+1);
	return 0;
}

