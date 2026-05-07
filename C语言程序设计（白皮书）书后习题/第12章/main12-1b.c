#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int ch,*a,j,i=0;
	char str[99];
	
	printf("Enter a message: ");
	while ((ch=getchar()) !='\n')
	  str[i++]=ch;
	str[i]='\0';
	a=&i;
	
	printf("Reversal is: ");
	for(j=*a-1;j>=0;j--)
	  printf("%c",str[j]);
	return 0;
}
