#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c,d,max,min;
	printf("Enter four integers:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
  if (a>=b)
      if (a>=c)
          if (a>=d)
              max=a;
          else
              max=d;
      else 
          if (c>=d)
              max=c;
          else
              max=d;
  else
      if (b>=c)
          if (b>=d)
              max=b;
          else
              max=d;
      else
          if (c>=d)
              max=c;
          else
              max=d;

            
  if (a<=b)
      if (a<=c)
          if (a<=d)
              min=a;
          else
              min=d;
      else 
          if (c<=d)
              min=c;
          else
              min=d;
  else
      if (b<=c)
          if (b<=d)
              min=b;
          else
              min=d;
      else
          if (c<=d)
              min=c;
          else
              min=d;
  
  printf("Largest:%d\n",max);
  printf("Smallest:%d",min);
  
	return 0;
}
