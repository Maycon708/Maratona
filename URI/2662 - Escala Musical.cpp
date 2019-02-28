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

int main(){
	int n, v;
	int p[] = { 2, 4, 5, 7, 9, 11, 12 };
	string s[] = { "do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si", "desafinado" };
	
	while( scanf("%d", &n ) != EOF ){
		set<int> st;
		rep( i, 0, n ){
			scanf("%d", &v );
			v = (v-1)%12;
			st.insert(v);
		}
		int i;
		for( i = 0; i < 12; i++ ){
			bool ans = 1;
			set<int> aux;
			for( auto x : p ) aux.insert((i+x)%12);
			for( auto x : st ) ans &= aux.count(x);
			if( ans ) break;
		}
		printf("%s\n", s[i].c_str() );
	}
}
