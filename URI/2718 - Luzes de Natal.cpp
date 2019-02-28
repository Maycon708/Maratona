#include <bits/stdc++.h>

#define pb push_back
 
using namespace std;

typedef long long int ll;
 
int main() {
 
    ll t, n;
    string s;
    
    cin >> t;
    while( t-- ){
        cin >> n;
        s.clear();
        while(n){
            if(n&1) s.pb('1');
            else s.pb('0');
            n /= 2;
        }
        int ans = 0, cont = 0;
        reverse( s.begin(), s.end() );
        for( int i = 0; i < s.size(); i++ ){
            if( s[i] == '1' ) cont++;
            else cont = 0;
            ans = max( ans, cont );
        }
        cout << ans << endl;
    }
 
    return 0;
}
