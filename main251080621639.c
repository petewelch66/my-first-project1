// 学生成绩管理系统
//1) 输入 n 个学生的学号，姓名，高等数学、大学物理、英语和 C 语言四门课程的成绩。
//2) 计算每门课平均分数并输出；
//3) 按照某类课程的成绩高低排序；
//4) 找出每门课最高分的同学学号和姓名（如果最高分有多名同学，都输出）。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0; //记录学生数量 
typedef struct message 
{
	int number;
	char name[20];
	int gdsx; 
	int dxwl; 
	int yy;  
	int cyu; 
}GRADE;  //定义结构体记录学生的信息 
GRADE arr[99];  //便于录入多个学生的信息 

void pf() //打印功能页面 
{
	printf("*  *  *  欢 迎 来 到 学 生 成 绩 管 理 系 统  *  *  *\n");
	printf("*  *  *  *  功 能 一：  录 入 学 生 成 绩  *  *  *  *\n");
	printf("*  *  *  *  功 能 二：  计 算 科 目 均 分  *  *  *  *\n");
	printf("*  *  *  *  功 能 三：  按 照 成 绩 排 序  *  *  *  *\n");
	printf("*  *  *  *  功 能 四：  找 出 高 分 同 学  *  *  *  *\n");
	printf("*  *  *  *  功 能 五：  修 改 学 生 成 绩  *  *  *  *\n");
	printf("*  *  *  *  功 能 六：  删 除 学 生 成 绩  *  *  *  *\n");
	printf("*  *  *  *  功 能 七：  按 序 输 出 成 绩  *  *  *  *\n");
	printf("*  *  *  *  功 能 八：  退 出 管 理 系 统  *  *  *  *\n");
}

void scann()  //录入学生信息 
{
	int i;
	printf("学号 姓名 高等数学 大学物理 大学英语 C语言(输入0结束)\n");
	for(i=count;i<99;i++){
		scanf("%d",&arr[i].number);
		if(arr[i].number==0)
		  break; //输入0停止 
		else
		scanf("%s%d%d%d%d",arr[i].name,&arr[i].gdsx,&arr[i].dxwl,&arr[i].yy,&arr[i].cyu);
		count++;
	}
	printf("已录入成功！\n\n"); 
}

void average()  //计算平均分 
{
	int i;
	if (count==0){
	printf("您尚未录入成绩! \n\n");
	return;
}
	int sum1=0,sum2=0,sum3=0,sum4=0;
	for(i=0;i<count;i++){
		sum1=sum1+arr[i].gdsx;
		sum2=sum2+arr[i].dxwl;
		sum3=sum3+arr[i].yy;
		sum4=sum4+arr[i].cyu;
	} 
	printf("高等数学平均分为：%.1f分\n",(float)sum1/count);  //强制转化为浮点数，使成绩更精确 
	printf("大学物理平均分为：%.1f分\n",(float)sum2/count);
	printf("大学英语平均分为：%.1f分\n",(float)sum3/count);
	printf("C语言平均分为：%.1f分\n\n",(float)sum4/count);
}

void paixu()  //对某门课成绩进行排序 
{
	char ch,kemu[10]={0};
	int i=0,j=0,flag=0;  //用flag来标记科目 
	GRADE newarr[99];
	if (count==0){
	printf("您尚未录入成绩！\n\n");
	return;
}
    printf("您要排序的科目是：");
    getchar(); //录入换行符，防止直接打印下面的内容 
    fgets(kemu,sizeof(kemu),stdin);
    kemu[strcspn(kemu, "\n")] = '\0'; //去掉换行符 
    
	if(strcmp(kemu,"高等数学")==0)
	  flag=1;
	else if(strcmp(kemu,"大学物理")==0) 
	  flag=2;
	else if(strcmp(kemu,"大学英语")==0)
	  flag=3;
	else if(strcmp(kemu,"C语言")==0)
	  flag=4;
	else {
		printf("未找到%s科目！\n",kemu);
		return;
	}
	
	for (i=0; i<count; i++) 
	{
    newarr[i] = arr[i];  //拷贝每一个结构体，防止后续操作改动原数据 
    }
	
	for (i=0;i<count-1;i++){  //冒泡排序 
		for (j=0;j<count-1-i;j++){
			int cj1=0,cj2=0;  //相邻两个同学的成绩 
			switch(flag){
			case 1:cj1=newarr[j].gdsx; cj2=newarr[j+1].gdsx; break;
			case 2:cj1=newarr[j].dxwl; cj2=newarr[j+1].dxwl; break;
			case 3:cj1=newarr[j].yy; cj2=newarr[j+1].yy; break;
			case 4:cj1=newarr[j].cyu; cj2=newarr[j+1].cyu; break;}
		if(cj1<cj2){ //高分在前 
			GRADE jiaohuan=newarr[j];
			newarr[j]=newarr[j+1];
			newarr[j+1]=jiaohuan;
		}
		  
		}
	}
	printf("\n%s成绩从高到低排序如下： \n",kemu);
	printf("\n学号\t姓名\t成绩\n");
	for(i=0;i<count;i++){
		printf("%d\t%s\t",newarr[i].number,newarr[i].name);
		switch(flag){
		case 1:printf("%d\n",newarr[i].gdsx); break;  //根据科目来打印相应的成绩 
		case 2:printf("%d\n",newarr[i].dxwl); break;
		case 3:printf("%d\n",newarr[i].yy); break;
		case 4:printf("%d\n",newarr[i].cyu); break;
		printf("\n");
	}
	}
	printf("\n");
}

void find() {  //找出每门课最高分 
    if (count == 0) {
        printf("您尚未录入成绩！\n\n");
        return;
    }
    int i;
    int maxgdsx = arr[0].gdsx;  //起始值为第一个学生的成绩 
    int maxdxwl = arr[0].dxwl;  
    int maxyy = arr[0].yy;      
    int maxcyu = arr[0].cyu;    

    for (i = 1; i < count; i++) {
        if (arr[i].gdsx > maxgdsx) 
            maxgdsx = arr[i].gdsx;
        if (arr[i].dxwl > maxdxwl) 
            maxdxwl = arr[i].dxwl;
        if (arr[i].yy > maxyy) 
            maxyy = arr[i].yy;
        if (arr[i].cyu > maxcyu) 
            maxcyu = arr[i].cyu;
    }
    printf("每门课最高分信息 \n\n");
    printf("高等数学最高分：%d\n", maxgdsx);
    for (i = 0; i < count; i++) {
    if (arr[i].gdsx == maxgdsx) {  //考虑同分情况 
        printf("学号:%d，姓名:%s\n", arr[i].number, arr[i].name);
    }
}
    printf("\n大学物理最高分：%d\n", maxdxwl);
    for (i = 0; i < count; i++) {
    if (arr[i].dxwl == maxdxwl) {
        printf("学号:%d，姓名:%s\n", arr[i].number, arr[i].name);
    }
}
    printf("\n大学英语最高分：%d\n", maxyy);
    for (i = 0; i < count; i++) {
    if (arr[i].yy == maxyy) {
        printf("学号:%d，姓名:%s\n", arr[i].number, arr[i].name);
    }
}
    printf("\nC语言最高分：%d\n", maxcyu);
    for (i = 0; i < count; i++) {
    if (arr[i].cyu == maxcyu) {
        printf("学号:%d，姓名:%s\n", arr[i].number, arr[i].name);
    }
}
    printf("\n\n");
}

void change()  //修改学生成绩 
{
	int a,c,flag=0; //用flag来标记是否找到该名学生 
	if (count==0){
	printf("您尚未录入成绩！\n\n");
	return;
}
	printf("您要修改的学生学号为：");
	scanf("%d",&a);
	for(c=0;c<count;c++) {
		if (arr[c].number==a){
	    printf("请您修改：\n学号 姓名 高等数学 大学物理 大学英语 C语言\n");
	    scanf("%d%s%d%d%d%d",&arr[c].number,arr[c].name,&arr[c].gdsx,&arr[c].dxwl,&arr[c].yy,&arr[c].cyu);
	    printf("修改成功！\n\n");
	    flag=1;
		break;}
	}
	if(flag==0){
	printf("未找到该名学生！\n\n");
	return;}
}

void dele()  //删除学生成绩 
{
	int a,c,i,flag=0; //用flag来标记是否找到该名学生 
	if (count==0){
		printf("您尚未录入成绩！\n\n");
		return; 
	}
	printf("您要删除的学生学号为：");
	scanf("%d",&a);
	for(c=0;c<count;c++) {
		if (arr[c].number==a){
			flag=1;
	      for (i=c;i<count-1;i++){
	      	arr[i]=arr[i+1];  //数组元素前移 
		  }
		count--;
	    printf("删除成功！\n\n");
		break;}
	}
	if(flag==0){
	printf("未找到该名学生！\n\n");
	return;}
	
}

void print()  //打印学生成绩 
{
	int b;
	if (count==0){
		printf("您尚未录入成绩！\n\n"); 
		return;
	}
	printf("学号\t姓名\t高等数学\t大学物理\t大学英语\tC语言\n");
	for (b=0;b<count;b++)
	{
	  printf("%d\t%s\t%d\t%d\t%d\t%d\n\n",arr[b].number,arr[b].name,arr[b].gdsx,arr[b].dxwl,arr[b].yy,arr[b].cyu);
	}
}

void et()  //退出成绩管理系统 
{
	printf("您已成功退出系统！");
	exit(0);
}

int main(int argc, char *argv[]) {
	int jishu;
	pf();
	while(1){
	printf("请输入：");
	scanf("%d",&jishu);
	switch(jishu){
		case 1: scann();break;
		case 2: average();break;
		case 3: paixu();break;
		case 4: find();break;
	    case 5: change();break;
		case 6: dele();break;
		case 7: print();break;
		case 8: et();break;
		default: printf("输入数字错误！\n\n"); break;
	}
}
	return 0;
}
