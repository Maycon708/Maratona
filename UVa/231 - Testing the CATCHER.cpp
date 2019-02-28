#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
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

int main(){
	
	int u, t = 1;
	while( cin >> u ){
		if( u == -1 ) break;
		if( t != 1 ) printf("\n");
		vector<int> v;
		set< int > st;
		set< int > :: iterator it;
		v.pb( -u );
		while( cin >> u && u != -1 ){
			v.pb( -u );
		}
		int n = v.size();
		rep( i, 0, n ){                 
			it = st.lower_bound( v[i] );                 
			if( it != st.end() ) st.erase( it );                 
			st.insert( v[i] );           
		}
		printf("Test #%d:\n", t++ );
		printf("  maximum possible interceptions: %d\n", int( st.size() ));
//		printf("\n");
	}
	
}

