#include <bits/stdc++.h>
  
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM(x,l,c) { rep( i, 0, l ){ rep(j, 0, c ) cout << x[i][j] << " ";  cout << "\n"; }};
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
  
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
  
using namespace std;
  
typedef pair <int, int> ii;
typedef long long int ll;
 
const int SZ = 3;
  
struct Matriz{
	ll mat[SZ][SZ];
};

ll mod;

Matriz identidade;

Matriz multiplica(Matriz A, Matriz B){
	Matriz C;
	for(int i = 0 ; i < SZ; i++)
		for(int j = 0 ; j < SZ; j++){
			C.mat[i][j] = 0;
			for(int k = 0; k < SZ; k++)
				C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])%mod)%mod;
		}
	return C;
}

Matriz fastExp(Matriz B, ll p){
	if(p == 0) return identidade;
	if(p == 1) return B;
	Matriz ret = fastExp(B,p/2);
	ret = multiplica(ret,ret);
	if(p&1) ret = multiplica(ret,B);
	return ret;
}

int main(){

	Matriz m, ans;
	ll n, a, b, c, d;
	int k = 1;
	rep( i, 0, 3 )
		rep( j, 0, 3 ){
			identidade.mat[i][j] = (i==j);
			m.mat[i][j] = ( ( i+1 == j ) || ( i == 1 ) || ( i == j && i == 2 ) );
		}
	
	while( cin >> n >> mod ){
		if( !n && !mod ) return 0;
		ans = fastExp( m, n );
		printf( "Case %d: ", k++ );
		cout <<  n << " " << mod << " " << ( ans.mat[1][2] + ans.mat[0][0] )%mod  << endl; 
	}
}
