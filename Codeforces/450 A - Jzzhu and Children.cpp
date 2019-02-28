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
	int n, m, v[111];
	while( scanf("%d%d", &n, &m ) != EOF ){
		queue<int> q;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			q.push(i);
		}
		while( q.size() > 1 ){
			int a = q.front();
			q.pop();
			if( v[a] > m ){
				v[a] -= m;
				q.push(a);
			}
		}
		printf("%d\n", q.front()+1 );
	}
}

