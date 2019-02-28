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
map<int, int> mp;

int cmp( int a, int b ){
	if( mp[a] != mp[b] ) return mp[a] > mp[b];
	return a > b;
}

int main(){
	int n, u;
	while( cin >> n ){
		vector<int> v;
		mp.clear();
		rep( i, 0, n ){
			cin >> u;
			mp[u]++;
			v.pb(u);
		}
		sort( all(v), cmp );
		printf("%d\n", v[0] );
	}
}

