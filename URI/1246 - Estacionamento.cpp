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

void D( map<ii, int > mp ){
	map < ii, int > :: iterator it;
	printf("----\n");
	for( it = mp.begin(); it != mp.end(); it++ )
		printf("%d %d %d\n", it -> F.F, it -> F.S, it -> S);
	printf("----\n");
}

int main(){
	int n, m, a, b, cnt;
	char op;
//	freopen("in.txt", "r", stdin );
	while( scanf("%d%d", &n, &m ) != EOF ){
		map < ii, int > mp;
		map < ii, int > :: iterator it;
		cnt = 0;
		while( m-- ){
			cin >> op;
			if( op == 'C' ){
				scanf("%d%d", &a, &b );
				ii last = ii( 0, 0 );
				bool aa = 1;
				for( it = mp.begin(); it != mp.end(); it++ ){
					ii aux = it -> F;
					if( b < aux.F - last.S ){
						mp[ ii( last.S+1, last.S+b )] = a;
						cnt++; aa = 0;
						break;
					} 
					last = it -> F;
				}
				if( aa && n - last.S >= b ){
					mp[ ii( last.S+1, last.S+b )] = a;
					cnt++;
				}
			}
			else{
				scanf("%d", &a );
				for( it = mp.begin(); it != mp.end(); it++ ){
					if( it -> S == a ){
						mp.erase( it );
						break;
					}
				}
			}
//			D( mp );
		}
		printf("%d\n", cnt * 10 );
	}	
}
