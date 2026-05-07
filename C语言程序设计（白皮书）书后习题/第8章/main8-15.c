#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char arr[80];
	int a;
	char c;
	int i=0;
	printf("Enter message to be encrypted: ");
	while((c=getchar())!='\n' && i<79){
	  arr[i++]=c;
}
    arr[i]='\0';
	printf("Enter shift amuont(1-25): ");
	scanf("%d",&a);
	
	if (a>25 ||a<1){
		return 1;
	}
    for(i=0;arr[i]!='\0';i++)
	{
		c=arr[i];
		if (c>='A' &&c<='Z')
		c=((c-'A')+a)%26+'A';
		else if (c>='a' &&c<='z')
		c=((c-'a')+a)%26+'a';
		arr[i]=c;
	}
	printf("Encrypted message: ");
	for(i=0;arr[i]!='\0';i++)
	{
		printf("%c",arr[i]);
	}
	return 0;
}
