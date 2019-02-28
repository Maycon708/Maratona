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
	int n;
	while( scanf("%d", &n ) != EOF ){
		int a, b, o1 = 0, z1 = 0, o2 = 0, z2 = 0;
		rep( i, 0, n ){
			scanf("%d%d", &a, &b );
			a ? o1++ : z1++;
			b ? o2++ : z2++;
		}
		printf("%d\n", min( o1, z1 ) + min( o2, z2 ) );
	}
}

