#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair <int, int> ii;
 
const int MOD = 1000000007;
const int mod = MOD;
 
vector<long long int> fat;

long long int n, m,  bit[2100][2100];

int ma[2100][2100];
 
long long int fast_pow(long long int b, int p){
    if (p==0) return 1;
    if (p==1) return b;
    if (p%2 == 0){
        long long int ret = fast_pow(b,p/2);
        return (ret*ret)%mod;
    }else{
        return (fast_pow(b,p-1)*b)%mod;
    }
}

void update(int x , int y , int val){
    int y1;
    while (x <= n){
        y1 = y;
        while (y1 <= m){
            bit[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}

long long int query(int x,int y){
    
	long long int sum= 0;         
    
	while(x){
        int y1 = y;
        
        while(y1){
	        sum += bit[x][y1];
	        y1 -= (y1&-y1);
        }
        
        x -= (x & -x);
    }
    
    return sum;
}
 
int main(){
     
    int a, b, k, d=1;
    char c[2000];
    string s;
    stringstream ss;
     
    fat.push_back(1);
    for(int i=1; i<10000001; i++){
        long long int kk = (i*fat[i-1])%MOD;
        fat.push_back(kk);
    }
     
    cin >> n >> m;
     
    while(gets(c)){
         
        int v[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
         
        s = ""; k = 0;
         
        int t = strlen(c);
         
        for(int i = 0; i < t; i++){
            if(c[i]>='0' && c[i]<='9'){
                s+=c[i];
            }
            else{
                ss << s;
                ss >> v[k];
                ss.clear();
                s="";
                k++;
            }
        }
         
                ss << s;
                ss >> v[k];
                ss.clear();
                s="";
                k++;
         
        switch (k){
             
            case 3:{
            	int x = v[0], y = v[1], z = v[2];
                ma[x][y] += z;
                update(x,y,z);                
                break;
            }
             
            case 2:{
            	int x = v[0], y = v[1], z = v[2]; 
                update(x,y,-ma[x][y]);
				ma[x][y] = 0;
                break;
            }
             
            case 5:{
                int x1 = v[0];
	            int y1 = v[1];
	            int x2 = v[2];
	            int y2 = v[3];
	            int cen = v[4];
	            long long int cont = query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1);
                 
                long long int inv = fast_pow(((fat[(v[4])]%MOD) * (fat[(cont-1)]%MOD))%MOD, mod-2);
                
				long long int fu = ((fat[abs(cont+v[4]-1)]%MOD) * (inv%MOD))% mod;
                 
				//cout << fat[cont+v[4]-1] << " " << inv << endl;
                 
                if(cont==0) fu = 0; 
                
                printf("Day #%d: %lld\n", d, fu);
                 
                d++;
                 
                break;
            }
             
        }
         
    }
     
     
    return 0;
}
