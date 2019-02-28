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

struct T{
	int o, p, b;
	char nome[1000];
	void read(){
		scanf("%s%d%d%d", nome, &o, &p, &b );
	}
	void print(){
		printf("%s %d %d %d\n", nome, o, p, b );
	}
};

bool cmp( T b, T a ){
	if( a.o != b.o ) return b.o > a.o;
	if( a.p != b.p ) return b.p > a.p;
	if( a.b != b.b ) return b.b > a.b;
	return strcmp( b.nome, a.nome ) < 0;
}

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		vector<T> v( n );
		rep( i, 0, n ) v[i].read();
		sort( all(v), cmp );
		rep( i, 0, n ) v[i].print();
	}

}
