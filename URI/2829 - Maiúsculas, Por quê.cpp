#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

string v[50040];

bool cmp( string a, string b ){
	int t1 = a.size(), t2 = b.size();
	rep( i, 0, min(t1, t2) ) if( tolower(a[i]) != tolower(b[i])) return  tolower(a[i]) < tolower(b[i]); 
	if( t1 != t2 ) return t1 < t2;
	return a < b;
}

int main(){
	int n;
	
	while( scanf("%d", &n) != EOF ){
		rep( i, 0, n ) cin >> v[i];
		sort( v, v+n, cmp );
		rep( i, 0, n ) cout << v[i] << endl;
	}
}
