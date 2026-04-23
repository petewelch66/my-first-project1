#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	float b;
	
	printf("Enter your salary:");
	scanf("%d",&a);
	
	if (a>0&&a<750)
	  b=a*0.01;
	else if (a>=750&&a<2250)
	  b=7.50+(a-750)*0.02;
	else if (a>=2250&&a<3750)
	  b=37.50+(a-2250)*0.03;
	else if (a>=3750&&a<5250)
	  b=82.50+(a-3750)*0.04;
	else if (a>=5250&&a<7000)
	  b=142.50+(a-5250)*0.05;
	else if (a>=7000)
	  b=230.00+(a-7000)*0.06;
	  
	printf("Your tax is:%.2f",b);
	return 0;
}
