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
	int n, v[100010], sum;
	while( cin >> n ){
		sum = 0;
		rep( i, 0, n ){
			cin >> v[i];
			sum += v[i];
		}
		sum >>= 1;
		rep( i, 0, n ){
			sum -= v[i];
			if( !sum ) printf("%d\n", i+1 );
		}
	}
}

