#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int i1,i2,i3,i4; //四个变量，用于分别计数 
void jishu(char arr[])
{
	int i;
	for(i=0;arr[i]!='\0';i++) //遍历字符串 
	{
		if (arr[i]=='\n')  //跳过换行符 
		continue;
		else if((arr[i]>='A'&&arr[i]<='Y')||(arr[i]>='a'&&arr[i]<='y')||arr[i]=='z'||arr[i]=='Z')
		i1++;
		else if(arr[i]>='0'&&arr[i]<='9')
		i2++;
		else if(arr[i]==' ')
		i3++;
		else i4++;
	}
}
int main(int argc, char *argv[]) {
	FILE* fp; //定义文件指针 
	char str[100];
	if(argc!=2) //检查参数 
	{
		printf("Too many arguments.\n");
		exit(1);
	}
	if((fp=fopen(argv[1],"r"))==NULL) //打开文件 
	{
		printf("%s can't be opened\n",argv[1]);
		exit(1);
	}
	
	fgets(str,sizeof(str),fp); //读取文件中的字符串 
	jishu(str);  
	printf("字母: %d\n数字: %d\n空格: %d\n其他符号: %d\n",i1,i2,i3,i4);
	if(fclose(fp)!=0){ //关闭文件 
		printf("Error in closing the file%s.\n",argv[1]);
		exit(1);
	}
	
	return 0;
}
