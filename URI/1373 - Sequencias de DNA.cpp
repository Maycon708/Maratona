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

// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();
int  k, tam1, tam2;
char s1[1111], s2[1111];
int pd[1111][1111][2];
int solve( int i, int j, int aux ){
	if( i == tam1 || j == tam2 ) return 0;
	if( pd[i][j][aux] != -1 ) return pd[i][j][aux];
	int ans = 0;
	if( aux ) ans = max( ans, solve( i+1, j+1, s1[i] == s2[j] ) + ( s1[i] == s2[j] ) );
	else{
		bool aux = ( i + k <= tam1 ) && ( j + k <= tam2 );
		if( aux ){
			rep( l, 0, k )
				if( s1[i+l] != s2[j+l] ) aux = 0;
			ans = max( ans, solve( i+k, j+k, aux ) + aux * k );
		}
	}
	ans = max( ans, solve( i+1, j, 0 ) );
	ans = max( ans, solve( i, j+1, 0 ) );
	return pd[i][j][aux] = ans;
}

/*
int pd[1010][1010];
int solve( int i, int j ){
	if( i == tam1 || j == tam2 ) return 0;
	if( pd[i][j] != -1 ) return pd[i][j];
	int ans = 0;
	int I = i, J = j, l = 0;
	while( I < tam1 && J < tam2 && s1[I] == s2[J] )	I++, J++, l++;
	if( l >= k ) ans = max( ans, solve( I, J ) + l );
	ans = max( ans, solve( i+1, j ) );
	ans = max( ans, solve( i, j+1 ) );
	return pd[i][j] = ans;
}
*/
int main(){
//	freopen("sequence.in", "r", stdin);
	int kk = 1;
	while( 1 ){
		k = readInt();
		if( !k ) break;
		scanf("%s", s1);
		scanf("%s", s2);
//		if( kk == 199 ) printf("%d\n%s\n%s\n", k, s1, s2);
		tam1 = strlen( s1 );
		tam2 = strlen( s2 );
		rep( i, 0, tam1+1 ) rep( j, 0, tam2+1 ) pd[i][j][0] = pd[i][j][1] = -1;
		printf("%d\n", solve( 0, 0, 0) );
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}

