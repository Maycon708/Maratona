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

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

char mat[1100][1100];
int sum[1100][1100], n, m;

inline bool C( int l ){
	rep( i, 0, n-l ){
		rep( j, 0, m-l ){
			if( mat[i][j] == '*' ) continue;
			int u = sum[i+l][j+l];
			if( j ) u -= sum[i+l][j-1];
			if( i ) u -= sum[i-1][j+l];
			if( i && j ) u += sum[i-1][j-1];		
			if( !u ) return 1;
		}
	}
	return 0;
}

int bb( int fim ){
	int ini = 0, mid;
	rep( i, 0, 200 ){
		mid = ( ini + fim + 1 )/2;
		if( C( mid ) ) ini = mid;
		else fim = mid-1;
	}
	return mid;
}

void Out( int l ){
	int cont = 0;
	rep( i, 0, n-l ){
		rep( j, 0, m-l ){
			if( mat[i][j] == '*' ) continue;
			int u = sum[i+l][j+l];
			if( j ) u -= sum[i+l][j-1];
			if( i ) u -= sum[i-1][j+l];
			if( i && j ) u += sum[i-1][j-1];		
			if( !u ){
				printf("%d %d\n", i+1, j+1 );
				cont++;
			}
		}
	}
	printf("%d in total.\n", cont );
}

int main(){
	int t = readInt();
	while( t-- ){
		n = readInt();
		m = readInt();
		
		rep( i, 0, n )
			scanf("%s", mat[i] );
		
		rep( i, 0, n ){
			rep( j, 0, m ){
				sum[i][j] =  ( mat[i][j] == '*' );
				if( i ) sum[i][j] += sum[i-1][j];
				if( j ) sum[i][j] += sum[i][j-1];
				if( i && j  ) sum[i][j] -= sum[i-1][j-1] ;
			} 
		}
		
		int ans = bb( min( n, m ) );
		printf("The side of the square is %d and the locations are:\n", ans +1 );
		Out( ans );
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

