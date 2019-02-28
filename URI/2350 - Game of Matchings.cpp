#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
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

int P[500010];
int pattern[500010], text[500010], n, m;

void pre_process( ){
	P[0] = 0;
	int j = 0;
	rep( i, 1, m ){
		while( (( pattern[i] <= j && pattern[j] != pattern[i]) ||
		(pattern[i] > j && pattern[j] != -1 ) ) && j ) j = P[j-1];
		if( (pattern[i] <= j && pattern[j] == pattern[i]) ||
			(pattern[i] > j && pattern[j] == -1) ) j++;
		P[i] = j;
	}
}

int KMP ( ){
	int j = 0, cnt = 0;
	rep( i, 0, n ){
		while( j > 0 && ( (text[i] <= j && text[i] != pattern[j]) || 
		(text[i] > j && pattern[j] != -1) ) )  j = P[j-1];
		if((text[i] <= j && text[i] == pattern[j])  || ( text[i] > j && pattern[j] == -1 )){
			j++;
			if( j == m ){
				cnt++;
				j = P[j-1];
			}
		}
	}
	return cnt;
}

int main(){
	int aux[26];
	char s[500010];
	while( scanf("%s", s ) != EOF ){
		scanf("%d", &m );
		rep( i, 0, m ) scanf("%d", &pattern[i] );
		memset( aux, -1, sizeof aux );
		n = strlen(s);
		rep( i, 0, n ){
			int u = s[i] - 'a';
			if( aux[u] == -1 ) text[i] = aux[u];
			else text[i] = i - aux[u];
			aux[u] = i;
		}
		memset( aux, -1, sizeof aux );
		rep( i, 0, m ){
			int u = pattern[i] - 1;
			if( aux[u] == -1 ) pattern[i] = aux[u];
			else pattern[i] = i - aux[u];
			aux[u] = i;
		}
		pre_process();
		printf("%d\n", KMP() );
	} 	
}

