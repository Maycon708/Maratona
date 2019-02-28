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

struct group{
	int a, b, c;
	group(){};
	group( int aa, int bb, int cc ){
		if( aa > bb ) swap( aa, bb );
		if( aa > cc ) swap( aa, cc );
		if( bb > cc ) swap( bb, cc );
		a = aa; b = bb; c = cc;
	}
	bool operator < ( group A ) const{
		if( a != A.a ) return a < A.a;
		if( b != A.b ) return b < A.b;
		return c < A.c;
	}
	void D(){
		printf("%d %d %d\n", a, b, c );
	}
};

struct quad{
	int a[4];
	quad(){};
	quad( group A, group B ){
		int a1 = A.a, a2 = B.a, b1 = A.b, b2 = B.b, c1 = A.c, c2 = B.c;
		set<int> st;
		set<int> :: iterator it;
		st.insert( a1 ); st.insert( b1 );
		st.insert( c1 ); st.insert( a2 );
		st.insert( b2 ); st.insert( c2 );
		int i = 0;
		for( it = st.begin(); it != st.end(); it++, i++ ){
			a[i] = *it;
		}
	}
	bool operator < ( quad A ) const{
		if( a[0] != A.a[0] ) return a[0] < A.a[0];
		if( a[1] != A.a[1] ) return a[1] < A.a[1];
		if( a[2] != A.a[2] ) return a[2] < A.a[2];
		return a[3] < A.a[3];
	}
	void P(){
		printf("%d %d %d %d\n", a[0], a[1], a[2], a[3] );
	}
};

map<group,bool> mp;

inline bool check( group a, group b ){
	quad aux = quad( a, b );
	rep( i, 0, 4 ){
		rep( j, i+1, 4 ){
			rep( k, j+1, 4 ){
				group c = group( aux.a[i], aux.a[j], aux.a[k] );
				if( !mp.count( c ) ) return 0;
			}
		}
	}
	return 1;
}

int main(){
	
	int m, a, b, c, t = 1;
	while( scanf("%d", &m ) != EOF ){
		if( !m ) break;
		mp.clear();
		set<quad> st;
		set<quad> :: iterator it3;
		map<group,bool> :: iterator it, it2;
		while( m-- ){
			scanf("%d%d%d", &a, &b, &c );
			mp[ group( a, b, c ) ] = 1;
		}
		printf("Instancia %d\n", t++ );
		for( it = mp.begin(); it != mp.end(); it++ ){
			for( it2 = it; it2 != mp.end(); it2++ ){
				if( it == it2 ) continue;
				group A = it -> F;
				group B = it2 -> F;
				if( check( A, B ) ){
					st.insert( quad( A, B ) );
				}
			}
		}
		if( st.empty() ) puts("ok");
		else 
			for( it3 = st.begin(); it3 != st.end(); it3++ ){
				quad A = *it3; A.P();
			}
		printf("\n");
	}
	
}

