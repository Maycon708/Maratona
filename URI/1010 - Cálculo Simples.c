#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a, b, c, d;
	double s, t;
	scanf("%d%d%lf", &a, &b, &s );
	scanf("%d%d%lf", &c, &d, &t );
	printf("VALOR A PAGAR: R$ %.2f\n", b*s + d*t );
}
