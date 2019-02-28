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

inline int mod( int a, int b ){
	return ( (a%b) + b )%b;
}

int main(){
	int n, m, pos, dir;
	while( scanf("%d%d", &n, &m ) != EOF ){
		vector<ii> v;
		map<int,int> mp;
		rep( i, 0, m ){
			scanf("%d%d", &pos, &dir );
			pos--;
			v.pb( ii( pos, dir ) );
			mp[pos] = 1;
		}
		sort( all(v) );
		int ans = n;
		rep( i, 1, m ){
			map<int, int> aux;
			int dist = v[i].F - v[0].F;
			if( v[0].S == -1 ) dist = n - dist;
			rep( j, 0, m ){
				pos = ((( v[j].F + v[j].S * dist )%n ) + n )%n;
				if( !mp.count(pos) ) break;
				aux[pos] = 1;
 			}
 			if( aux.size() == m ) ans = min( ans, abs( dist ) );
		}
		printf("%d\n", ans );
	}
}

