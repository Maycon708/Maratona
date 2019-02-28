#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){
	int d, m, month[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 25 };
	while( cin >> m >> d ){
		if( m == 12 ){
			if( d > 25 ) printf("Ja passou!\n");
			else if( d == 25 ) printf("E natal!\n");
			else if( d == 24 ) printf("E vespera de natal!\n");
			else printf("Faltam %d dias para o natal!\n", 24 - d );
		}
		else{
			int cnt = 0;
			rep( i, m, 13 ){
				cnt += month[i];	
			}
			cnt -= d;
			printf("Faltam %d dias para o natal!\n", cnt );
		}
	}
}

