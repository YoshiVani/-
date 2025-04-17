#include<stdio.h>
#define LOW -10
#define MAX 200

int main(){
	int ten,n,sum,max,min;
	float heikin;
	max = LOW;
	min = MAX;
	sum = 0;
	n = 0;
	while(printf("point:\n"),scanf("%d",&ten)!=EOF){
		if(max<ten)max = ten;
		if(min>ten)min = ten;
		sum += ten;
		n++;
	}
	heikin=sum/n;
	printf("number=%d,Max=%d,Min=%d,average=%f",n,max,min,heikin);
	return 0;
}