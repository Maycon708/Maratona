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

const int N = 100010;

int vet[N], P[N], n, mp[N];

int LIS(){
	
	int L[N], L_id[N];
	int li = 0, lf = 0;
	rep( i, 0, n ){
		int pos = lower_bound(L, L + li, vet[i]) - L;
		L[pos] = vet[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if( pos + 1 > li ) {
			li = pos + 1;
			lf = i;
		}
	}
	return li;
}


int main(){
	int t, u;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, n ){
			scanf("%d", &u );
			mp[u] = i;
		}
		rep( i, 0, n ){
			scanf("%d", &u );
			vet[i] = mp[u];	
		}
		printf("%d\n", LIS() );
	}
}

