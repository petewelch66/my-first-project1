#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long fact=1;
	float sum=0.0,a;
	int i=1;
	scanf("%f",&a);
	
	while (1)
	{
		fact=fact*i;
		sum=sum+1.0/fact;
		i++;
		if (fact>1/a)
		break;
	}
	
	printf("%f",sum+1);
	return 0;
}

