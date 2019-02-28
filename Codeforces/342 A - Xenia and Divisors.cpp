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
	int n, aux;
	while( scanf("%d", &n ) != EOF ){
		vector<int> cnt(10, 0);
		rep( i, 0, n ){
			scanf("%d", &aux );
			cnt[aux]++;
		}
		if( cnt[7] || cnt[5] || cnt[1] != n/3 || cnt[4] > cnt[2] || cnt[3] != ( cnt[6] + cnt[4] - cnt[2] ) ){
			printf("-1\n" );
			continue;
		}
		rep( i, 0, cnt[4] ) printf("1 2 4\n");
		cnt[2] -= cnt[4];
		rep( i, 0, cnt[2] ) printf("1 2 6\n");
		cnt[6]  -= cnt[2];
		rep( i, 0, cnt[3] ) printf("1 3 6\n");
		
	}
}

