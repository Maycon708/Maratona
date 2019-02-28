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

const int N = 100010;

int age[N], v[N], idade[N];
double m[N], sum[N], money[N];

inline bool cmp( int a, int b ){
	return age[a] < age[b];
}


#define gc getchar_unlocked

void scanint( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ); c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}


int main(){
	int n, d;
	scanint(n), scanint(d);
	rep( i, 1, n+1 ){
		v[i] = i;
		scanint(age[i]);
	}
	sum[0] = 0;
	rep( i, 1, n+1 ){
		scanf("%lf", &m[i] );
	}
	sort( v+1, v+n+1, cmp );
	rep( i, 1, n+1 ){
		idade[i] = age[ v[i] ];
		money[i] = m[ v[i] ];
		sum[i] = sum[i-1] + money[i];
	}
	int qtdd = 0, tam = 0, last = -1;
	double valor = 0; 
	rep( i, 1, n+1 ){
		int aux = idade[i] + d;
		int pos = upper_bound( idade, idade+n+1, aux ) - idade;
		tam = max( tam, pos - i );
		pos--;
		valor = max( valor, sum[pos] - sum[i-1] );
		if( pos != last ) qtdd++;
		last = pos;
	}
	printf("%d %d %.2f\n", qtdd, tam, valor );
}
