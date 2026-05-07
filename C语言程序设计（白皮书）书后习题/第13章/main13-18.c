#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char Month[][12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int main(int argc, char *argv[]) {
	int month,day,year;
	
	printf("Enter a date(mm/dd/yyyy): ");
	scanf("%d/%d/%d",&month,&day,&year);
	printf("You entered the date %s %d, %d",Month[month-1],day,year);
	return 0;
}
