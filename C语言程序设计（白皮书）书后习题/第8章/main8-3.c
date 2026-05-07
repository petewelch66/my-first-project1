#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int digit_seen[10]={0};
	int dig[100];
	int digit,flag=1;
	long n;
	int i;
	
	printf("Enter the numbers of your number:");
	scanf("%ld",&n);
	
	for (i=0;i<n;i++){
	  printf("Enter your number:");
	  scanf("%d",&dig[i]);
	  if (dig[i]<=0)
	    break;
}
	for (i=0;i<n;i++){
	  if (dig[i]<=0)
	  break;
	  while (dig[i]>0){
		digit=dig[i]%10;
		digit_seen[digit]++;
		dig[i]/=10;
	}
}
	for (digit=0;digit<10;digit++){
		if (digit_seen[digit]>1){
		  flag=2;
		  break;}
	}
	
	if (flag==1)
	  printf("No repeated digit\n");
	else if (flag==2)
	  printf("Repeated digit(s):");
	  
    for (digit=0;digit<10;digit++){
		if (digit_seen[digit]>1)
		  printf("%d ",digit);
	}
	
	return 0;
}
