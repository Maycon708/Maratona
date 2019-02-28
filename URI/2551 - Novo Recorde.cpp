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
	int n, t, d, rt, rd;
	
	while( scanf("%d", &n ) != EOF ){
		puts("1");
		scanf("%d%d", &rt, &rd );
		rep( i, 1, n ){
			scanf("%d%d", &t, &d );
			if( t * rd < rt * d ){
				printf("%d\n", i+1 );
				rd = d, rt = t;
			}
		}
	}
	
}
