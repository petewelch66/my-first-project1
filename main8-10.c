#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int arr[8]={8*60,9*60+43,11*60+19,12*60+47,14*60,15*60+45,19*60,21*60+45};
	int brr[8]={10*60+16,11*60+52,13*60+31,15*60,16*60+8,17*60+55,21*60+20,23*60+58};
	int hour,minute;
	int rminute,raminute;
	int i;
	
	printf("Enter your time: ");
	scanf("%d:%d",&hour,&minute);
	rminute=hour*60+minute;
	if (rminute>arr[0]){
	  for (i=0;i<7;i++){
		if (rminute >arr[i]&&rminute<arr[i+1]){
			if(rminute-arr[i]>arr[i+1]-rminute){
				i++;
				break;
			}
			else
			    break;
		}
	}
}
    else
    {
    	if (480-rminute<rminute+1440-arr[7])
    	i=0;
    	else
    	i=7;
	}

    printf("start: %d:%02d\n",arr[i]/60,arr[i]%60);
    printf("arrive:%d:%02d",brr[i]/60,brr[i]%60);
	
	return 0;
}
