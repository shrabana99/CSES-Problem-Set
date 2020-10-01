#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;

		if(a > b*2 || b > a*2){
			cout << "NO\n";
			continue;
		}

		a %= 3, b %= 3;
		if((a==0 && b==0) || (a==1 && b==2) || (a==2 && b==1) )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
 