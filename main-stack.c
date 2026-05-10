#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Stack_Size 100
typedef char ElemType;
#include "stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Match(char a,char b){
	if((a=='('&&b==')')||
	  (a=='{'&&b=='}')||
	  (a=='['&&b==']'))
		return 1;
	else
		return 0;
}
void BracketMatch(char *str)
{
	SeqStack S;
	int i;
	char ch;
	InitStack(&S);
	for(i=0;str[i]!='\0';i++){
		switch(str[i]){
			case '(':
			case '[':
			case '{':
				Push(&S,str[i]);
				break;
			case ')':
			case ']':
			case '}':
				if(IsStackEmpty(&S)){
					printf("\n右括号多余！\n"); 
					return; 
				}
				else{
					GetTop(&S,&ch);
					if(Match(ch,str[i]))
						Pop(&S,&ch);
					else{
						printf("\n对应左右括号不同类！\n");
						return;
					}
				}
		}
	}
	if(IsStackEmpty(&S)){
		printf("\n括号匹配成功！\n");
	}
	else{
		printf("\n左括号多余！\n");
	}
}

int Prior(char op){
	if(op=='*'||op=='/') return 2;
	if(op=='+'||op=='-') return 1;
	return 0;
}
void zhongtohou(char zhong[],char hou[]){
	SeqStack S;
	InitStack(&S);
	int i=0,j=0;
	char ch,topch;
	while((ch=zhong[i++])!='\0'){
		if(isalnum(ch)){
			hou[j++]=ch;
		}
		else if(ch=='('){
			Push(&S,ch);
		}
		else if(ch==')'){
			while(GetTop(&S,&topch)&&topch!='('){
				Pop(&S,&hou[j++]);
			}
			Pop(&S,&topch);
		}
		else{
			while(GetTop(&S,&topch)&&Prior(topch)>=Prior(ch)){
				Pop(&S,&hou[j++]);
			}
			Push(&S,ch);
		}
	}
	while(!IsStackEmpty(&S)){
		Pop(&S,&hou[j++]);
	}
	hou[j]='\0';
}
int main(int argc, char *argv[]) {
	ElemType str[Stack_Size];
	printf("————括号匹配问题————\n");
	printf("请输入字符串：");
	scanf("%s",str);
	BracketMatch(str);
	
	ElemType zhong[Stack_Size],hou[Stack_Size];
	printf("\n————表达式转换问题————\n");
	printf("请输入中缀表达式：");
	scanf("%s",zhong);
	zhongtohou(zhong,hou);
	printf("\n转换成后缀表达式为：%s",hou);
	return 0;
}

