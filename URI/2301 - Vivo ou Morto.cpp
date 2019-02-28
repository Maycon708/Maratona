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

int main(){
	int p, r, x, n, op, u, t = 1;
	while( scanf("%d%d", &p, &r ) != EOF ){
		if( !p && !r ) break;
		queue<int> q;
		rep( i, 0, p ) scanf("%d", &x ), q.push(x);
		while( r-- ){
			scanf("%d%d", &n, &op );
			rep( i, 0, n ){
				x = q.front(); q.pop();
				scanf("%d", &u );
				if( u == op ) q.push(x);
			}
		}
		printf("Teste %d\n", t++ );
		printf("%d\n\n", q.front() );
		
	}
}

