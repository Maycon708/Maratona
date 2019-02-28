#include <stdio.h>

int main(){
	double a, b;
	while( scanf("%lf%lf", &a, &b ) != EOF ){
		printf("%.2f\n", a/b );
	}
}

