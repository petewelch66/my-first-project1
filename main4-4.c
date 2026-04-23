#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  int a;

  printf("Enter a number between 0 and 32767 :");
  scanf("%d",&a);

  printf("In octal,your number is :%05o",a);

  return 0;
}
