#include <bits/stdc++.h>
        
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pf push_front
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
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

int main(){

	int t, n, m;
	char c[100], s[100];
	map < string, string > mp;

	scanf("%d", &t );
	
	while( t-- ){
	
		mp.clear();
	
		scanf("%d%d", &n, &m );
		
		getchar();
		
		while( n-- ){
			gets( c );
			gets( s );
			mp[c] = s;
		} 
		
		while( m-- ){
			gets( c );
			int tam = strlen( c );
			string ss = "";
			rep( i, 0, tam ){
				if( c[i] < 'a' || c[i] > 'z' ){
					if( !mp.count( ss ) ){
						cout << ss;
					}
					else{
						cout << mp[ss];
					}
					ss = "";
					cout << c[i];
				}
				else{
					ss += c[i];
				}
			}
			if( !mp.count( ss ) ){
						cout << ss << "\n";
			}  
			else{
				cout << mp[ss] << "\n";
			}			
		}
		printf("\n");
	}

}
