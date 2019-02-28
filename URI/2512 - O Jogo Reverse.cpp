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

struct matriz{
	int m[5][5];
	bool operator < ( matriz A ) const{
		rep( i, 0, 3 )
			rep( j, 0, 3 )
				if( m[i][j] != A.m[i][j] )
					return m[i][j] < A.m[i][j];
		return m[0][0] < A.m[0][0];
	}
	void read(){
		char c;
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				cin >> c;
				m[i][j] = ( c == '*' )? 1 : 0;
			}
		}
	}
	void set( int u ){
		rep( i, 0, 3 )
			rep( j, 0, 3 )
				m[i][j] = u;
	}
	void press( int i, int j ){
		int dx[] = { 1, -1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };
		m[i][j] ^= 1;
		rep( k, 0, 4 ){
			int x = i + dx[k], y = j + dy[k];
			if( x < 0 || y < 0 || x > 2 || y > 2 ) continue;
			m[x][y] ^= 1; 
		}
	}
};

unordered_map<matriz, int> mp;

void bfs(){
	queue< pair< matriz, int > > q;
	matriz aux;
	aux.set(0);
	q.push( mk( aux, 0 ) );
	aux.set(1);
	q.push( mk( aux, 0 ) );
	while( ! q.empty() ){
		matriz u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( mp.count(u) ) continue;
		mp[u] = c;
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				aux = u;
				aux.press( i, j );
				q.push( mk( aux, c+1 ) );
			}
		}
	}
}

int main(){
	bfs();
	int t, aa = 0, bb = 0;
	scanf("%d", &t );
	while( t-- ){
		matriz a, b;
		a.read();
		b.read();
		if( mp[a] > mp[b] ) aa++;
		else if( mp[b] > mp[a] ) bb++;
	}
	if( aa > bb ) printf("Jason wins!\n");
	else if( aa < bb ) printf("Fred wins!\n");
	else printf("Its a draw!\n");

}

