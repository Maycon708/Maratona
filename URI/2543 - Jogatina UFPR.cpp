#include <stdio.h>

using namespace std;

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc(), aux = 0;
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() ) if( c == '-' ) aux = 1;
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
    if( aux ) x *= -1;
}

int main(){
	
	int n, id, a, b;
	
	while( 42 ){
		scan(n), scan(id);
		if( !n ) break;
		int cnt = 0;
		for( int i = n; i > 0; i-- ){
			scan(a), scan(b);
			if( !b && a == id ) cnt++; 
		}
		printf("%d\n", cnt );
	}
	
}
