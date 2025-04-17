#include <stdio.h>
#define LOW -10
#define MAX 200
int main(){
	int c,n,max,ten,min,good,bad;
	n=0;
	max=LOW;
	min = MAX;
	float heikin,sum;
	sum=0;
	n = 0;
	good=0;
	bad=0;
	while(1){
		printf("point : %d\n",n);
		c=scanf("%d",&ten);
		if (c == EOF ) break;
		if(max<ten)max=ten;
		if(min>ten)min = ten;
		sum += ten;
		n++;
		if(80<=ten)good++;
		if (60>ten)bad++;		
	}
	heikin=sum/n;
	printf("\n");
	printf("number of students : %d\n",n);
	printf("total : %f\n",sum);
	printf("average : %f\n",heikin);
	printf("Max score : %d\n",max);
	printf("Min score : %d\n",min);
	printf("good score amount : %d\n",good);
	printf("bad score amount : %d\n",bad);
	printf("\n");
	return 0;
}