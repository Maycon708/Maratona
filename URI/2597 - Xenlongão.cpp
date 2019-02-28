#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, ans, t;
    scanf("%d", &t );
    while( scanf("%d", &n ) != EOF ){
        ans = n;
        for( int i = 1; i <= sqrt(n); i++ )
            if( i*i <= n ) ans--;
        cout << ans << endl;
    }
}
