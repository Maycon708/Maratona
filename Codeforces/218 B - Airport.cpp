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
	int n, m, a;
	while( scanf("%d%d", &n, &m ) != EOF ){
		priority_queue<int> pq, st;
		rep( i, 0, m ){
			scanf("%d", &a );
			pq.push(a);
			st.push(-a);
		}
		int mx = 0, mn = 0, t = 0;
		while( !pq.empty() && t < n ){
			int u = pq.top();
			pq.pop();
			mx += u;
			if( u - 1 ) pq.push( u-1 );
			t++;
		}
		while( !st.empty() && n ){
			int u = -st.top();
			st.pop();
			mn += u;
			if( u - 1 ) st.push( -u+1 );
			n--;
		}
		printf("%d %d\n", mx, mn );
	}
}

