#include <stdio.h>

int main(){
for(int i=1;i<=20;i++){
	for(int j=1;j<=20;j++){
	int kuku=i*j;
	printf("%d * %d = %d\n",i,j,kuku);
	}
	puts("");
}
return 0;
}
