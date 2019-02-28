#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
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

int dist[1000001], sum[1000001][13];

void crivo( ll upper ){
	bitset < 1000001 > b;
	b.set();
	vector < ll > primes;
	for( ll i = 2; i < upper; i++ ){
		rep( j, 0, 13 ) sum[i][j] = sum[i-1][j];
		if( b[i] ){
			primes.pb(i);
			for( ll j = i*i; j < upper; j+=i ) b[j] = 0;
			dist[i] = 1;
			sum[i][1]++; 
		}
		else{
			int j = 0, cnt = 0;
			ll n = i;
			while( primes[j] * primes[j] <= n ){
				if( n % primes[j] == 0 ){
					while( n%primes[j] == 0 ){
						n/=primes[j];
					}
					cnt += primes[j];
				}
				j++;
			}
			if( n > 1 ) cnt += n;
			dist[i] = dist[cnt] + 1;
			sum[i][ dist[i] ]++;
		}
	}
}

int main(){

	crivo( 1000001 );
	int t, i, j, k;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d", &i, &j, &k );
		if( k > 12 ) printf("0\n");
		else
		printf("%d\n", sum[j][k] - sum[i-1][k] );
	}
}

