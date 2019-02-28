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

typedef long long int ll;
typedef pair <int, int> ii;

int n, m;
vector<ii> mat[22];

int cmp( ii a, ii b ){
	if( a.S != b.S ) return a.S > b.S;
	return a.F > b.F;
}

void D( ii a ){
	char ss[] = {"SGWR"};
	printf("[%d]%c ", a.F, ss[ a.S ]  );		
}

int ordena(){
	int ans = 0;
	rep( id, 0, m ){
		bool t;
		do{
			t = 0;
			rep( j, 0, n-1 ){
				if( cmp( mat[j][id], mat[j+1][id] ) ){
					ans++;
					swap( mat[j+1], mat[j] );
					t = 1;
				}
			}
		}while(t);
	}
	return ans;
}

int C( char b ){
	if( b == 'S' ) return 0; 
	if( b == 'G' ) return 1; 
	if( b == 'W' ) return 2; 
	if( b == 'R' ) return 3; 
}

int main(){
	int t = 1;
//	freopen("RedLights-g.in", "r", stdin );
	while( scanf("%d%d", &n, &m ) != EOF ){
		ll a; char b;
		ll cnt = 0;
		rep( i, 0, n ){
			mat[i].clear();
			rep( j, 0, m ){
//				scanf(" [%lld]%c", &a, &b );
				a = (i+j)%(i+1); b = 'G';
				if( b == 'R' ) cnt += a;
				mat[i].pb( ii( a, C(b) ) );
			} 
		}
		if( t != 1 ) printf("\n");
		printf("Instance %02d:\n", t++ );
		printf("%d %lld\n", ordena(), cnt );		
	}
}

