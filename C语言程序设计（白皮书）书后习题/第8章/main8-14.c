#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char arr[100];
	char ch;
	int i,k,n=0;
	arr[0]=' ';
	printf("Enter a sentence: ");
	ch=getchar();
	while (ch!='.'&&ch!='!'&&ch!='?'){
	  arr[++n]=ch;
	  ch=getchar();
}
    printf("Reversal of sentence:");
    while(n>0){
    	i=n;
    	while (n>=0&&arr[n--]!=' ') 
    	  for(k=n+1;k<=i;k++)
    	    printf("%c",arr[k]);
	}
	printf("c",ch);
	return 0;
}
