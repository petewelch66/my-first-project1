#include <stdio.h>
#include <stdlib.h>
#include <string.h>>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char crr[15];
	int i;
	int arr[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
	printf("Enter a word: ");
	fgets(crr,15,stdin);
	int sum=0;
	
	strupr(crr);
	for (i=0; crr[i] != '\0' && crr[i] != '\n';i++){
		char ch;
		ch=crr[i];
		sum=sum+arr[ch-'A'];
	}
	printf("Scrabble value: %d",sum);
	return 0;
}
