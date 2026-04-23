#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char arr[100];
	int i,len;
	
	printf("Enter message:");
	fgets(arr,100,stdin);
	
	strupr(arr);
	
	printf("In B1FF-speak:");
	for (i=0;i<100;i++){
	  if (arr[i]=='A')
	  arr[i]='4';
	  else if (arr[i]=='B')
	  arr[i]='8';
	  else if (arr[i]=='E')
	  arr[i]='3';
	  else if (arr[i]=='I')
	  arr[i]='1';
	  else if (arr[i]=='O')
	  arr[i]='0';
	  else if (arr[i]=='S')
	  arr[i]='5';
}
    len=strlen(arr);
    if (len>0 && arr[len-1]=='\n'){
    	arr[len-1]='\0';
    	len=len-1;
	}
    
	printf("%s",arr);
	printf("!!!!!!!!!!");
	return 0;
}
