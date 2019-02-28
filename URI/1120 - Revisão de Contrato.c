#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n;
	char s[1000];
	while( 1 ){
		scanf("%d %s", &n, s );
		if( !n && strcmp( s, "0" ) == 0 ) break;
		int tam = strlen( s );
		int aux = 0, i;
		for( i = 0; i < tam; i++ ){
			if( s[i] != '0' + n && ( aux || s[i] != '0' ) ){
				printf("%c", s[i]);
				aux = 1;
			}
		}
		if( !aux ) printf("0");
		printf("\n");
	}
}
