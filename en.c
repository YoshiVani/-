#include <stdio.h>
#define PAI 3.1415926535897932384626433832795
float sqr( float x );
int main() {
float r,s,l,S;
printf("radius = ");
scanf("%f",&r);
s=PAI*sqr(r);
l=PAI*2*r;
S=4*PAI*sqr(r);
printf("\n");
printf("area of the circle : %f\n",s);
printf("circumferencee : %f\n",l);
printf("surface area of sphere : %f\n",S);
printf("\n");
return 0;
}
float sqr( float x ) {
return (x*x);
}
