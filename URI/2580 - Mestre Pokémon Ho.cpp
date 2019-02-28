#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 1, 1+c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef double ld;

#define N 150

struct pokemon{
	ld p;
	int t, e;
	ld r[10010];
};

inline bool cmp( pokemon a, pokemon b ){
	return ( 1 - a.p ) * a.e < ( 1 - b.p ) * b.e;
}

pokemon P[100];
int n, p;
ld S[33][N], Y[33][N], pd[33][1001], prob[33][1001];
char nome[100];	

void pre(){
	rep( i, 0, n ){
		ld aux = 1, escape = 1;
		rep( k, 1, N ){
			S[i][k] = ( 1 - P[i].p ) * aux * escape;
			aux *= P[i].p;
			Y[i][k] = aux * P[i].r[(k-1)%P[i].t] * escape;
			escape *= ( 1 - P[i].r[(k-1)%P[i].t] );
		}
	}
}

ld probabilidade( int i, int j ){
	if( i == -1 || j <= 0 ) return 1; 
	if( prob[i][j] > -1 ) return prob[i][j];
	ld ans = 0;
	rep( k, 1, min( j+1, N ) )
		ans += ( S[i][k] + Y[i][k] * probabilidade( i-1, j-k ) );
	return prob[i][j] = ans;
}

ld solve( int i, int j ){
	if( i == -1 ||  j <= 0 ) return 0;
	if( pd[i][j] > -1 ) return pd[i][j];
	ld ans = 0;
	rep( k, 1, min( j+1, N ) )
		ans += ( S[i][k] * probabilidade(i-1, j-k))*(P[i].e + solve(i-1, j-k)/probabilidade(i-1, j-k) ) + Y[i][k] * solve(i-1, j-k) + S[i][k] * ( 1 - probabilidade(i-1, j-k) ) * P[i].e;
		
	return pd[i][j] = ans;
}

int main(){
	
	while( scanf("%d%d", &n, &p ) != EOF ){
		p = min( p, 1000 );
		rep( i, 0, n ){
			for( int j = p; j >= 0; j-- ) pd[i][j] = prob[i][j] = -100;
			scanf("%s%d%d%lf", nome, &P[i].t, &P[i].e, &P[i].p );
			rep( j, 0, P[i].t ) scanf("%lf", &P[i].r[j] );
		}
		sort( P, P+n, cmp );
		pre();
		printf("%.4f\n", solve(n-1, p) );	
	}

}
