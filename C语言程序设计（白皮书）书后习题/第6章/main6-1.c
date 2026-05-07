#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float number;
	float max=0;
	
	printf("Enter a number:");
	scanf("%f",&number);
	max=number;
	
	while(number>0)
	{
	printf("Enter a number:");
	scanf("%f",&number);
	if (number>max)
	    max=number;
}
    printf("The largest number entered was %f",max);
	
	return 0;
}
