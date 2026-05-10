#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct number{
	int numerator;
	int denominator;
	}RatNum;
	
void print(){
	printf("	有理数的基本运算	\n");
	printf("***按0：输入两个有理数***\n");
	printf("***按1：两个有理数相加***\n");
	printf("***按2：两个有理数相减***\n");
	printf("***按3：两个有理数相乘***\n");
	printf("***按4：两个有理数相除***\n");
	printf("***按5：退出程序***\n\n");
}
 
int gys(int a,int b){
	while(b!=0){
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

void yuefeng(RatNum *p1){
	int temp=gys(p1->numerator,p1->denominator);
	if (temp!=0){
	p1->numerator=p1->numerator/temp;
	p1->denominator=p1->denominator/temp;}
	if(p1->denominator < 0){
        p1->numerator *= -1;
        p1->denominator *= -1;}
}

void create(RatNum *p1,RatNum *p2){
	printf("请输入两个有理数：\n");
	scanf("%d/%d %d/%d",&p1->numerator,&p1->denominator,&p2->numerator,&p2->denominator);
	if(p1->denominator== 0 || p2->denominator==0){
        printf("分数分母不能为0！\n");
        return;}
    yuefeng(p1);
	yuefeng(p2);
}

void xiangjia(RatNum *p1,RatNum *p2,RatNum *p3){
	p3->numerator=(p2->denominator)*(p1->numerator)+(p2->numerator)*(p1->denominator);
	p3->denominator=(p1->denominator)*(p2->denominator);
}

void xiangjian(RatNum *p1,RatNum *p2,RatNum *p3){
	p3->numerator=(p2->denominator)*(p1->numerator)-(p2->numerator)*(p1->denominator);
	p3->denominator=(p1->denominator)*(p2->denominator);
}

void xiangchen(RatNum *p1,RatNum *p2,RatNum *p3){
	p3->numerator=(p1->numerator)*(p2->numerator);
	p3->denominator=(p1->denominator)*(p2->denominator);
}

void xiangchu(RatNum *p1,RatNum *p2,RatNum *p3){
	if(p2->numerator == 0){
        printf("除数不能为0！\n");
        return;
    }
	p3->numerator=(p1->numerator)*(p2->denominator);
	p3->denominator=(p1->denominator)*(p2->numerator);
}

void dayin(RatNum *p1,RatNum *p2,RatNum *p3,char c){
	if (p3->numerator==0){
	printf("结果为：%d/%d %c %d/%d = 0\n\n",p1->numerator,p1->denominator,c,p2->numerator,p2->denominator);
	}
	else if((p3->numerator!=0)&&(p3->denominator==1)){
	printf("结果为：%d/%d %c %d/%d = %d\n\n",p1->numerator,p1->denominator,c,p2->numerator,p2->denominator,p3->numerator);
	}
	else{
	printf("结果为：%d/%d %c %d/%d = %d/%d\n\n",p1->numerator,p1->denominator,c,p2->numerator,p2->denominator,p3->numerator,p3->denominator);
}
}

int main(int argc, char *argv[]) {
	RatNum NUM1,NUM2,NUM3;
	
	int a;
	print();
	while(1){
		scanf("%d",&a);
		switch(a){
			case 0:
				create(&NUM1,&NUM2);
				printf("已录入成功！\n\n"); 
				break;
			case 1:
				xiangjia(&NUM1,&NUM2,&NUM3);
				yuefeng(&NUM3);
				dayin(&NUM1,&NUM2,&NUM3,'+');
				break;
			case 2:
				xiangjian(&NUM1,&NUM2,&NUM3);
				yuefeng(&NUM3);
				dayin(&NUM1,&NUM2,&NUM3,'-');
				break;
			case 3:
				xiangchen(&NUM1,&NUM2,&NUM3);
				yuefeng(&NUM3);
				dayin(&NUM1,&NUM2,&NUM3,'*');
				break;
			case 4:
				xiangchu(&NUM1,&NUM2,&NUM3);
				yuefeng(&NUM3);
				dayin(&NUM1,&NUM2,&NUM3,'/');
				break;
			case 5:
				printf("您已成功退出程序!\n");
				return 0;
			default:
				printf("输入数字无效，请重新输入！\n");
				break;
	}
}
	return 0;
}
