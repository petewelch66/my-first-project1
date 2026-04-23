#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void find_closest_flight(int desired_time,int *departure_time,int *arrival_time)
{
	if(desired_time<(615)/2){
		*departure_time=21*60+45;
		*arrival_time=23*60+58;
	}
	else if(desired_time<(8*60+9*60+43)/2){
		*departure_time=8*60;
		*arrival_time=11*60+58;
	}
	else if(desired_time<(9*60+43+11*60+19)/2){
		*departure_time=9*60+43;
		*arrival_time=11*60+52;
	}
	else if(desired_time<(11*60+19+12*60+47)/2){
		*departure_time=11*60+19;
		*arrival_time=13*60+31;
	}
	else if(desired_time<(12*60+47+14*60)/2){
		*departure_time=12*60+47;
		*arrival_time=15*60;
	}
	else if(desired_time<(14*60+15*60+45)/2){
		*departure_time=14*60;
		*arrival_time=16*60+8;
	}
	else if(desired_time<(15*60+45+19*60)/2){
		*departure_time=15*60+45;
		*arrival_time=17*60+55;
	}
	else if(desired_time<(19*60+21*60+45)/2){
		*departure_time=19*60;
		*arrival_time=21*60+20;
	}
	else{
		*departure_time=21*60+45;
		*arrival_time=23*60+58;
	}
}
int main(int argc, char *argv[]) {
	int time,dt,at;
	int h,m;
	printf("Enter your time: ");
	scanf("%d:%d",&h,&m);
	time=h*60+m;
	find_closest_flight(time,&dt,&at);
	if(dt>=13*60)
	printf("Your departure time is:%d:%02d p.m.\n",(dt/60)-12,dt%60);
	else if(dt>=12*60)
	printf("Your departure time is:%d:%02d p.m.\n",(dt/60),dt%60);
	else
	printf("Your departure time is:%d:%02d a.m.\n",(dt/60),dt%60);
	
	if(at>=13*60)
	printf("Your arrival time is:%d:%02d p.m.",(at/60)-12,at%60);
	else if(at>=12*60)
	printf("Your arrival time is:%d:%02d p.m.",(at/60),at%60);
	else
	printf("Your arrival time is:%d:%02d a.m.",(at/60),at%60);
	 
	return 0;
}
