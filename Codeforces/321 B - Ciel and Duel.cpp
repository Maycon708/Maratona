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

int main(){
	int n, m, p;
	char pos[10];
	vector<int> def, atk, my;
	
	scanf("%d%d", &n, &m );
	rep( i, 0, n ){
		scanf("%s%d", pos, &p );
		if( pos[0] == 'A' ) atk.pb(p);
		else def.pb(p);
	}
	rep( i, 0, m ){
		scanf("%d", &p );
		my.pb(p);
	}
	sort( all(def) );
	sort( all(atk) ); 
	sort( all(my) );
	
	int a = 0, b = 0;
	for( int i = 0, j = m-1; i < atk.size() && j >= 0; i++, j-- ){
		if( my[j] > atk[i] ) a += ( my[j] - atk[i] );
		else break;
	}
	p = 0;	
	bool check = 0;
	for( auto x : def ){
		p = upper_bound( my.begin()+p, my.end(), x ) - my.begin();
		if( p == my.size() ) check = 1;
		else my[p] = 0;
	}
	sort( all(my) );
	p = 0;
	for( auto x : atk ){
		p = lower_bound( my.begin()+p, my.end(), x ) - my.begin();
		if( p == my.size() ) check = 1;
		else b += ( my[p] - x ), my[p] = 0;
	}
	for( auto x : my ) b += x;
	
	if( check ) b = -1;
	cout << max(a, b) << endl;
}

