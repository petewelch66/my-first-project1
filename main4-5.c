#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5;
	int first_sum,second_sum,total;
	
	printf("Enter the eleven digits :");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d,&i1,&i2,&i3,&i4,&i5,&j1,&j2,&j3,&j4,&j5);
	
	first_sum=d+i2+i4+j1+j3+j5;
	second_sum=i1+i3+i5+j2+j4;
	total=3*first_sum+second_sum;
	
	printf("Check digit :%d\n",9-((total-1)%10));
	
	return 0;
}
