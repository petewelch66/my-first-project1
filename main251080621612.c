//口袋里有红、黄、蓝、白、黑 5 种颜色的球若干个。每次从口袋中取出 3 个不同颜色的球，问有多少种取法。
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
enum qiu  
{
	red,
	yellow,
	blue,
	white,
	black
};   //枚举五种颜色的球 
int main(int argc, char *argv[]) {
	
	enum qiu q1,q2,q3;  //取三个球 
    int i=1; //记录多少种取法 
    char color[6][10]={"红色","黄色","蓝色","白色","黑色"};  //存储字符串，便于输出 
    
	for (q1=red;q1<=black;q1++){
		for (q2=red;q2<=black;q2++){
			for (q3=red;q3<=black;q3++){
				if (q1!=q2 && q2!=q3 && q1!=q3){ //三种不同颜色的球 
				  printf("组合%d：%s %s %s \t",i,color[q1],color[q2],color[q3]);
				  i++;
				if (i%2!=0)
				  printf("\n"); //隔两个换一次行 
			}
			}
		}
	} 
	return 0;
}
