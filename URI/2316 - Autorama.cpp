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

struct car{
	int id;
	int c;
	int p;
	int last;
	void init( int i ){
		id = i;
		last = 0;
		c = 0;
		p = 0;
	}
};

bool cmp( car a, car b ){
	if( a.p != b.p ) return a.p > b.p;
	return a.c < b.c;
}

int main(){
	int k, n, m, x, y;
	car v[111];
	while( scanf("%d%d%d", &k, &n, &m ) != EOF ){
		rep( i, 0, n ) v[i].init(i+1);
		rep( i, 0, m ){
			scanf("%d%d", &x, &y );
			x--;
			if( v[x].last + 1 == y ){
				v[x].last = y%k;
				v[x].p++;
				v[x].c = i;
			}
		}
		sort( v, v+n, cmp );
		rep( i, 0, n ){
			if( i ) printf(" ");
			printf("%d", v[i].id );
		}
		printf("\n");
	}
}

