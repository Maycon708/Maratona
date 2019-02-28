#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
	int n, tam, i, result;
	char a[11000], b[11000];
	scanf("%d", &n );
	while( n-- ){
		result = 0;
		scanf("%s %s", a, b );
		tam = strlen( a );
		for( i = 0; i < tam; i++ ){
			result += ( b[i] - a[i] + 26 )%26;
		}
		printf("%d\n", result );
	}
}
