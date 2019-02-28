#include <bits/stdc++.h>
        
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " " << y << " --- " << #z << " " << z << "\n";
#define debugV(a, b) { for( int i = 0; i < b; i ++ ) cout << a[i] << " "; cout << endl; }
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
#define MAXV 500*500+1
        
using namespace std;
        
typedef unsigned long long ll;
typedef pair < int, int >  ii;
typedef pair < string, int >  si;

int mat[10][10], n, m;

inline bool dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m;
}

inline bool B( string s ){
	int tam = s.size();
	rep( i, 1, tam ){
		if( s[i] != s[i-1] ) return 0;
	}
	return 1;
}

string bfs( int a, string S ){
	int k = 0, mat[11][11], vis[11][11], dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
	rep( i, 0, n ){
		rep( j, 0, m ){
			mat[i][j] = S[k++] - '0';
			vis[i][j] = 0;
		}
	}
	int b = S[0]-'0';
	queue < ii > q;
	q.push( ii( 0, 0 ) );
	while( !q.empty() ){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		if( vis[x][y] ) continue;
		vis[x][y] = 1;
		mat[x][y] = a;
		rep( i, 0, 4 ){
			int xx = x + dx[i], yy = y + dy[i];
			if( dentro( xx, yy ) ){
				if( mat[xx][yy] == a || mat[xx][yy] == b ){
					q.push( ii( xx, yy ) );
				}
			}
		}
	}
	string s;
	rep( i, 0, n ){
		rep( j, 0, m ){
			s += ( char ) ( '0' + mat[i][j] );
		}
	}
	return s;
}

int resp[] = { 5, 3, 5, 2, 6, 9, 1 , 4, 8 , 7, 0};
int k = 0;
int solve( string S ){
	map < string, int > vis;
	queue < si > q;
	q.push( si( S, 0 ) );
	while( !q.empty() ){
		string s = q.front().F;
		int c = q.front().S;
		q.pop();
		if( vis.count(s) ) continue;
		vis[s] = 1;
		if( B(s) ) return c;
		rep( i, 0, 10 ){
			string ss = bfs( i, s );
//			debug(ss)
			q.push( si( ss, c+1 ));
		}
//		getchar();
	}
}

int main(){	
	
	char s[10];
	string S;
	while( scanf("%d%d", &n, &m ) != EOF ){
		S = "";
		rep( i, 0, n ){
			scanf("%s", s );
			S += s;
		}
		printf("%d\n", solve( S ) );
	
	}
	
		
	return 0;
}
