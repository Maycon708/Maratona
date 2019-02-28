#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, ans, t;
    scanf("%d", &t );
    while( t-- ){
        scanf("%d", &n );
        ans = n;
        for( int i = 1; i <= sqrt(n); i++ )
            if( i*i <= n ) ans--;
        cout << ans << endl;
    }
}
