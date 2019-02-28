#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

bool C1( int mat[5][5] ){
	rep( i, 0, 3 ) if( mat[i][i] ) return 1;
	return 0;
}
bool C2( int mat[5][5] ){
	rep( i, 0, 3 ) if( mat[i][2-i] ) return 1;
	return 0;
}

int main(){
	
	int m[5][5], sl[5], sc[5], sd[5];
	while(42){
		vector<ii> v;
		rep( i, 0, 3 ) sl[i] = sc[i] = sd[i] = 0;
		rep( i, 0, 3 )
			rep( j, 0, 3 ){
				scanf("%d", &m[i][j] );
				sl[i] += m[i][j];
				sc[j] += m[i][j];
				if( !m[i][j] ) v.pb( ii( i, j ) );
			}
		if( !C1(m) ){
			m[0][0] = ( sl[1] + sl[2] - sl[0] ) >> 1;
			m[1][1] = ( sl[2] + sl[0] - sl[1] ) >> 1;
			m[2][2] = ( sl[1] + sl[0] - sl[2] ) >> 1;
		}
		else if( !C2(m) ){
			m[0][2] = ( sl[1] + sl[2] - sl[0] ) >> 1;
			m[1][1] = ( sl[2] + sl[0] - sl[1] ) >> 1;
			m[2][0] = ( sl[1] + sl[0] - sl[2] ) >> 1;
		}
		else{
			rep( i, 0, 3 )
				sd[0] += m[i][i], sd[1] += m[i][2-i];
			int ans = max( sd[0], sd[1] );
			rep( i, 0, 3 )
				ans = max( ans, max( sl[i], sc[i] ) );
			rep( i, 0, v.size() ){
				int a = v[i].F;
				int b = v[i].S;
				m[a][b] = ans - max( sl[a], sc[b] );
			}
		}
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				if( j ) printf(" ");
				printf("%d", m[i][j] );
			}
			printf("\n");
		}
		break;
	}
}

