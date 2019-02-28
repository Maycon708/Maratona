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
	int x[3], y[3], xx[3], yy[3];
	rep( i, 0, 3 ){
		cin >> x[i] >> y[i];
	}
	set<ii> st;
	set<ii> :: iterator it;
	rep( i, 0, 3 ){
		rep( j, 0, 3 ){
			rep( k, 0, 3 ){
				if( i == j || i == k || j == k ) continue;
				st.insert( ii( x[i] + ( x[j] - x[k] ), y[i] + ( y[j] - y[k] ) ) );
			}
		}
	}
	printf("%d\n", st.size() );
	for( it = st.begin(); it!= st.end(); it++ ){
		printf("%d %d\n", it -> F, it -> S );
	}
}

