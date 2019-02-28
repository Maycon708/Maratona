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

#define N  110

int n, p[N], c[N], pd[N][N], cnt, mat[N][N];
double r[N], ans;

int solve( int pos, int cap ){
	if( pos == n ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int a = solve( pos+1, cap ), b = 0;
	if( cap >= c[pos] ) 
		b = solve( pos+1, cap - c[pos] ) + p[pos];
	if( b > a ) mat[pos][cap] = 1;
	return pd[pos][cap] = max( b, a );
}

void back( int pos, int cap ){
	if( pos == n ) return;
	if( mat[pos][cap] ){
		ans += r[pos];
		cnt++;
		back( pos+1, cap - c[pos] );
	}
	else back( pos+1, cap );
}

int main(){
	
	int m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		double media = 0;
		ans = 0; cnt = 0;
		if( !n && !m ) break;
		rep( i, 0, n ){
			scanf("%d%d%lf", &p[i], &c[i], &r[i] );
			rep( j, 0, m+1 ) pd[i][j] = -1, mat[i][j] = 0;
			media += r[i];
		}
		media /= n;
		solve( 0, m );
		back( 0, m );
		ans /= cnt;
		if( fabs(ans - media) > 1e-9 && ans > media ) 
			printf("%.2f\n", ans );
		else 
			printf("%.2f NO!\n", media );
	}
}

