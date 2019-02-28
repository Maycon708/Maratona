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

int main(){
	int s, n, a, b;
	while( scanf("%d%d", &s, &n ) != EOF ){
		vector<ii> v;
		rep( i, 0, n ){
			scanf("%d%d", &a, &b );
			v.pb( ii( a, b ) );
		}
		sort( all(v) );
		bool aux = 1;
		rep( i, 0, v.size() ){
			aux &= ( s > v[i].F );
			s += v[i].S;
		}
		if( aux ) puts("YES");
		else puts("NO");
	}
}

