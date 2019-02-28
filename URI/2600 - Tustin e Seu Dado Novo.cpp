#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for( int i = a; i < b; i++ )

void solve(){

	int v[10], a[] = { 0, 1, 2 }, b[] = { 5, 3, 4 };
	bool aux = 1;
	set<int> st;
	rep( i, 0, 6 ) scanf("%d", &v[i] ), aux &= ( v[i] >= 1 && v[i] <= 6 ), st.insert(v[i]);
	rep( i, 0, 3 ){
		if( v[a[i]] + v[b[i]] != 7 ) aux = 0;
	}	
	if( aux && st.size() == 6 ) printf("SIM\n");
	else printf("NAO\n");

}

int main(){
    int t;
    scanf("%d", &t );
	while( t-- ) solve();
}
