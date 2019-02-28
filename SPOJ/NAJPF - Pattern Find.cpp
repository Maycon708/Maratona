#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
#define MAXN 1001001 
int pi[MAXN], res[MAXN], nres;
void kmp(string text, string pattern){
    nres = 0;
    pi[0] = -1;
    rep(i, 1, pattern.size()){
        pi[i] = pi[i-1];
        while (pi[i] >= 0 && pattern[pi[i]+1] != pattern[i])
            pi[i] = pi[pi[i]];
        if (pattern[pi[i]+1] == pattern[i])
            ++pi[i];
    }
    int k = -1;  //k+1 eh o tamanho do match atual
    rep(i, 0, text.size()){
        while (k >= 0 && pattern[k+1] != text[i])
            k = pi[k];
        if (pattern[k+1] == text[i])
            ++k;
        if (k+1 == pattern.size()){
            res[nres++] = i-k;
            k = pi[k];
        }
    }
}

int main(){
	int test;
	string t, p;
	cin >> test;
	while( test-- && cin >> t >> p ){
		kmp(t, p);
		if( nres ){
			printf("%d\n", nres );
			rep( i, 0, nres ) printf("%d%s", res[i]+1, i+1==nres? "\n":" ");
		}
		else printf("Not Found\n");
		if( test != 1 ) printf("\n");
	}
}

