#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int main(){
      
    stack<char> s;
      
    int n, aux;
      
    char c[3000], r[3000];
      
    while(cin>>n && n){
        string res="";
        
        for (int i = 0; i < n; i++) 
            scanf(" %c", &c[i]);
        for (int i = 0; i < n; i++) 
            scanf(" %c", &r[i]);
         
        c[n] = r[n] = '\0';
          
//      e t d a
//		d a t e    
          
        s.push(c[0]);
        res+="I";
        int i=0, k=1;
        while(i<n){
            if(!s.empty() && s.top()==r[i]){
                s.pop();
                res+="R";
                i++;
            }
            else{
                if(k>=n){
                    res+=" Impossible";
                    break;
                }
                else{
                    s.push(c[k]);
                    res+="I";
                    k++;
                }
            }
        }
        
        cout << res << endl;
        while(!s.empty())s.pop();
    }
      
    return 0;
}
