#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = a; i < b; i++ )

using namespace std;

int main(){

	int n, v[9], maior, D;
	scanf("%d", &n );
	while( n-- ){
		maior = 0;
		vector<int> V;
		map<int, int> cont;
		rep( i, 0, 9 ){
			scanf("%d", &v[i]);
		}
		rep( i, 0, 9 ){
			int diff;
			if( i % 3 == 0 ) diff = abs( v[i] - v[i + 1] );
			else diff = abs(v[i] - v[i - 1]);
			cont[diff]++;
			if( cont[diff] > maior ){
				maior = cont[diff];
				D = diff;
			}
		}
		rep( i, 0, 9 ){
			if( i%3 == 0 && abs( v[i] - v[i+1] ) != D && abs(v[i] - v[i+2]) != D ) V.push_back(v[i]);
			if( i%3 == 1 && abs( v[i] - v[i-1] ) != D && abs(v[i] - v[i+1]) != D ) V.push_back(v[i]);
			if( i%3 == 2 && abs( v[i] - v[i-1] ) != D && abs(v[i] - v[i-2]) != D ) V.push_back(v[i]);
		}
		rep( i, 0, (int)V.size() ){
			if( i ) printf(", ");
			else printf("Possiveis maletas: ");
			printf("%d", V[i] );
		}
		printf(";\n");
	}

	return 0;
}
