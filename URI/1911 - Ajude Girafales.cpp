#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define D(x) cout << #x << " = " << x << endl;
#define D2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9


using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

map <string, string> mp;

int main(){

    int n, resp, t;
    string nome, assinatura;

    while(scanf("%d", &n) && n){
        
        mp.clear();
        resp = 0;

        while(n--){        
            cin >> nome >> assinatura;
            mp[nome] = assinatura;
        }

        scanf("%d", &t);

        while(t--){
            cin >> nome >> assinatura;
            
            int t = assinatura.size();
            int cnt = 0;

            string aux = mp[nome];
            rep(i, 0, t){
         
                if(assinatura[i] != aux[i]) cnt++;
                if(cnt==2){
                    resp++;
                    break;
                }
            }
        }
        printf("%d\n", resp);

    }  

  return 0;
}

