#include<iostream>
#include<cstring>

using namespace std;

int main(){
    
    int n, t, v[50], r; 
    char p[60];
    
    
    cin >> n;
    
    while(n--){
		r=0;
		cin >> t;

		for(int i=0; i<t; i++){
			   cin >> v[i];
		}
		cin.ignore();
		gets(p);

		for(int i=0; i<t; i++){
			if(p[i]=='S' && v[i]<=2) {
				r++;
			}
			if(p[i]=='J' && v[i]>2) {
						r++;
			}
					   
		}
			cout << r << endl;
	}

    system("pause");
    return 0;
}

