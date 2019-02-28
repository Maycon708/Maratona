#include<stdio.h>

int main(){
	int a, b, c, d, num, dem;
	for( a = 1; a <= 500; a++ ){
		for( b = a; b < ( 2000 - a )/3; b++ ){
			for( c = b; c < ( 2000 - a - b )/2; c++ ){
				num = 1000000 * ( a + b + c );
				dem = a * b * c - 1000000;
				if( dem <= 0 || num%dem ) continue;
				d = num/dem;
				if( d < c || a + b + c + d > 2000 ) continue;
				printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0 );
			}
		}
	}
}
