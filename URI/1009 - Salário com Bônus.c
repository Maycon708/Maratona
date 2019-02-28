#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a, b, c, d;
	double s, t;
	char nome[100];
	scanf("%s%lf%lf", nome, &s, &t );
	printf("TOTAL = R$ %.2f\n", s + t * 0.15 );
}
