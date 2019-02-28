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

int n, d, a, b, c, sz;
double pd[11][11][11];
ll C[55][55];

void pascal(){
	C[0][0] = 1;
	rep( i, 0, 55 ){
		C[i][0] = C[i][i] = 1;
		rep( j, 1, i ){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
}

double prob( int a, int b, int c, int i, int j, int k ){
	int aa = d - i - j - k, bb = n - a - b - c;
	double numerador = C[a][i] * C[b][j] * C[c][k] * C[bb][aa];
	double denominador = C[n][d];
	return numerador/denominador;
}

double solve( int aa, int bb, int cc ){
	if( !aa && ( !bb || !cc ) ) return 0;
	if( pd[aa][bb][cc] > -1 ) return pd[aa][bb][cc];
	double ans = 0;
	rep( i, 0, aa+1 ){
		rep( j, 0, bb+1 ){
			rep( k, 0, cc+1 ){
				if( i+j+k > d || i+j+k == 0 ) continue;
				ans += ( prob( aa, bb, cc, i, j, k ) * solve( aa-i, bb-j, cc-k ) );
			}
		}
	}
	return pd[aa][bb][cc] = (1.0/(1-prob(aa, bb, cc, 0,0,0))) * (1+ans);
}

int main(){
	
	int aux;
	pascal();
	while( scanf("%d%d%d", &n, &d, &sz ) != EOF ){
		set<int> st;
		rep( i, 0, sz ){
			scanf("%d", &aux );
			st.insert(aux);
		}
		a = b = c = 0;
		rep( i, 0, sz ){
			scanf("%d", &aux );
			if( st.count(aux) ) a++;
			else b++;
		}
		c = st.size() - a;
		memset( pd, -10, sizeof pd );
		double ans = solve( a, b, c );
		printf("%.6f\n", ans );
	}
	
}
