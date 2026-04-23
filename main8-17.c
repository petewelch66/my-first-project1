#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,n;
	
	printf("Enter size of magic square: ");
	scanf("%d",&n);
	int arr[99][99]={0};
	if (n%2==0)
	  return 0;
	int a=0;
	int b=n/2;
	arr[a][b]=1;
	for (i=2;i<=n*n;i++)
	{
		int aa,bb;
	  	aa=a-1;
	  	bb=b+1;
	  	if (aa<0)
	  	aa=n-1;
	  	if (bb>n-1)
	  	bb=0;
	  	if (arr[aa][bb] !=0){
	  	aa=a+1;
	  	bb=b;
	  	  if (aa<0)
	  	  aa=n-1;
	  }
	    a=aa;
	    b=bb;
		arr[a][b]=i;
	  }
	for (i=0;i<n;i++){
	  for(j=0;j<n;j++){
	    printf("%4d  ",arr[i][j]);
	}
	printf("\n");
}
	return 0;
}
