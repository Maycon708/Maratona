#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a, b, c, d, e;
	double s, t, pi = 3.14159;
	scanf("%d%d%d", &a, &b, &c );
	d = ( a + b + abs( a - b ) )/2;
	e = ( d + c + abs( d - c ) )/2;
	printf("%d eh o maior\n", e );
}
