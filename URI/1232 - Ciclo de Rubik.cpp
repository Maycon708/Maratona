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

int v[54];

void rotate(int a, int b, int c, int d, int e, int f, int g, int h) {
    int x = v[h], y = v[g];
    v[h] = v[f]; v[g] = v[e];
    v[f] = v[d]; v[e] = v[c];
    v[d] = v[b]; v[c] = v[a];
    v[b] = x; v[a] = y;
}

void adjust(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    int x = v[j], y = v[k], z = v[l];
    v[j] = v[g]; v[k] = v[h]; v[l] = v[i];
    v[g] = v[d]; v[h] = v[e]; v[i] = v[f];
    v[d] = v[a]; v[e] = v[b]; v[f] = v[c];
    v[a] = x; v[b] = y; v[c] = z;
}

void F() {
    rotate(0, 1, 2, 5, 8, 7, 6, 3);
    adjust(33, 34, 35, 45, 48, 51, 11, 10, 9, 44, 41, 38);
}

void B() {
    rotate(26, 25, 24, 21, 18, 19, 20, 23);
    adjust(29, 28, 27, 36, 39, 42, 15, 16, 17, 53, 50, 47);
}

void L() {
    rotate(36, 37, 38, 41, 44, 43, 42, 39);
    adjust(0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33);
}

void R() {
    rotate(45, 46, 47, 50, 53, 52, 51, 48);
    adjust(8, 5, 2, 35, 32, 29, 26, 23, 20, 17, 14, 11);
}

void U() {
    rotate(27, 28, 29, 32, 35, 34, 33, 30);
    adjust(2, 1, 0, 38, 37, 36, 24, 25, 26, 47, 46, 45);
}

void D() {
    rotate(9, 10, 11, 14, 17, 16, 15, 12);
    adjust(6, 7, 8, 51, 52, 53, 20, 19, 18, 42, 43, 44);
}


inline bool ok() {
    rep( i, 0, 54 ){
        if( v[i] != i ) return 0;
    }
    return 1;
}

int main() {
    string s;
	while( cin >> s ){
		rep( i, 0, 54 ) v[i] = i;
            
        int cnt = 0;
        do{
            rep( i, 0, s.size() ){
                switch( s[i] ){
                    case 'F': F(); break;
                    case 'B': B(); break;
                    case 'R': R(); break;
                    case 'L': L(); break;
                    case 'U': U(); break;
                    case 'D': D(); break;
                    case 'f': F(); F(); F(); break;
                    case 'b': B(); B(); B(); break;
                    case 'r': R(); R(); R(); break;
                    case 'l': L(); L(); L(); break;
                    case 'u': U(); U(); U(); break;
                    case 'd': D(); D(); D(); break;
                }
            }
            cnt++;
        }while( !ok() );
        printf("%d\n", cnt );
    }
}

