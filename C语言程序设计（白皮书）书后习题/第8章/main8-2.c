#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int digit_seen[10]={0};
	int digit,flag=1;
	long n;
	
	printf("Enter a number: ");
	scanf("%ld",&n);
	
	while (n>0){
		digit=n%10;
		digit_seen[digit]++;
		n/=10;
	}
	
	printf("Digit:       ");
	for (digit=0;digit<10;digit++){
	  printf("%d ",digit);
}
    printf("\nOccurrences: ");
    for (digit=0;digit<10;digit++){
    	printf("%d ",digit_seen[digit]);
	}
	
	
	return 0;
}
