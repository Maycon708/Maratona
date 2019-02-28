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

char v[54];

void rotate(int a, int b, int c, int d, int e, int f, int g, int h) {
    char x = v[h], y = v[g];
    v[h] = v[f]; v[g] = v[e];
    v[f] = v[d]; v[e] = v[c];
    v[d] = v[b]; v[c] = v[a];
    v[b] = x; v[a] = y;
}

void adjust(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    char x = v[j], y = v[k], z = v[l];
    v[j] = v[g]; v[k] = v[h]; v[l] = v[i];
    v[g] = v[d]; v[h] = v[e]; v[i] = v[f];
    v[d] = v[a]; v[e] = v[b]; v[f] = v[c];
    v[a] = x; v[b] = y; v[c] = z;
}

void F(){
    rotate(0, 1, 2, 5, 8, 7, 6, 3);
    adjust(9, 12, 15, 45, 48, 51, 35, 32, 29, 36, 39, 42 );
}

void B(){
    rotate(26, 25, 24, 21, 18, 19, 20, 23);
    adjust( 27, 30, 33, 53, 50, 47, 17, 14, 11, 44, 41, 38 );
}

void L(){
    rotate(36, 37, 38, 41, 44, 43, 42, 39);
    adjust( 27, 28, 29, 18, 19, 20, 9, 10, 11, 0, 1, 2);
}

void R(){
    rotate(45, 46, 47, 50, 53, 52, 51, 48);
    adjust(15, 16, 17, 24, 25, 26, 33, 34, 35, 6, 7, 8 );
}

void U(){
    rotate(27, 28, 29, 32, 35, 34, 33, 30);
    adjust(38, 37, 36, 0, 3, 6, 51, 52, 53, 26, 23, 20 );
}

void D() {
    rotate(9, 10, 11, 14, 17, 16, 15, 12);
    adjust(8, 5, 2, 42, 43, 44, 18, 21, 24, 47, 46, 45 );
}

inline bool ok(){
    rep( i, 1, 9 ){
        if( v[i] != v[i-1] ) return 0;
    }
    rep( i, 10, 18 ){
        if( v[i] != v[i-1] ) return 0;
    }
    rep( i, 19, 27 ){
        if( v[i] != v[i-1] ) return 0;
    }
    rep( i, 28, 36 ){
        if( v[i] != v[i-1] ) return 0;
    }
    rep( i, 37, 45 ){
        if( v[i] != v[i-1] ) return 0;
    }
    rep( i, 46, 54 ){
        if( v[i] != v[i-1] ) return 0;
    }
    return 1;
}

int main() {
    string s;
    int t, u;
    cin >> t;
	while( t-- ){
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				int u = 36 + i * 3 + j;
				cin >> v[u];
			}
		}
		rep( i, 0, 3 ){
			rep( j, 0, 12 ){
				int k = ( j/3 ) * 9 + i * 3 + j%3;
				cin >> v[k];
			}
		}
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				int u = 45 + i * 3 + j;
				cin >> v[u];
			}
		}
        while( cin >> u && u ){
            switch( u ){
                case 1: F(); break;
                case 2: D(); break;
                case 3: B(); break;
                case 4: U(); break;
                case 5: L(); break;
                case 6: R(); break;
                case -1: F(); F(); F(); break;
                case -2: D(); D(); D(); break;
                case -3: B(); B(); B(); break;
                case -4: U(); U(); U(); break;
                case -5: L(); L(); L(); break;
                case -6: R(); R(); R(); break;
            }
        }
		if( ok() ) printf("Yes, grandpa!\n");
        else printf("No, you are wrong!\n");
    }
}

