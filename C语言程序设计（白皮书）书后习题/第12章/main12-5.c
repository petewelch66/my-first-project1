#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char sentence[100];
	char c;
	char* p=sentence;
	*p++=' ';
	printf("Enter a sentence: ");
	c=getchar();
	while(c!='.'&&c!='!'&&c!='?'){
		*p++=c;
		c=getchar();
	}
	
	printf("Reversal of sentence: ");
	p--;
	while(p>sentence){
		int i=0,k;
		while(*(p--)!=' ')
		i++;
		for (k=2;k<=i+2;k++)
		  printf("%c",*(p+k));
	}
	printf("%c",c);
	return 0;
}
