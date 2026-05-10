#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef int QueueElementType;
#include "queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void YangHuiSanjiao(int N)
{
	int i,n,temp,x;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);
	printf("杨辉三角的前%d行数据为：\n",N);
	for(n=2;n<=N;n++){
		for(i=1;i<=N-n;i++) {
			printf("  ");}
		EnterQueue(&Q,1);
		for(i=1;i<=n-2;i++){
			DeleteQueue(&Q,&temp);
			GetHead(&Q,&x);
			printf("  %3d",temp);
			temp=temp+x;
			EnterQueue(&Q,temp);
		}
		DeleteQueue(&Q,&x);
		printf("  %3d",x);
		EnterQueue(&Q,1);
		printf("\n");
	}
	
	while(!IsQueueEmpty(&Q)){
		DeleteQueue(&Q,&x);
		printf("%3d  ",x);
	}
	printf("\n\n");  
}
int main(int argc, char *argv[]) {
	YangHuiSanjiao(5);
	YangHuiSanjiao(10);
	return 0;
}
