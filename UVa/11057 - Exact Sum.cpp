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
	int n, aux, t;
	while( scanf("%d", &n ) != EOF ){
		map<int, int> mp;
		map<int, int> :: iterator it;
		rep( i, 0, n ){
			scanf("%d", &aux );
			mp[aux]++;
		}
		scanf("%d", &t );
		int i, j, menor = INF;
		for( it = mp.begin(); it != mp.end(); it++ ){
			int x = it -> F;
			int y = t - x;
			if( !mp.count(y) ) continue;
			if( x == y && mp[x] < 2 ) continue;
			if( abs(x-y) < menor ){
				menor = abs(x-y);
				i = min( x, y );
				j = max( x, y );
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", i, j );
	}
}

