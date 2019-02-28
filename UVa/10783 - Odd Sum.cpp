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
	int sum[111], t, a, b, test = 1;
	sum[0] = 0;
	for( int i = 1; i < 100; i += 2 ) sum[i] = sum[i+1] = sum[i-1]+i;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &a, &b );
		printf("Case %d: %d\n", test++, sum[b] - ( a? sum[a-1] : 0 ));
	}
}

