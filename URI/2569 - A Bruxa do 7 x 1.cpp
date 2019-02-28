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

int C( int n ){
	int ans = 0, aux = 1;
	while( n ){
		int x = n%10;
		if( x == 7 ) x = 0;
		ans += ( x * aux );
		aux *= 10;
		n /= 10;
	}
	return ans;
}

int main(){
	
	int a, b;
	char op;
	while( scanf("%d %c %d", &a, &op, &b ) != EOF ){
		a = C(a);
		b = C(b);
		if( op == '+' ) printf("%d\n", C(a+b) );
		else printf("%d\n", C(a*b) );
	}

}
