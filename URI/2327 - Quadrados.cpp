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
	
	int m[11][11], sl[11], sc[11], sd[11], n;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) sl[i] = sc[i] = sd[i] = 0;
		rep( i, 0, n )
			rep( j, 0, n )
				scanf("%d", &m[i][j] );

		rep( i, 0, n ){
			rep( j, 0, n ){
				sl[i] += m[i][j];
				sc[j] += m[i][j];
			}
		}
		rep( i, 0, n )
			sd[0] += m[i][i], sd[1] += m[i][n-1-i];
		
		set<int> st;
		st.insert( sd[0] );
		st.insert( sd[1] );
	
		rep( i, 0, n ){
			st.insert( sc[i] );
			st.insert( sl[i] );
		}
		
		if( st.size() != 1 ) printf("-1\n");
		else printf("%d\n", *st.begin() );
	}
}

