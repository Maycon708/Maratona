#include <stdio.h>

int main(){
	int a, b, c;
	while( scanf("%d%d%d", &a, &b, &c ) != EOF ){
		if( a == b || a == c || b == c ) printf("S\n");
		else if( a+b == c || a+c == b || b+c == a ) printf("S\n");
		else printf("N\n");
	}
}

