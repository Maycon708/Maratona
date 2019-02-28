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
	int n, m, a, b;
	while( scanf("%d%d", &n, &m ) != EOF ){
		map<int, int> mp1, mp2;
		map<int, int> :: iterator it;
		rep( i, 0, n ){
			scanf("%d%d", &a, &b );
			mp1[a] = b;
		}
		rep( i, 0, m ){
			scanf("%d%d", &a, &b );
			if( !mp1.count(a) || mp1[a] < b ) mp2[a] = max( b, mp2[a] );
		}
		for( it = mp2.begin(); it != mp2.end(); it++ ){
			printf("%d %d\n", it -> F, it -> S );
		}
	}
}

