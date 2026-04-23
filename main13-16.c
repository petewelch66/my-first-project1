#include <stdio.h>
#include <string.h>
#define MAX 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char *message);

int main(int argc, char *argv[]) {
	char str[MAX];
	char ch;
	int i=0;
	
	printf("Enter a message: ");
	while((ch=getchar())!='\n'&& i<MAX)
	  str[i++]=ch;
	reverse(str);
	printf("Reverse is: %s",str);
	return 0;
}

void reverse(char *message)
{
	char *phead=message;
	char *ptail=message+strlen(message)-1;
	char temp;
	while(phead!=ptail){
		temp=*phead;
		*phead=*ptail;
		*ptail=temp;
		phead++;
		ptail--;
	}
}
