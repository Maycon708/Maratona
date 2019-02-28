#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int main(){
	
	int n, aux, e[10], o[10], xr[10], mask, a, b, c, maskE, maskO, maskX;
	char op, lastOp;
	
	while( scanf("%d", &n ) != EOF ){
		memset( o, 0, sizeof o );
		memset( e, 0, sizeof e );
		memset( xr, 0, sizeof xr );
		vector< pair<char, int> > v;
		rep( i, 0, n ){
			scanf(" %c%d", &op, &aux );
			if( !i ){
				lastOp = op;
				mask = aux;
			}
			else if( op == lastOp ){
				if( op == '&' ) mask &= aux;
				else if( op == '|' ) mask |= aux;
				else mask ^= aux;  
			} 
			else{
				v.pb( mk(lastOp, mask ) );
				lastOp = op;
				mask = aux;
			}
		}
		v.pb( mk( lastOp, mask ) );
		rep( i, 0, v.size() ){
			op = v[i].F;
			mask = v[i].S;
			if( op == '&'){
				rep( j, 0, 10 ){
					if( !( mask&(1<<j)) ){
						e[j] = 1;
						o[j] = 0;
						xr[j] = 0;
					}
				}
			}
			else if( op == '|'){
				rep( j, 0, 10 ){
					if( mask&(1<<j) ){
						o[j] = 1;
						e[j] = 0;
						xr[j] = 0;
					}
				}
			}
			else if( op == '^'){
				rep( j, 0, 10 ){
					if( mask&(1<<j) ){
						xr[j] ^= 1;
					}
				}
			}
		}
		a = b = c = maskE = maskO = maskX = 0;
		rep( i, 0, 10 ){
			if( o[i] == 1 ) a = 1, maskO |= (1<<i);
			if( e[i] == 1 ) b = 1;
			else maskE |= (1<<i);
			if( xr[i] == 1 ) c = 1, maskX |= (1<<i); 
		}
		printf("%d\n", a+b+c );
		if( b ) printf("& %d\n", maskE );
		if( a ) printf("| %d\n", maskO );
		if( c ) printf("^ %d\n", maskX );
	}	
	
	
}
