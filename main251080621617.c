#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(int *row, int n) { //定义函数，逐行反转数组元素 
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int temp = row[left];
        row[left] = row[right];
        row[right] = temp;
        left++;
        right--;
    }
}

int main(int argc, char *argv[]) {
	int n,i,j;
	printf("您的方阵行数列数为： ");
	scanf("%d",&n);  //录入行列数 
	int arr[n][n];   //输入的原数组 
	int newarr[n][n]; //定义新数组，便于操作 

	printf("请输入您的方阵：\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%d",&arr[i][j]); //录入数组 
		}
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			newarr[j][i]=arr[i][j]; //行列号交换 
		}
	}
	
	for (i = 0; i < n; i++) {
        reverse(newarr[i], n);  //调用函数，反转数组 
    }
	
	printf("\n方阵顺时针旋转的最终结果为： \n");
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++){
			printf("%d ",newarr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
