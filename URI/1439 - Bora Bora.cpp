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

int C( char c ){
	char aux[] = {"CDHS"};
	rep( i, 0, 4 ) if( c == aux[i] ) return i;
}

struct card{
	int v;
	char n;
	bool e;
	bool operator < ( card q ) const{
		if( v != q.v ) return v > q.v;
		return C(n) > C(q.n);
	}
	void read(){
		scanf("%d %c", &v, &n );
		e = 1;
	}
	void D(){
		printf("%d %c\n", v, n );
	}
};

int main(){
	int p, m, n, t = 1;
	while( scanf("%d%d%d", &p, &m, &n ) != EOF && p ){
		multiset<card> mao[12];
		multiset<card> :: iterator it;
		queue<card> deck;
		rep( i, 0, p ){
			rep( j, 0, m ){
				card a;
				a.read();
				mao[i].insert(a);
			}
		}
		card topo;
		topo.read();
		rep( i, p*m+1, n ){
			card a;
			a.read();
			deck.push(a);
		}
		int pos = 0, aux = 1;
		if( topo.v == 12 && topo.e ) aux = -1, topo.e = 0;
		while( 42 ){
			if( topo.v == 7 && topo.e ){
				mao[pos].insert( deck.front() ); deck.pop();
				mao[pos].insert( deck.front() ); deck.pop();
				pos = ( pos + aux + p )%p;
				topo.e = 0;
			}
			if( topo.v == 1 && topo.e ){
				mao[pos].insert( deck.front() ); deck.pop();
				pos = ( pos + aux + p )%p;
				topo.e = 0;
			}
			if( topo.v == 11 && topo.e ){
				pos = ( pos + aux + p )%p;
				topo.e = 0;
			}
			bool aa = 0;
			for( it = mao[pos].begin(); it != mao[pos].end(); it++ ){
				card a = *it;
				if( a.n == topo.n || a.v == topo.v ){ 
					topo = a;
					aa = 1; 
					break;
				}
			}
			if( aa ) mao[pos].erase(it);
			else{
				card a = deck.front(); deck.pop();
				if( a.v == topo.v || a.n == topo.n ) topo = a;
				else mao[pos].insert(a);
			}
			if( mao[pos].empty() ){
				printf("%d\n", pos+1 );
				break;
			}
			if( topo.v == 12 && topo.e ) aux *= -1, topo.e = 0;
			pos = ( pos + p + aux )%p;
		}
	}
}

