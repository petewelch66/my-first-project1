#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c;
	int len,i; 
	int arr[26]={0};
	
	printf("Enter first word: ");
	while((c=getchar())!='\n'){
	  if (isalpha(c)){
	    c=tolower(c);
	    arr[c-'a']++;
	}
}
	printf("Enter second word: ");
	while((c=getchar())!='\n'){
	  if (isalpha(c)){
	    c=tolower(c);
	    arr[c-'a']--;
	}
}
	for(i=0;i<26;i++){
	  if(arr[i]!=0){
	  printf("The words are not anagrams.");
	  return 0;}
}
	printf("The words are anagrams.");
	return 0;
}
