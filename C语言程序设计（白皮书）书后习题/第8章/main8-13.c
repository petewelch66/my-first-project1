#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char fname=' ';
	char c;
	int i=0;
	int lname=0;
	char arr[1000];
	printf("Enter a first and last name: ");
	while((c=getchar())!='\n'){
		if (c!=' '&&fname==' ')
		  fname=c;
		else if(c==' '&&lname==0)
		  lname=1;
		else if(c!=' '&&lname==1)
		  arr[i++]=c;
	}
	arr[i]="\0";
	printf("%s,%c.",arr,fname);
	return 0;
}
