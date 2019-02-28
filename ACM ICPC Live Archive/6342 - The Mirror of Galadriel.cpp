#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }
#define all(s) s.begin(), s.end()

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int main(){
	
	int t;
	char s[20], aux[20];
	
	scanf("%d", &t );
	while( t-- ){
		set<string> st;
		scanf("%s", s );
		int tam = strlen(s);
		rep( i, 0, tam ){
			int k = 0;
			rep( j, i, tam ){
				aux[k++] = s[j];
				aux[k] = '\0';
				st.insert(aux); 
			}
		}
		bool aa = 1;
		for( auto x : st ){
			string s = x;
			reverse( all(s) );
			if( !st.count(s) ){
				aa = 0;
				break;
			}
		}
		printf("%s\n", aa? "YES" : "NO" );
	}
	
	return 0;
}
