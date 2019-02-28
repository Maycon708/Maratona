#include<stdio.h>

int main(){

	int n, i, aux, cnt;
	
	while( scanf("%d", &n ) != EOF && n ){
		aux = n; i = 2; cnt = 0;
		while( aux > 1 ){
			if( aux%i == 0 ) cnt++;
			while( aux%i == 0 ) aux/=i;
			i++;
		}
		printf("%d : %d\n", n, cnt );
	}

	return 0;
}
