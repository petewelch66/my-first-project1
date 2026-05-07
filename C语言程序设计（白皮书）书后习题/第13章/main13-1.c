#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	char smallest_word[20],largest_word[20];
	char arr[20],c;
	
	printf("Enter word: ");
	i=0;
	  while((c=getchar())!='\n' && i<19){
	  	arr[i++]=c;
	  }
	  arr[i]='\0';
	strcpy(smallest_word,arr);
	strcpy(largest_word,arr);
	
	while (1){
	printf("Enter word: ");
	i=0;
	  while((c=getchar())!='\n' && i<19){
	  	arr[i++]=c;
	  }
	arr[i]='\0';
	
	int len;
	len=strlen(arr);
	if (len==4){
	break;
	}
	if (strcmp(arr,smallest_word)<0)
	strcpy(smallest_word,arr);
	if (strcmp(arr,largest_word)>0)
	strcpy(largest_word,arr);

}
    printf("Smallest word: %s\n",smallest_word);
    printf("Largest word: %s\n",largest_word);
	return 0;
}
