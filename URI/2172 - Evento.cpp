#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked

int main(){
	register int a, b;
	while( 1 ){
		register int c = gc();
	    a = 0;
	    for( ; ( c < 48 || c > 57 ); c = gc() );
	    for( ; c > 47 && c < 58; c = gc() ){ a = (a << 1 ) + ( a << 3) + c - 48; }
	    if( !a ) break;
		c = gc();
	    b = 0;
	    for( ; ( c < 48 || c > 57 ); c = gc() );
	    for( ; c > 47 && c < 58; c = gc() ){ b = (b << 1 ) + ( b << 3) + c - 48; }
	    if( a == 1 ) printf("%d\n", b );
	    else if( a == 2 ) printf("%d\n", b << 1 );
	    else printf("%d\n", b*a );
	}
    return 0;
}

