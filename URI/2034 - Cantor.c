#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define rep(i, a, b) for ( i = (a); i < (b); i++)

typedef long long int ll;

ll readInt();

ll n, v[100], pd[100][2][2];
char s1[100];
int TAM;

ll solve( int pos, int prefix, int num ){
	int i;
	if( pos == TAM ) return 1;
	if( pd[pos][prefix][num] != -1 ) return pd[pos][prefix][num];
	ll ans = 0;
	if( prefix ){
		int u = s1[pos] - '0';
		rep( i, 0, u ){
			if( num || i )
				if( v[i] ) ans += solve( pos+1, 0, 1 );
		}
		if( v[u] ) ans += solve( pos+1, 1, 1 );
	}
	else{
		rep( i, 0, n ){
			if( num || i )
				if( v[i] ) ans += solve( pos+1, 0, 1 );
		}
	}
	if( !num ) ans += solve( pos+1, 0, 0 );
	return pd[pos][prefix][num] = ans;
}

void convert( ll d, char c[] ){
	int i = 0;
	char s[100];
	char aux[] = {"0123456789"};
	while( d ){
		int u = d%n;
		s[i] = aux[u];
		d /= n;
		i++;	
	}
	s[i] = '\0';
	int tam = strlen( s );
	rep( i, 0, tam ){
		c[i] = s[tam-i-1];
	}
	c[tam] = '\0';
	return;
}

int main(){
	char s[100], s2[100];
	int i;
	while( 1 ){
		ll d = readInt();
		ll h = readInt();
		n = readInt();
		scanf("%s", s );
		if( d == -1 ) break;
		rep( i, 0, n ) v[i] = ( s[i] == 'S' );
		convert( d-1, s1 );
		TAM = strlen( s1 );
		memset( pd, -1, sizeof pd );
		ll ans = solve( 0, 1, 0 );
		convert( h, s1 );
		TAM = strlen( s1 );
		memset( pd, -1, sizeof pd );
		ll ans2 = solve( 0, 1, 0 );
		printf("%lld\n", ans2 - ans );
	}


}

ll readInt () {
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while (1) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = 1;
    else result = ch-'0';
    while (1) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}


