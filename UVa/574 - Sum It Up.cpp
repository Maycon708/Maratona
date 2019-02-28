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

int v[20];
int ans[20], n, t;
set<string, greater<string> > st;

int cmp( int a, int b ){ 
	return a > b;
}

void C( int t ){
	int aux[20];
	memcpy( aux, ans, sizeof ans );
	sort(aux, aux+t, cmp);
	char ss[5];
	string str, a;
	rep( i, 0, t ){
		if( i ) str.pb('+');
		sprintf(ss, "%d", aux[i] );
		str += ss;
	}
	st.insert(str);
}

void back( int p, int sum, int i ){
	if( sum == t ){
		C(i);
		return;
	}
	if( p == n ) return;
	
	ans[i] = v[p];
	back( p+1, sum+v[p], i+1 );
	back( p+1, sum, i );
} 
	
int main(){

	while( scanf("%d%d", &t, &n ) != EOF && n+t ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		printf("Sums of %d:\n", t );
		back(0, 0, 0);
		if( st.empty() ) puts("NONE");
		else for( auto x : st ) cout << x << endl;
		st.clear();
	}
	
	 	
	return 0;
}
