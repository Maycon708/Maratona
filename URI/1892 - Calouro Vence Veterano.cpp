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

ll c, n;
string a[1000010], b[1000010];

void conta_e_intercala(int p, int q, int r){
	int i, j;

	for( i = p; i <= q; i++ ) b[i] = a[i];
	for( j = q+1; j <= r; j++ ) b[r+q+1-j] = a[j];
	i = p; j = r;
	
	for(int k = p; k <= r; k++){
		if( b[i] <= b[j] ){
			a[k] = b[i];
			i++;
		}
		else{
			a[k] = b[j];
			j--;
			c = c + ( q - i + 1 );
		}
	}
	return;
}

void conta_e_ordena( int p, int r){
	int q;
	if(p >= r) return;
	else{
		q = ( p+r )/2;
		conta_e_ordena( p, q );
		conta_e_ordena( q+1, r );
		conta_e_intercala( p, q, r );
	}
}

int main(){
	while( scanf("%lld", &n) != EOF ){
		rep( i, 0, n ) cin >> a[i];
		c = 0;
		conta_e_ordena(0, n-1);
		printf("%lld\n", c ); 
	}
	return 0;
	
}
