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

typedef long long int ll;
typedef long double ld;
typedef pair <int, int> ii;

int main(){

	int v, p, n, t, d[11];
	while( scanf("%d%d%d", &v, &p, &n ) != EOF ){
		if( !v && !p && !n ) break;
		rep( i, 0, p ) scanf("%d", &d[i] );
		vector<ii> st;
		rep( i, 0, n ){
			ld ans = 0;
			ld lt = 0, ld = 0;  	
			rep( j, 0, p ){
				scanf("%d", &t );
				int aux = 3.6*(d[j])/v, tmp = 1200;
				if( t < aux ) ans += min(2*abs(aux-t), tmp );
				else ans += min( tmp, abs(t-aux) );
			}
			st.pb( ii( ans, i+1 ) );
		}
		sort(all(st));
		rep( i, 0, st.size() ) printf("%d%s", st[i].S, (i+1 == st.size() )? "\n" : " " );
	}

}
