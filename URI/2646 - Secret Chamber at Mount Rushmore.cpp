#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m, mat[26][26];
	char a, b, aa[110], bb[111]; 
	while( scanf("%d%d", &n, &m ) != EOF ){
		memset( mat, 0, sizeof mat );
		for( int i = 0; i < 26; ++i ) mat[i][i] = 1;
		while( n-- ){
			cin >> a >> b;
			mat[a-'a'][b-'a'] = 1;
		}
		for( int k = 0; k < 26; ++k )
			for( int i = 0; i < 26; ++i )
				for( int j = 0; j < 26; ++j )
					mat[i][j] |= ( mat[i][k] & mat[k][j] );
		while( m-- ){
			scanf("%s%s", aa, bb );
			int t1 = strlen(aa), t2 = strlen(bb);
			bool aux = t1 == t2;
			for( int i = 0; i < t1 && aux; ++i ) aux &= ( mat[aa[i]-'a'][bb[i]-'a'] );
			printf("%s\n", aux ? "yes" : "no" );
		}
	}
}