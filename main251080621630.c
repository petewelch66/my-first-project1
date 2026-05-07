//比较两个分数的大小 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d,z; 
	printf("请按格式输入两个分数(格式：a/b c/d)：");
	scanf("%d/%d %d/%d",&a,&b,&c,&d); 
	if (b==0 ||d==0){
		printf("分母不能为零！请重新输入！\n");
		return 1;   //分母为零的情况 
	}
	z=a*d-b*c;  //两分数相减，看分子是否大于0 
	printf("比较结果如下：\n");
    if(z>0)
      printf("%d/%d > %d/%d",a,b,c,d);  //第一个分数大 
	else if (z==0)
	  printf("%d/%d = %d/%d",a,b,c,d);  //两个分数一样大 
	else
	  printf("%d/%d < %d/%d",a,b,c,d);  //第二个分数大 
	return 0;
}
