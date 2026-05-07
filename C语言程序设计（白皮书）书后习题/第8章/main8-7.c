#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int arr[5][5];
	int i,j;
	int total;
	
	for (j=0;j<5;j++){
	printf("Enter row %d: ",j+1);
	for (i=0;i<5;i++)
	  scanf("%d",&arr[j][i]);
}
    
    printf("Row totals: ");
    for (i=0;i<5;i++){
      total=0;
      for (j=0;j<5;j++){
      total=total+arr[i][j];
}
	printf("%d ",total);
}
    printf("\n");
	printf("Column totals: ");
    for (i=0;i<5;i++){
      total=0;
      for (j=0;j<5;j++){
      total=total+arr[j][i];
}
	printf("%d ",total);
}
	return 0;
}
