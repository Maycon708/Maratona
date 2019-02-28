#include<iostream>
#include<math.h>

using namespace std;

int main(){
	
	int x1, y1, x2, y2;
	
	
	cin >> x1 >> y1 >> x2 >> y2;
	
	while(x1!=0 or y1!=0 or x2!=0 or y2!=0){
		
		
		
		if(x1!=0 or y1!=0 or x2!=0 or y2!=0){
		
			if(x1==x2 and y1==y2) cout << "0" << endl;
			if(x1==x2 and y1!=y2) cout << "1" << endl;
			if(x1!=x2 and y1==y2) cout << "1" << endl;
			
			if(x1>x2 and y1>y2){
				while(x1!=x2){
					x1=x1-1;
					y1=y1-1;
				}
				
				if(y1==y2) cout << "1" << endl;
				else cout << "2" << endl;
			}
			
			if(x1<x2 and y1<y2){
				while(x1!=x2){
					x1=x1+1;
					y1=y1+1;
				}
				
				if(y1==y2) cout << "1" << endl;
				else cout << "2" << endl;
			}
			
			if(x1<x2 and y1>y2){
				while(x1!=x2){
					x1=x1+1;
					y1=y1-1;
				}
				
				if(y1==y2) cout << "1" << endl;
				else cout << "2" << endl;
			}
			
			if(x1>x2 and y1<y2){
				while(x1!=x2){
					x1=x1-1;
					y1=y1+1;
				}
				
				if(y1==y2) cout << "1" << endl;
				else cout << "2" << endl;
			}
		}
		
		cin >> x1 >> y1 >> x2 >> y2;
	}
	return(0);
}
