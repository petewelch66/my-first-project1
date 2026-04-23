#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  int a,b,c,d;

  printf("Enter a two-digit number :");
  scanf("%d",&a);

  b=a%10;
  c=a/10;
  d=b*10+c;
  
  printf("The reversal is :%d",d);

  return 0;
}
