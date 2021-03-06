#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

int main(){
	register int t, n, m, u;
	scan(t);
	for( register int k = t; k > 0; k-- ){
		scan(n), scan(m);
		vector<int> v;
		register int ans = 0, last = 0;
		for( register int i = m; i > 0; i-- ) scan(u), v.pb(u);
		
		sort( all(v) );
		
		for( register int i = 0; i < m; i++ ){
			if( v[i] > n ) break;
			ans = max( ans, v[i] - last );
			last = v[i];
		}
		ans = max( ans, n - last );
		printf("%d\n", ans );
	}	
}

