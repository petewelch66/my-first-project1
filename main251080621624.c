#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#define ZIMUSHU 26
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fp;  //定义文件指针 
	int ch,chh;
	int i=0,jishu[ZIMUSHU]={0}; //定义数组用于字母计数 
	
	
    if(argc!=2){  //检查参数 
    	printf("Too many arguments.\n");
    	exit(1);
	}
	if ((fp=fopen(argv[1],"r"))==NULL){  //打开文件 
		printf("%s can't be opened\n",argv[1]);
		exit(1);
	}
	while ((ch = fgetc(fp)) != EOF) {  //EOF为文件结束标志 
	  if(isalpha(chh=tolower(ch))){ //都改为小写 
	  	jishu[chh-'a']++; //chh-'a 正好对应字母位置和数组元素 
	  }
}
    for(i=0;i<ZIMUSHU;i++){
    	printf("%d",jishu[i]);
	}
	printf("\n");
	
	if(fclose(fp)!=0){  //关闭文件 
		printf("Error in closing the file %s.\n",argv[1]);
		exit(1);
	}
	return 0;
}
