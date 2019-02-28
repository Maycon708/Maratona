#include <bits/stdc++.h>
      
#define INF 1e+12
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 2110
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
      
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
      
using namespace std;
      
typedef pair <int, int> ii;
typedef long long int ll;

int main(){
    int n, l, c;
    char s[100];
    while( scanf("%d%d%d", &n, &l, &c ) != EOF ){
        int T = 0, t = 0;
        while( n-- ){
            scanf("%s", s );
            int len = strlen( s );
            if( t + len <= c ){
                t += len;
                t++;
            }
            else{
                T++;
                t = len + 1;
            }
        }
        T++;
        printf("%d\n", T/l + ( T%l != 0 ) );
    }   
    
}
