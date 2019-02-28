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

int l, c, mat[400][400];

int solve(){
	int cont = 0, I;
	rep( i, 0, l ){
		if( ( mat[i][0] - 1 )/c == i ) continue;
		rep( j, i, l ) if( ( mat[j][0] - 1 )/c == i ){
			I = j; 
			break;
		}
		swap( mat[i][0], mat[I][0] );
		cont++;
	}
//	debugM( mat, l, c )
	rep( j, 0, c ){
		if( mat[0][j]%c == (j+1)%c ) continue;
		rep( i, j, c ) if( mat[0][i]%c == (j+1)%c ){
			I = i;
			break;
		}
		swap( mat[0][j], mat[0][I] );
		cont++;
		
//		debugM( mat, l, c )
	}
	return cont;
}

int main(){

	while( scanf("%d%d", &l, &c ) != EOF ){
		bool aux = 1;
		rep( i, 0, l ){
			rep( j, 0, c ){
				mat[i][j] = readInt();
			}
		}
		rep( i, 0, l )
			rep( j, 1, c ){
				int n = ( mat[i][j] - 1 )/c;
				int m = ( mat[i][j-1] - 1 )/c;
				if( n != m ){
					aux = 0;
					goto resp;
				}
			}
			
		rep( i, 1, l )
			rep( j, 0, c ){
				int n = ( mat[i][j] )%c;
				int m = ( mat[i-1][j] )%c;
				if( n != m ){
					aux = 0;
					goto resp;
				}	
			}
		resp: 
			if( aux ) printf("%d\n", solve() );
			else printf("*\n");
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

