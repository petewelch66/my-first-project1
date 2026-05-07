#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int ch,a,i=0;
	char *j;
	char str[99];
	
	printf("Enter a message: ");
	while ((ch=getchar()) !='\n')
	  str[i++]=ch;
	str[i]='\0';
	a=i;
	
	printf("Reversal is: ");
	for(j=str+a-1;j>=str;j--)
	  printf("%c",*j);
	return 0;
}
