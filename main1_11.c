#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	float realpart;
	float imagpart;
}Complex; 

Complex create(float x,float y);
Complex add(Complex z1,Complex z2);

Complex create(float x,float y)
{
	Complex z;
	z.realpart=x;
	z.imagpart=y;
	return(z);
}

Complex add(Complex z1,Complex z2)
{
	Complex sum;
	sum.realpart=z1.realpart+z2.realpart;
	sum.imagpart=z1.imagpart+z2.imagpart;
	return(sum);
}

int main(int argc, char *argv[]) {
	float a,b;
	Complex c1,c2,c3;
	printf("\n\n\n Input realpart and imagpart: ");
	scanf("%f%f",&a,&b);
	c1=create(a,b);
	printf("\n\n\n Input realpart and imagpart: ");
	scanf("%f%f",&a,&b);
	c2=create(a,b);
	c3=add(c1,c2);
	printf("\n\n c1==%f+%fi",c1.realpart,c1.imagpart);
	printf("\n\n c2==%f+%fi",c2.realpart,c2.imagpart);
	printf("\n\n c3==c1+c2==%f+%fi",c3.realpart,c3.imagpart);
	return 0;
}
