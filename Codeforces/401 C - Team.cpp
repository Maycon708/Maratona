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
	int n, m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( n > m+1 || m > (n+1)*2 ){
			printf("-1\n");
			continue;
		}
		int u = -1, p = -1;
		while( n || m ){
			if( n >= m ){
				if( !u ) printf("1"), m--, u = 1, p = 0;
				else printf("0"), n--, u = 0, p = 1;
			}
			else{
				if( u == 1 && p == 1 ) printf("0"), n--, u = 0;
				else printf("1"), m--, p = u, u = 1;
			}
		}
		printf("\n");
	}
}

