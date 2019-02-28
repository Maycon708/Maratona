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

const int mod = 1e9+7;
int pd[111][111], n, k;

const int MAX_N = 210;

ll C[MAX_N][MAX_N];
 
void calc_pascal(){
    memset(C, 0, sizeof(C));
    for(int i = 0; i < MAX_N; i++){
        C[i][0] = C[i][i] = 1;   
        for(int j = 1; j < i; ++j){
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
    }
}

int solve( int u, int rest ){
	if( !rest ) return 1;
	if( u == n ) return 0;
	if( pd[u][rest] != -1 ) return pd[u][rest];
	int ans = 0;
	rep( i, 0, k ){
		if( i > rest ) break;
		
		ans = ( ans + C[rest][i] * solve( u+1, rest - i ) )%mod;
	}
	return pd[u][rest] = ans;
}

int main(){
	calc_pascal();
	while( scanf("%d%d", &n, &k ) != EOF ){
		memset( pd, -1, sizeof pd );
		if( n >= 2 )
		printf("%d\n", solve( 0, n-2 ) );
		else puts("1");
	}
}
