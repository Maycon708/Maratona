#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)

using namespace std;

int main(){
	int t;
	char s[10], c;
	while( scanf("%d", &t ) != EOF ){
		while( t-- ){
			scanf("%s", s );
			c = 0;
			int tam = strlen(s);
			rep( i, 0, tam ) c = c * 2 + ( s[i] - '0' );
			printf("%c", c );
		}
		printf("\n");
	}
}
