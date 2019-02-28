#include <stdio.h>
#include <string.h>

char s[100], aux[100];
int t, j, i;

inline int C(){
	for( i = 0; i < j; i++ ){
		if( aux[i] != aux[j-i-1] ) return 0;
	}
	return 1;
}

inline int S( char s ){
	return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

int main(){
	while( scanf("%s", s ) != EOF ){
		int t = strlen( s );
		j = 0;
		for( i = 0; i < t; i++ ){
			if( S( s[i] ) ) aux[j++] = s[i];
		}
		aux[j] = '\0';
		if( C() ) printf("S\n");
		else printf("N\n");
	}
}

