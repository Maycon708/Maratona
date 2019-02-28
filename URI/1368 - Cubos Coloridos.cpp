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

void left( int v[] ){
	int a = v[1];
	v[1] = v[2];
	v[2] = v[3];
	v[3] = v[4];
	v[4] = a;
}

void up( int v[] ){
	int a = v[0];
	v[0] = v[1];
	v[1] = v[5];
	v[5] = v[3];
	v[3] = a;
}

bool cmp( int a[], int b[] ){
	rep( i, 0, 6 ){
		if( a[i] != b[i] ) return a[i] < b[i];
	}
	return 0;
}

struct cubo{
	int a[6];
	void read(){
		int v[6];
		rep( i, 0, 6 ) scanf("%d", &v[i] ), a[i] = v[i];
		rep( i, 0, 4 ){
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			up( v );   if( cmp( v, a ) ) memcpy( a, v, sizeof v );
		}
		left(v);
		rep( i, 0, 4 ){
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			left( v ); if( cmp( v, a ) ) memcpy( a, v, sizeof v );
			up( v );   if( cmp( v, a ) ) memcpy( a, v, sizeof v );
		}
	}
	bool operator < ( cubo A ) const{
		rep( i, 0, 5 ){
			if( a[i] != A.a[i] ) return a[i] < A.a[i];
		}
		return a[5] < A.a[5];
	}
	void D(){
		printf("%d\n", a[0] );
		rep( i, 1, 5 ) printf("%d ", a[i]);
		printf("\n%d\n", a[5] );
	}
};

int main(){
	
	int n;
	cubo aux;
	while( scanf("%d", &n ) != EOF ){
		if( !n ) break;
		set<cubo> st;
		rep( i, 0, n ){
			aux.read();
			st.insert( aux );
		}
		printf("%d\n", (int)st.size() );
	}

}

