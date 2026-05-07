#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[50];
	int ch,i=0;
	char *j;

	printf("Enter a message: ");
	while ((ch=getchar())!='\n')
	  if(isalpha(ch)){
	  ch=tolower(ch);
	  str[i++]=ch;
}
	str[i]='\0';
	
	for(j=str;j<str+i/2;j++)
	  if (*j!=*(str+i-1-(j-str)))
	    break;
	if(j<str+i/2)
	  printf("Not a palindrome\n");
	else 
	  printf("Palindrome\n");
	return 0;
}

