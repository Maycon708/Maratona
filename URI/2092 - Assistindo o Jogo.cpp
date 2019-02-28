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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

set<int> st[1000010];
ll team[100100];

int main(){
	int n, f, m, l, e;
	set<int> :: iterator fst, lst;
	ll a, b, c;
	
	while( scanf("%d%d", &n, &f ) != EOF ){
		rep( i, 0, f ) st[i].clear();
		scanf("%lld%lld%lld", &a, &b, &c );
		team[0] = a%l;
		st[a].insert(0);
		rep( i, 1, n ){
			team[i] = ( team[i-1] * b + c )%f;
			st[team[i]].insert(i);
		}
		scanf("%d", &m );
		while( m-- ){
			scanf("%d%d", &l, &e ); l--;
			st[team[l]].erase( st[team[l]].find(l) );
			if( st[e].empty() ) printf("%d %d\n", n, n );
			else{
				fst = st[e].lower_bound(l);
				lst = st[e].upper_bound(l);
				if( fst == st[e].begin() ) fst = st[e].end();
				fst--;
				if( lst == st[e].end() ) lst = st[e].begin();
				printf("%d %d\n", (n+(l-*fst)%n)%n, (n+(*lst-l)%n)%n );
			}
			team[l] = e;
			st[e].insert(l);
		}
	}
}
