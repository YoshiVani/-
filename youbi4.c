#include <stdio.h>
long n1day(int,int,int);
long n2day(int,int,int);
int main(){
	int y1,m1,d1,y2,m2,d2;
	long n1,n2;
	while(printf("Y1 M1 D1,Y2 M2 D2 "),scanf("%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2)!=EOF){
		n1 =n1day(y1,m1,d1);
		n2 =n2day(y2,m2,d2);
		printf("number of days from %d %d %d to %d%d%d = %ld\n",y1,m1,d2,y2,m2,d2,n1-n2);
	}
	return 0;
}

long n1day(int iy1,int im1,int id1){
	long ny1,nm1;
	ny1 = iy1;
	nm1 = im1;
	if(im1 <= 2){
		ny1--;
		nm1+=12;
	}
	return (365*ny1+ny1/4-ny1/100+ny1/400+306*(nm1+1)/10+id1-428);
}
long n2day(int iy2,int im2,int id2){
	long ny2,nm2;
	ny2 = iy2;
	nm2 = im2;
	if(im2 <= 2){
		ny2--;
		nm2+=12;
	}
	return (365*ny2+ny2/4-ny2/100+ny2/400+306*(nm2+1)/10+id2-428);
}