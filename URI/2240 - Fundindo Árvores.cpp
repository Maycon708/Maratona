#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";


using namespace std;

const int N = 5*1e4;

int cnt, c[N], l[N];

void dfs( int w, int t ){
	cnt = max( cnt, t );
	if( c[w] ) dfs( c[w], t+1 );
	if( l[w] ) dfs( l[w], 1 );
}

#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	register int i, n, m, w, a, ans;
	while(42){
		scan(n);
		if( !n ) break;
		for( i = n; i > 0; i-- ){
			scan(w);
			scan( l[w] );
			scan( c[w] );
		}
		scan(m);
		for( i = m; i > 0; i-- ){
			scan(w);
			w += n;
			scan( c[w] ); if( c[w] ) c[w] += n;
			scan( l[w] ); if( l[w] ) l[w] += n;
		}
		cnt = a = w = 1;
		while( c[w] ) a++, w = c[w];
		dfs( n+1, 1 );
		ans = n + m - min( a, cnt );
		
		cnt = a = 1; w = 1 + n;
		while( c[w] ) a++, w = c[w];
		dfs( 1, 1 );
		ans = min( ans, n + m - min( a, cnt ) );
		
		printf("%d\n", ans );
	}
}

