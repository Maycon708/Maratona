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

int v[1000000];

int main(){
	int n;
	while( scanf("%d", &n ) != EOF ){
		int ans = 0, cnt = 0;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			cnt += ( i );
			ans += v[i];
		}
		if( (ans-cnt)%n ) printf("-1\n");
		else{
			ans -= cnt;
			ans /= n;
			cnt = 0;
			rep( i, 0, n ){
				cnt += abs( v[i] - ans );
				ans++;
			}
			printf("%d\n", cnt >> 1 );
		}
	}
}

