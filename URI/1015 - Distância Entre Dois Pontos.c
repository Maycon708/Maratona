#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double a, b, c, d, pi = 3.14159;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d );
	printf("%.4f\n", hypot( a - c, b - d ) );
}
