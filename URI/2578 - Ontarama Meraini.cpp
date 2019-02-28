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

#define N 1000010

char m[N], t[N];

int main(){
	
	int cnt[26], cnt2[26];
	while( scanf("%s%s", t, m ) != EOF ){
		int t1 = strlen(t);
		int t2 = strlen(m);
		rep( i, 0, 26 ) cnt[i] = cnt2[i] = 0;
		rep( i, 0, t2 ) cnt[m[i]-'a']++;
		int j = 0, aux = 0, last = 0;
		ll ans = 0;
		rep( i, 0, t1 ){
			int u = t[i]-'a';
			if( !cnt[u] ){
				memset( cnt2, 0, sizeof cnt2 );
				aux = 0;
				j = i+1;
				continue;
			}
			while( cnt2[u]+1 > cnt[u] ){
				cnt2[t[j]-'a']--;
				j++;
				aux--;
			}
			cnt2[u]++;
			aux++;
			if( aux == t2 ){
				ans += (ll)( j - last + 1 ) * (ll)( t1 - i );
				last = j+1;
			}
		}
		printf("%lld\n", ans );
	}	

}
