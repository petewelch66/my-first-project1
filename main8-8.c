#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int arr[5][5];
	int i,j;
	float total;
	int sum=0;
	int max,min;
	
	for (j=0;j<5;j++){
	printf("Enter student %d: ",j+1);
	for (i=0;i<5;i++)
	  scanf("%d",&arr[j][i]);
}
    
    printf("Row totals: ");
    for (i=0;i<5;i++){
      total=0;
      for (j=0;j<5;j++){
      total=total+arr[i][j];
}
	sum=sum+total;
	printf("%f ",total);
}
    printf("\n");
    printf("junfen1:%d\n",sum/5);
	printf("Column totals: \n");
    for (i=0;i<5;i++){
      total=0;
      max=0;
      min=0;
      max=arr[0][i];
      min=arr[0][i];
      for (j=0;j<5;j++){
      total=total+arr[j][i];
      if (max<arr[j][i])
      max=arr[j][i];
      if(min>arr[j][i])
      min=arr[j][i];
}
	printf("junfen2(%d):%f\n",i+1,total/5);
	printf("maxfen(%d):%d\n",i+1,max);
	printf("minfen(%d):%d\n\n",i+1,min);
}
	return 0;
}
