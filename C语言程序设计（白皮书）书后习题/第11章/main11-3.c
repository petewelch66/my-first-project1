#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reduce(int numerator,int denominator,int *reduced_numerator,int *reduced_denominator){
	int m,n,gcd,i;
	m=numerator;
	n=denominator;
	while(n!=0){
		i=m%n;
		m=n;
		n=i;
	}
	gcd=m;
	*reduced_numerator=numerator/gcd;
	*reduced_denominator=denominator/gcd;
}
int main(int argc, char *argv[]) {
	int n,d,nn,nd;
	printf("Enter a fraction: ");
	scanf("%d/%d",&n,&d);
	reduce(n,d,&nn,&nd);
	printf("In lowest terms: %d/%d",nn,nd);
	
	return 0;
}
