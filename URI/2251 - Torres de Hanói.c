#include <stdio.h>

int main(){
	int n, t = 1;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		printf("Teste %d\n", t++ );
		printf("%d\n\n", (1 << n ) -1 );
	}
}

