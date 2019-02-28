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

const int mod = 1e9 + 7;

struct matriz{
	ll mat[2][2];
	
	void null(){
		mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
	}
	matriz mul( matriz aux ){
		matriz ans;
		ans.null();
		rep( i, 0, 2 ) rep( j, 0, 2 ) rep( k, 0, 2 )
			ans.mat[i][j] = ( ans.mat[i][j] + ( mat[i][k] * aux.mat[k][j] )%mod )%mod;
		return ans;
	}
	void init(){
		mat[0][0] = 3;	mat[0][1] = 2; 
		mat[1][0] = 2;	mat[1][1] = 2; 
	}
	void id(){
		mat[0][0] = 1;	mat[0][1] = 0; 
		mat[1][0] = 0;	mat[1][1] = 1; 
	}
	void D(){
		printf("%lld %lld\n", mat[0][0], mat[0][1] );
		printf("%lld %lld\n", mat[1][0], mat[1][1] );
	}
};

int main(){	
	matriz a, b;
	ll n;
	while( scanf("%lld", &n ) != EOF ){
		a.init();
		b.id();
		n--;
		while( n ){
			if( n&1 ) b = b.mul(a);
			a = a.mul(a);
			n >>= 1;
		}
		ll aux = 0;
		rep( i, 0, 2 )
			rep( j, 0, 2 )
				aux = ( aux + b.mat[i][j] )%mod;
		
		printf("%lld\n", ( aux * 6 )%mod );
	}
}

