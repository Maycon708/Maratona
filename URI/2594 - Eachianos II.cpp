#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back

#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

char text[1000000], pattern[1000000], aux[1000000];

vector <int> KMP()
{
    
    int n = strlen(text), m = strlen(pattern);
    vector <int> ret, T(m+2);
    
    int k = T[0] = -1;
    rep(i, 0, m)
    {
        while( ~k && pattern[i] != pattern[k] ) k = T[k];
        T[i + 1] = ++k;
    }
    
    
    k = 0;
    rep(i, 0, n)
    {
        while( ~k && text[i] != pattern[k] ) k = T[k];
        ++k;
        if( k == m ) ret.pb(i-m+1), k = T[k];
    }
    
    return ret;
    
}

int main()
{
    
    int n;
    while(cin >> n){ 
    
        
        rep(i, 0, n){
            
            text[0] = ' '; 
            gets(aux); 
            gets(aux);
            int t = strlen(aux);
            rep(j, 0, t) text[1+j] = aux[j];
            text[1+t] = ' ';
            text[2+t] = '\0';
        
            pattern[0] = ' '; 
            scanf("%s", aux );
            int t2 = strlen(aux);
            rep(j, 0, t2) pattern[1+j] = aux[j];
            pattern[1+t2] = ' ';
            pattern[2+t2] = '\0';
            
            vector <int> p = KMP();
            if(!p.size()) puts("-1");
            else{
                rep(j, 0, p.size()){
                    if(j) printf(" ");
                    printf("%d", p[j]);
                }   printf("\n");
            }
            
        }
        
    }

    return 0;
    
}
