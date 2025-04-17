#include<stdio.h>

int main(){
	int i,n,gankin;
	float r,manki1,mankih,sisu1,sisuh;
	printf("principal interest_rate years");
	scanf("%d%f%d",&gankin,&r,&n);
	for (sisu1=1.0,i=1;
	i<=n;
	i++)
	{sisu1*=1+r/100;
	}
	for (sisuh=1.0,i=1;
	i<=2*n;
	i++)
	{sisuh*=1+r/200;
	}
	manki1=gankin*sisu1;
	mankih=gankin*sisuh;
	printf("principal = %d\n",gankin);
	printf("interest rate = %fpercent\n",r);
	printf("years = %d\n",n);
	printf("maturity amount = %f,half of maturity amount = %f\n",manki1,mankih);
	return 0;
}