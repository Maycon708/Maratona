#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
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

ll readInt();

int main(){
	
	char aux[] = {"BGC"};
	int m[10][10];
	while( scanf("%d", &m[0][0] ) != EOF ){
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				if( !i && !j ) continue;
				scanf("%d", &m[i][j] );
			}
		}
//		B
		int a = m[1][0] + m[2][0];
		int b = m[0][0] + m[2][0];
		int c = m[1][0] + m[0][0];
//		G
		int d = m[1][1] + m[2][1];
		int e = m[0][1] + m[2][1];
		int f = m[1][1] + m[0][1];
//		C
		int g = m[1][2] + m[2][2];
		int h = m[0][2] + m[2][2];
		int i = m[1][2] + m[0][2];
//		BGC
		int aa = a + e + i;
//		BCG
		int bb = a + f + h;
//		GBC
		int cc = b + d + i;
//		CBG
		int dd = b + f + g;
//		CGB
		int ee = c + e + g;
//		GCB
		int ff = c + d + h;
		int aaa = min( aa, min( bb, min( cc, min( dd, min( ee, ff ) ) ) ) );
		if( aaa == bb ) printf("BCG %d\n", aaa );
		else if( aaa == aa ) printf("BGC %d\n", aaa );
		else if( aaa == dd ) printf("CBG %d\n", aaa );
		else if( aaa == ee ) printf("CGB %d\n", aaa );
		else if( aaa == cc ) printf("GBC %d\n", aaa );
		else if( aaa == ff ) printf("GCB %d\n", aaa );
	}	
}




