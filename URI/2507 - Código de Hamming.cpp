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

void D( int n ){
	rep( i, 0, 21 ){
		if( n&(1 << (20-i) ) ) printf("1");
		else printf("0");
	}
	printf("\n");
}

int main(){
	int n, mp[100];
	while( scanf("%x", &n ) != EOF ){
		int aux = 0, cnt = 3;
		rep( i, 0, 5 ) aux |= (n&(1<<i));
		rep( i, 5, 22 ){
			mp[cnt] = i;
			if( n&(1<<i) ) 
				rep( j, 0, 5 ){
					if( cnt&(1<<j) ) aux ^= (1<<j);
				}
			bool check;
			do{
				check = 0;
				cnt++;
				rep( j, 0, 5 ) if( cnt == ( 1 << j ) ) check = 1;
			}while(check);
		}
		if( aux ) n ^= (1<<(mp[aux]));
		n >>= 5;
		printf("%x\n", n );
	}
}

