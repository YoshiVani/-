#include <stdio.h>
#define PAI 3.1415926535897932384626433832795

float sqr(float x);

int main(){
float r,S;
printf("radius = ");
scanf("%f",&r);
S=PAI*sqr(r);
printf("S = %f\n",S);
return 0;
}

float sqr(float x){
return(x*x);
}