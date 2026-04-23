#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void pay_amount(int dollars,int *twenties,int *tens,int *fives,int *ones)
{
	*twenties=dollars/20;
	dollars=dollars-(*twenties)*20;
	*tens=dollars/10;
	dollars=dollars-(*tens)*10;
	*fives=dollars/5;
	*ones=dollars-(*fives)*5;
}
int main(int argc, char *argv[]) {
	int d,tw,t,f,o;
	printf("Enter a dollar amount: ");
	scanf("%d",&d);
	pay_amount(d,&tw,&t,&f,&o);
	printf("$20 bills: %d\n",tw);
	printf("$10 bills: %d\n",t);
	printf("$5 bills: %d\n",f);
	printf("$1 bills: %d",o);
	
	return 0;
}
