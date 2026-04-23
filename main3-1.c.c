#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  int m,d,y;
  int sum;

  printf("%s","Enter a date (mm/dd/yyyy) :");
  scanf("%d/%d/%d",&m,&d,&y);
  sum=y*10000+m*100+d;
  printf("%d",sum);

  return 0;

	return 0;
}
