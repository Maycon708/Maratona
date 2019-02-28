#include <bits/stdc++.h>
    
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n"
#define debugM(x,l,c) { rep( i, 0, l ){ rep(j, 0, c ) cout << x[i][j] << " ";  cout << "\n"; }};
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
    
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
    
using namespace std;
    
typedef pair <int, int> ii;
typedef long long int ll;

char s[25], S[25];
int tam;
int d[25];

void solve( int pos ){
	
	if( !pos ){
		s[pos] = '0';
		return;
	}
	int c = s[pos] - '0';
	int atual = ( c + 9 )%10;
	
	while( d[atual] == 2 ){
		atual = ( atual + 9 )%10;
	}
	if( atual > c ){
		d[c]--;
		solve( pos-1 );
		d[c]++;
	}
	if( d[atual] == 2 ) solve( pos );
	
	s[pos] = char( '0' + atual );
	d[c]--;

}

int main(){
	while( scanf("%s", s ) != EOF ){
		strcpy( S, s );
		rep( i, 0, 10 ) d[i] = 0;
		tam = strlen( s );
		rep( i, 0, tam ){
			int c = s[i] - '0';
			d[c]++;
			if( d[c] == 3 ){
				solve( i );
				break;
			}
		}
		int k;
		rep( i, 0, tam ){
			k = i;
			if( s[i] != S[i] ) break;
		}
		k++;
		rep( i, 0, 10 ) d[i] = 0;
		rep( i, 0, k ){
			int c = s[i] - '0';
			d[c]++;
		}
		rep( i, k, tam ){
			for( int j = 9; j >= 0; j-- ){
				if( d[j] < 2 ){
					d[j]++;
					s[i] = char( '0' + j );
					break; 
				}
			}
		}
		k = 0;
		while( s[k] == '0' ) k++;
		rep( i, k, tam ) printf("%c", s[i] );
		printf("\n");
	}
}

