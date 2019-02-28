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
#define PMAX 10000
#define TMAX 10000

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef vector<ll> vec;

vector<ll> pattern, text[200010];
int n, m, P[1010101];

void pre_process( ){
	P[0] = 0;
	int j = 0;
	rep( i, 1, pattern.size() ){
		while( j > 0 && pattern[j] != pattern[i] ) j = P[j-1];
		if( pattern[j] == pattern[i] ) j++;
		P[i] = j;
	}
}

bool qbra;

void KMP ( int id ){
//	bool aux = true;
	int j = 0;
	rep( i, 0, text[id].size() ){
		while( j > 0 && pattern[j] != text[id][i] ) j = P[j-1];
		if( pattern[j] == text[id][i] ){
			j++;
			if( j == pattern.size() ){
				printf("%d %d\n", i-j+1, id );
				qbra = false;
				j = P[j-1];
			}
		}
	}
	return;
}

char mat[1110][1110];

int main(){
	int test = 1;
	while( scanf("%d%d", &n, &m ) != EOF ){
		
		pattern.clear();
		rep( i, 0, n ){
			text[i].clear();
			scanf("%s", mat[i] );
		}
		
		ll aux = ( ll(1) << m ) -1;
		rep( i, 0, n ){
			ll a = 0;
			rep( j, 0, n ){
				a <<= 1;
				if( mat[i][j] == '|' ) a ^= 1;
				a &= aux;
				if( j+1 >= m )
					text[j+1-m].pb( a );
			}
		}
		
		rep( i, 0, m ){
			scanf("%s", mat[i] );
		}
		rep( i, 0, m ){
			ll a = 0;
			rep( j, 0, m ){
				a <<= 1;
				if( mat[i][j] == '|' ) a ^= 1;
			}
			pattern.pb( a );
		}
		pre_process();
	    qbra = 1;
	    printf("Instancia %d\n", test++ );
		rep( i, 0, n-m+1 ){
			KMP( i );
		}
		if( qbra ) printf("nenhuma ocorrencia\n");
		printf("\n");
	}
}
