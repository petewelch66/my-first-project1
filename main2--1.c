#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType elem[MAXSIZE];
	int last;
}SeqList;

void Dayin(){
	printf("  欢迎来到顺序表系统! \n");
	printf("输入数字即可实现以下功能：\n"); 
	printf("1:实现顺序表的初始化\n");
	printf("2:输出顺序表中各元素的值\n");
	printf("3:在顺序表中插入数据元素\n");
	printf("4:删除数据元素\n");
	printf("5:求顺序表的长度\n");
	printf("6:顺序表的逆置\n");
	printf("7:顺序表的按值从小到大排序\n");
	printf("8:合并有序的两个顺序表\n");
	printf("9:有序插入一个数\n");
	printf("10:删除连续的几个元素\n"); 
	printf("11:奇偶排序\n");
	printf("0:退出顺序表系统\n\n");
}

void InitList(SeqList *L)
{
	L->last=-1;
}//顺序表初始化 

void bianli(SeqList *L)
{
	int i=0;
	if(L->last==-1){
		printf("该顺序表为空表！"); }
	else{
		while(i<=L->last){
			printf("%d ",L->elem[i]);
			i++;}
	}
	printf("\n\n");
}//遍历顺序表 

int InsList(SeqList *L,int i,ElemType e)
{
	int k;
	if((i<1)||(i>L->last+2)){
		printf("插入位置不合理！\n");
		return 0;}
	if(L->last>=MAXSIZE-1){
		printf("表已满，无法插入！\n");
		return 0;}
	for(k=L->last;k>=i-1;k--){
		L->elem[k+1]=L->elem[k];}
	L->elem[i-1]=e;
	L->last++;
	return 1;
}//插入元素 

int DelList(SeqList *L,int i,ElemType *e)
{
	int k;
	if (L->last==-1) {
		printf("顺序表为空表！"); 
        return 0;}
	if((i<1)||(i>L->last+1)){
		printf("删除位置不合理！\n");
		return 0;}
	*e=L->elem[i-1];
	for(k=i;k<=L->last;k++){
		L->elem[k-1]=L->elem[k];}
	L->last--;
	return 1;
}//删除元素 

int ListLength(SeqList *L)
{ 	
	return (L->last+1);
}//顺序表的长度 

void RevList(SeqList *L)
{
	int i,j;
	if(L->last==-1) {
		printf("顺序表为空表！"); }
	for(i=0,j=L->last;i<j;i++,j--){
		int temp=L->elem[j];
		L->elem[j]=L->elem[i];
		L->elem[i]=temp;}
}//顺序表的逆置 

void bubblesort(SeqList *L)
{
	int i,j;
	int temp;
	if(L->last==-1) {
		printf("顺序表为空表！"); }
	for(i=0;i<L->last;i++){
		for(j=0;j<L->last-i;j++){
			if(L->elem[j]>L->elem[j+1]){
				temp=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=temp;}
		}
	}
}//顺序表元素排序 
void SelectSort(SeqList *L)
{
    int i,j,min,temp;
    if(L->last==-1) {
		printf("顺序表为空表！\n");
		return;
	}
    for(i=0;i<=L->last;i++)
    {
        min=i;
        for(j=i+1;j<=L->last;j++){
            if(L->elem[j]<L->elem[min])
                min = j;
        }
        temp=L->elem[i];
        L->elem[i]=L->elem[min];
        L->elem[min]=temp;
    }
    printf("简单选择排序完成！\n");
}

void InsertSort(SeqList *L)
{
    int i,j,temp;
    if(L->last==-1) {
		printf("顺序表为空表！\n");
		return;
	}
    for(i=1;i<=L->last;i++)
    {
        temp=L->elem[i];
        j=i-1;
        while(j>=0&&L->elem[j]>temp){
            L->elem[j+1]=L->elem[j];
            j--;
        }
        L->elem[j+1]=temp;
    }
    printf("直接插入排序完成！\n");
}

void mergeList(SeqList *LA,SeqList *LB,SeqList *LC)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<=LA->last && j<=LB->last){
		if(LA->elem[i]<=LB->elem[j]){
			LC->elem[k]=LA->elem[i];
			i++;
			k++;}
		else{
			LC->elem[k]=LB->elem[j];
			j++;
			k++;}
	}
	while(i<=LA->last){
		LC->elem[k]=LA->elem[i];
		i++;
		k++;}
	while(j<=LB->last){
		LC->elem[k]=LB->elem[j];
		j++;
		k++;}
	LC->last=k-1;
}//合并两个按序排列的顺序表

int yxcr(SeqList *L,ElemType e){
	int i=0,j; 
	if(L->last>=MAXSIZE-1){
		printf("表已满，无法插入！");
		return 0;}
	while(i<=L->last&&L->elem[i]<e) {
        i++;}
    for(j=L->last;j>=i;j--) {
        L->elem[j+1]=L->elem[j];   }
	L->elem[i]=e;
	L->last++;
	return 1;
}//有序插入一个数 

int lxsc(SeqList *L,int i,int k){
	int l;
	if(L->last==-1) {
		printf("顺序表为空表！"); 
        return 0;}
	if((i+k-1>L->last+1)||(i>L->last+1)||(i<1)||(k<1)){
		printf("删除失败！");
		return 0;}
	for(l=i+k-1;l<=L->last;l++){
		L->elem[l-k]=L->elem[l];}
	L->last=L->last-k;
	return 1;
}

int jopx(SeqList *L){
	if (L->last==-1) {
		printf("顺序表为空表！"); 
        return 0;}
    int left=0;                
    int right=L->last;         
    ElemType temp;               

    while(left<right) {
        while (left<right&&L->elem[left]%2!=0) {
            left++;}
        while (left<right&&L->elem[right]%2==0) {
            right--;}
        if (left<right) {
            temp=L->elem[left];
            L->elem[left]=L->elem[right];
            L->elem[right]=temp;
            left++;
            right--;}
    }
    return 1;
}

int main(int argc, char *argv[]) {
	
	int a,b,c,fanhui;
	ElemType e;
	SeqList L,L1,L2;
	InitList(&L);
	InitList(&L1);
	InitList(&L2);
	L1.elem[0]=100;
	L1.elem[1]=0;
	L1.elem[2]=50;
	L1.elem[3]=25;
	L1.last=3;
	Dayin();
	while(1){
		printf("\n请输入一个数字：");
		scanf("%d",&a);
		switch(a){
			case 1:
				InitList(&L);
				L.elem[0]=0;
				L.elem[1]=20;
				L.elem[2]=1;
				L.elem[3]=15;
				L.elem[4]=10;
				L.last=4;
				printf("顺序表已初始成功！\n\n");
				break;
			case 2:
				bianli(&L);
				break;
			case 3:
				printf("请输入你要插入的位置："); 
				scanf("%d",&b);
				printf("请输入你要插入的数字：");
				scanf("%d",&c);
				fanhui=InsList(&L,b,c);
				if(fanhui){
				bianli(&L);}
				break;
			case 4:
				printf("请输入你要删除的数据元素位置：");
				scanf("%d",&b);
				fanhui=DelList(&L,b,&e);
				if(fanhui){
				bianli(&L);}
				break;
			case 5:
				fanhui=ListLength(&L);
				printf("顺序表的长度为：%d\n",fanhui); 
				break;
			case 6:
				RevList(&L);
				printf("顺序表逆置的结果为：");
				bianli(&L);
				break;
			case 7:
				printf("请输入数字(1:冒泡排序 2:简单选择排序 3:直接插入排序)：");
				scanf("%d",&b);
				switch(b){
					case 1: 
						bubblesort(&L); 
						break;
					case 2: 
						SelectSort(&L); 
						break;
					case 3: 
						InsertSort(&L); 
						break;
					default: printf("输入错误！\n"); continue;
				}
				printf("顺序表排序的结果为："); 
				bianli(&L);
				break;
			case 8:
				bianli(&L1);
				bubblesort(&L);
				bubblesort(&L1);
				mergeList(&L,&L1,&L2);
				printf("两个顺序表合并的结果为：");
				bianli(&L2);
				break;
			case 9:
				bubblesort(&L);
				printf("请输入你要插入的数字：");
				scanf("%d",&c);
				fanhui=yxcr(&L,c);
				if(fanhui){
					bianli(&L);}
				break;
			case 10:
				printf("请输入你要删除的数字开始位置：");
				scanf("%d",&b);
				printf("请输入你要删除的数字数量：");
				scanf("%d",&c);
				fanhui=lxsc(&L,b,c);
				if(fanhui){
					bianli(&L);}
				break;
			case 11:
				fanhui=jopx(&L);
				if(fanhui){
					bianli(&L);}
				break;
			case 0:
				printf("您已成功退出顺序表管理系统！\n"); 
				return 0;
			default: 
				printf("输入错误，请输入0-11的数字！\n");
		}
	}
	return 0;
}

