#include <stdio.h>

typedef long long int ll;

int main(){
	
	ll a, b, c;
	while( scanf("%llx%llx%llx", &a, &b, &c ) != EOF ){
		ll aa = ( (a/b) * (a/b) );
		ll bb = ( (b/c) * (b/c) );
		printf("%llx\n", 1 + aa + aa * bb );
	}
	
}

