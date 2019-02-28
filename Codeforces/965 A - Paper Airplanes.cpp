#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int a, b, c, d;
	
	while( cin >> a >> b >> c >> d ){
		int t = (b+c-1)/c;
		printf("%d\n", (t*a+d-1)/d );	
	}
	
	
}