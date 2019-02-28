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
	int n, l, k, sum[1111];
	while( scanf("%d%d", &n, &l ) != EOF ){
		set<ii> st;
		rep( i, 0, n ){
			st.insert( ii( 0, i ) );
			sum[i] = 0;
		}
		rep( i, 0, l ){
			scanf("%d", &k );
			ii a = *st.begin();
			st.erase( st.begin() );
			sum[ a.S ]++;
			a.F += k;
			st.insert(a);
		}
		rep( i, 0, n ) printf("%d %d\n", i+1, sum[i] );
	}
}

