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

vector<ll> f;

void pre(){
	ll a = 1, b = 1, c;
	for( int i = 3; f.size() < 61; i++ ){
		bool verif = 0;
		c = a + b;
		a = b;
		b = c;
		while( c ){
			if( c%10 == 3 ) verif = 1;
			c /= 10; 
		}
		if( verif || b%3 == 0 ) f.pb( b );
	}
}

int main(){
	pre();
	int n;
	while( scanf("%d", &n ) != EOF ){
		printf("%lld\n", f[n-1] );
	}
}

