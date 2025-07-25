#include <stdio.h>
#define SIZE 6　// 配列のサイズを6に設定
#define ERR 0.00001　// 誤差
#define LOW 1.0　// 探索範囲の下限
#define HIGH 3.0　 // 探索範囲の上限
float proot( float *, int, float, float, float );　// 多項式の根を二分法で探索する関数
float polyf( float *, int, float );　// 多項式計算の関数プロトタイプ
int main() {
float a[SIZE], rir;
int i, n;
printf( "input polynomial data\n" );　// 多項式の係数入力
n = SIZE - 1;　// 多項式の次数
for ( i = 0; i < SIZE; i++ ) {
printf( "a[%2d]=", i);　// 各係数の入力表示
if ( scanf( "%f", &a[i] ) == EOF ) {　 // 入力終了判定
n = i - 1;
break;
}
}
rir = 1.072;　// 評価するxの値を設定
printf("balance at term end %f\n", polyf(a, n, rir));　 // 多項式評価結果を表示
return 0;
}

float proot( float *a, int n, float err, float xa, float xb ) {
float x1, x2, x;
x1 = xa;
x2 = xb;
if ( polyf( a, n, x1 ) * polyf( a, n, x2 ) > 0.0 )return ( xa - 1.0 );　// 根が区間内にない場合のエラー値
while ( x2 - x1 >= err ) {x = ( x1 + x2 )/2.0;
if ( polyf( a, n, x ) * polyf( a, n, x2 ) > 0.0 ) x2 = x;
else x1 = x;}return x2;
}

float polyf( float *a, int i, float x ) {
if(i>0)return(polyf(a,i-1,x)*x+(*(a+i)));　// 再帰で多項式を計算
else return *(a+i)*x;　 // 最後の項の計算
}
