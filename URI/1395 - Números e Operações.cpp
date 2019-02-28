#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef vector< int > vec;

int  c, best;
vector< pair< ii, int > > ans, nss;

void D(vec v){
	rep( i, 0, v.size() ) printf("%d ", v[i] );
	printf("\n");
	getchar();
}

map< vec, bool> vis;

void solve( vec v ){
	int last = v[ v.size()-1 ];
	if( last == c ){
		if( ans.size() < best ){
			best = ans.size();
			nss = ans;
		}
		return;
	}
	if( vis[v] ) return;
	vis[v] = 1;
	rep( i, 0, v.size() ){
		rep( j, i+1, v.size() ){
			vec temp;
			rep( k, 0, v.size() ) if( k != i && k != j ) temp.pb(v[k]);
			
			temp.pb( v[i] + v[j] );
			ans.pb( mk( ii( i, j ), 0 ) );
			solve( temp );
			temp.pop_back();
			ans.pop_back();
			
			temp.pb( v[i] * v[j] );
			ans.pb( mk( ii( i, j ), 1 ) );
			solve( temp );
			temp.pop_back();
			ans.pop_back();
			
			temp.pb( abs( v[i] - v[j] ) );
			ans.pb( mk( ii( i, j ), 2 ) );
			solve( temp );
			temp.pop_back();
			ans.pop_back();
			
			if( v[j] && v[i]%v[j] == 0 ){
				temp.pb( v[i]/v[j] );
				ans.pb( mk( ii( i, j ), 3 ) );
				solve( temp );
				temp.pop_back();
				ans.pop_back();
			}
			
			else if( v[i] && v[j]%v[i] == 0 ){
				temp.pb( v[j]/v[i] );
				ans.pb( mk( ii( i, j ), 3 ) );
				solve( temp );
				temp.pop_back();
				ans.pop_back();
			}
			
		}
	}
}

int main(){
	
	while( scanf("%d", &c ) != EOF ){
		int n, x;
		vec v;
		ans.clear();
		best = INF;
		scanf("%d", &n );
		rep( i, 0, n ) scanf("%d", &x ), v.pb(x);
		solve( v );
		printf("%d\n", (int)nss.size() );
	}
}
