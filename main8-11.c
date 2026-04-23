#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char crr[15];
	int i;
	
	printf("Enter phone number: ");
	fgets(crr,15,stdin);
	printf("In numeric form: ");
	for (i=0; crr[i] != '\0' && crr[i] != '\n';i++){
		if (crr[i]>='A'&&crr[i]<='C')
		printf("%d",2);
		else if(crr[i]>='D' &&crr[i]<='F')
		printf("%d",3);
		else if(crr[i]>='G' &&crr[i]<='I')
		printf("%d",4);
		else if(crr[i]>='J' &&crr[i]<='L')
		printf("%d",5);
		else if(crr[i]>='M' &&crr[i]<='O')
		printf("%d",6);
		else if(crr[i]>='P' &&crr[i]<='S')
		printf("%d",7);
		else if(crr[i]>='T' &&crr[i]<='V')
		printf("%d",8);
		else if(crr[i]>='W' &&crr[i]<='Z')
		printf("%d",9);
		else printf("%c",crr[i]);
		
	}
	return 0;
}


