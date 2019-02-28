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

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int main(){

	ll t, k;
	string A, B, C, a, b, c;
	map < string, string > mp, mp2;
	map < string, string > :: iterator it;
	
	mp["0"] = "0000"; mp["1"] = "0001"; mp["2"] = "0010"; mp["3"] = "0011", mp["4"] = "0100";
	mp["5"] = "0101"; mp["6"] = "0110"; mp["7"] = "0111"; mp["8"] = "1000", mp["9"] = "1001";
	mp["A"] = "1010"; mp["B"] = "1011"; mp["C"] = "1100"; mp["D"] = "1101", mp["E"] = "1110";
	mp["F"] = "1111"; 
	
	for( it = mp.begin(); it != mp.end(); it++ ){
		mp2[ it -> S ] = it -> F;
	}
		
	scanf("%lld", &t );
	while( t-- ){
		
		scanf("%lld", &k );
		cin >> a >> b >> c;
		A = B = C = "";
		int mn = max( a.size(), max( b.size(), c.size() ) );
		rep( i, 0, ( mn - a.size() ) ) A += '0';
		rep( i, 0, ( mn - b.size() ) ) B += '0';
		rep( i, 0, ( mn - c.size() ) ) C += '0';
		
		rep( i, 0, a.size() ){
			string s; s += a[i];
			A += mp[s];
		}
		rep( i, 0, b.size() ){
			string s; s += b[i];
			B += mp[s];
		}
		rep( i, 0, c.size() ){
			string s; s += c[i];
			C += mp[s];
		}
		
		int cnt = 0;
		rep( i, 0, C.size() ){
			if( C[i] == '0' ){
				if( A[i] == '1' ) cnt++, A[i] = '0';
				if( B[i] == '1' ) cnt++, B[i] = '0';
			}
			else{
				if( A[i] == '1' || B[i] == '1' ) continue;
				B[i] = '1', cnt++;
			}
		}
		if( cnt > k ) printf("-1\n");
		else{
			rep( i, 0, C.size() ){
				if( cnt == k ) break;
				if( A[i] == '1' && B[i] == '1' ) A[i] = '0', cnt++;
			}
			string s;
			bool aux = 0;
			rep( i, 0, C.size() ){
				if( i%4 == 0 && i ){
					string S = mp2[s];
					if( S != "0" || aux ){
						aux = 1;
						cout << mp2[s];
					}
					s = "";
				}
				s += A[i];
			}
			cout << mp2[s] << endl;
			s = ""; aux = 0;
			rep( i, 0, C.size() ){
				if( i%4 == 0 && i ){
					string S = mp2[s];
					if( S != "0" || aux ){
						aux = 1;
						cout << mp2[s];
					}
					s = "";
				}
				s += B[i];
			}
			cout << mp2[s] << endl;
			s = "";
		}
		
	}

}
