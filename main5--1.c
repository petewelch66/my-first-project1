#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXLEN 40
typedef struct{
	char ch[MAXLEN];
	int len;
}SString;

void CreateStr(SString *s,char *str){
	int i=0;
	while(str[i]!='\0'&&i<MAXLEN){
		s->ch[i]=str[i];
		i++;
	}
	s->len=i;
}

void PrintStr(SString *s){
	int i;
	for(i=0;i<s->len;i++){
		printf("%c",s->ch[i]);
	}
	printf("\n");
}
int StrIndex(SString s,int pos,SString t){
	int i,j,start;
	if(t.len==0)  return 0;
	start=pos-1;
	i=start;
	j=0;
	while(i<s.len&&j<t.len){
		if(s.ch[i]==t.ch[j]) {i++;j++;}
		else{
			start++;
			i=start;
			j=0;
		}
	}
	if(j>=t.len) return (start+1);
	else return(-1);
}

void getnext(SString *T,int next[]){
	next[0]=-1;int j=-1;int i=0;
	while(i<T->len){
		if(T->ch[i]==T->ch[j]||j==-1){
			i++;j++;next[i]=j;
		}
		else j=next[j];
	}
}
void getnextval(SString *T, int nextval[]) {
    nextval[0]=-1;int j=0;int k=-1;
    while(j<T->len){ 
        if(k==-1||T->ch[j]==T->ch[k]){
            ++j; ++k;
            if(T->ch[j]!=T->ch[k]) nextval[j]=k;
            else nextval[j]=nextval[k];
        }
        else k=nextval[k];
    }
}

int IndexKMP(SString *s,SString *T,int pos,int nextval[]){
	int i=pos-1;int j=0;
	while(i<s->len&&j<T->len){
		if(s->ch[i]==T->ch[j])  {i++;j++;}
		else j=nextval[j];
	}
	if(j==T->len) return i-T->len+1;
	else return 0;
}

int main(int argc, char *argv[]) {
	SString s,t;
	int a,pos;
	int next[MAXLEN],nextval[MAXLEN];
	char arr[]="ababcabcacbab";
	char trr[]="abcac";
	CreateStr(&s,arr);
	CreateStr(&t,trr);
	printf("主串的内容为：");
	PrintStr(&s);
	printf("模式串的内容为：");
	PrintStr(&t);
	printf("请输入一个数字（1：简单匹配算法 2：KMP模式匹配算法）：");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("请输入开始匹配的位置pos：");
			scanf("%d",&pos);
			printf("从%d开始第一次位置位置序号为：%d",pos,StrIndex(s,pos,t));
			break;
		case 2:
			getnext(&t,next);
			getnextval(&t,nextval);
			printf("请输入开始匹配的位置pos：") ;
			scanf("%d",&pos);
			printf("从%d开始第一次位置位置序号为：%d",pos,IndexKMP(&s,&t,pos,nextval));
			break;
		default:
			printf("输入数字不在范围内！");
	}
	
	return 0;
}
