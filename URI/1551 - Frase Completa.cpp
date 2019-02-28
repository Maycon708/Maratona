#include<iostream>
#include<map>
#include<cstring>

using namespace std;

map <char, int> mp;
map <char, int> :: iterator it;

int main(){
    
    int n, t;
    char s[1100];
    
    cin >> n;
    cin.ignore();
    
    while(n--){
               gets(s);
               t=strlen(s);
               for(int i=0; i<t; i++){
                       if(s[i]>='a' and s[i]<='z') mp[s[i]]=1;
                       }   
               t=mp.size();
               
               if(t<13) cout << "frase mal elaborada" << endl;
               else{
                    if(t==26) cout << "frase completa" << endl;
                    else cout << "frase quase completa" << endl;
                    }
               mp.clear();
               }
    system("pause");
    return(0);
}

