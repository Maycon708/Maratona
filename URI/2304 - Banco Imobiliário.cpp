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
	ll m, n, v, t[10];
	char p1, p2, op;
	while( cin >> m >> n ){
		rep( i, 0, 3 ) t[i] = m;
		rep( i, 0, n ){
			cin >> op;
			switch(op){
				case 'C':
					cin >> p2 >> v;
					t[p2-'D'] -= v;
					break;
				case 'V':
					cin >> p1 >> v;
					t[p1-'D'] += v;
					break;
				case 'A':
					cin >> p1 >> p2 >> v;
					t[p1-'D'] += v;
					t[p2-'D'] -= v;
					break;
			}
		}
		printf("%lld %lld %lld", t[0], t[1], t[2] );
		printf("\n");
		break;
	}
}

