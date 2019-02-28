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

struct result{
	string a, b;
	int r;
	int ga, gb;
	void read(){
		cin >> a >> ga >> b >> gb;
		r = ( ga > gb ) ? 1 : ( ga == gb ) ? 0 : -1;
		if( a > b ) swap( a, b ), swap( ga, gb ), r *= -1;
	}
	int cmp( result k ){
		if( k.a != a || k.b != b ) return 0;
		if( k.r == r ){
			if( ga == k.ga && gb == k.gb ) return 10;
			else if( ga == k.ga || gb == k.gb ) return 7;
			else return 5;
		}
		else return ( ga == k.ga || gb == k.gb ) * 2;
	}
};

int p[100], id[100];
string nome[100];

bool cmp( int a, int b ){
	if( p[a] != p[b] ) return p[a] > p[b];
	return nome[a] < nome[b];
}

int main(){
	int n, m;
	result mat[50][50], aux;
	while( scanf("%d%d", &n, &m ) != EOF && n ){
		rep( i, 0, n ){
			id[i] = i, p[i] = 0;
			cin >> nome[i];
			rep( j, 0, m ) mat[i][j].read();
		}
		rep( i, 0, m ){
			aux.read();
			rep( i, 0, n ){
				rep( j, 0, m ){
					p[i] += aux.cmp( mat[i][j] );
				}
			}
		}
		sort( id, id+n, cmp );
		rep( i, 0, n ){
			printf("%s %d\n", nome[id[i]].c_str(), p[id[i]]);
		}
	}
}

