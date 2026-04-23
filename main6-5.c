#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long n;
	printf("Please enter a number:");
	scanf("%ld",&n);
	printf("The reversal is :");
	
	if (n==0)
	  printf("0");
	else if (n<0) {
	  n=-n;
	  printf("-");   
	  while (n!=0){
		printf("%ld",(n%10));
		n=n/10;
		}
    }
	else {
	  while (n!=0){
		printf("%ld",(n%10));
		n=n/10;
		}
    }
	return 0;
}
