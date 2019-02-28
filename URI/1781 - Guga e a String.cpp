#include <bits/stdc++.h>
      
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 2110
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
typedef vector<ii> vec;

ll readInt();

inline bool V( char c ){
	return ( c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'|| c == 'o' || c == 'O' || c == 'u' || c == 'U' );
}

char s[300101];
int t1, t2, tam, aux[300101];

inline bool cmp ( ii a, ii b ){
	return a.F < b.F;
}

vec c, v;

void print( int cc, int vv ){
	rep( i, 0, v.size() ){
		int d = ( i + vv )%t1;
		v[i].F = v[d].S;
	}
	rep( i, 0, c.size() ){
		int d = ( i + cc )%t2;
	 	c[i].F = c[d].S; 
	}
	sort( all( v ), cmp );
	sort( all( c ), cmp );
	int i = 0, j = 0;
	rep( l, 0, tam ){
		if( aux[l] ){
			int u = v[i].S; i++;
			printf("%c", s[u] );
		}
		else{
			int u = c[j].S; j++;
			printf("%c", s[u] );
		}
	}
	printf("\n");
} 

int main(){
	int t = readInt();
	rep( kk, 1, t+1 ){
		printf("Caso #%d:\n", kk );
		v.clear(), c.clear();
		int cc = 0, vv = 0;
		scanf("%s", s );
		tam = strlen( s );
		rep( i, 0, tam ){
			aux[i] = V( s[i] );
			if( aux[i] ) v.pb( ii( i, i ) );
			else c.pb( ii( i, i ) );
		}
		t1 = v.size(), t2 = c.size();
		int q = readInt();
		while( q-- ){
			int op = readInt();
			if( !op ){
				int k = readInt();
				vv = ( vv + k );
			}
			if( op == 1 ){
				int k = readInt();
				cc = ( cc + k );
			}
			if( op == 2 ){
				print( cc, vv );
			}
		}
	}
}

ll readInt (){
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
