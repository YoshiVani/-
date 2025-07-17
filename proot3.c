#include <stdio.h>
#define SIZE 6
#define ERR 0.00000
#define LOW 1.0
#define HIGH 3.0
float proot( float *, int, float, float, float );
float polyf( float *, int, float );
int main() {
float a[SIZE], rir;
int i, n;
printf( "input polynomial data\n" );
n = SIZE - 1;
for ( i = 0; i < SIZE; i++ ) {
printf( "a[%2d]=", i);
if ( scanf( "%f", &a[i] ) == EOF ) {
n = i - 1;
break;
}
}
rir = 1.072;
printf("balance at term end %f\n", polyf(a, n, rir));
return 0;
}

float polyf( float *a, int i, float x ) {
if(i>0)return(polyf(a,i-1,x)*x+(*(a+i)));
else return *(a+i)*x;
}