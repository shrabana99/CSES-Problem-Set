#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long n;
	cin >> n;

	int count5 = 0;
	while(n){
		count5 += (n/5);
		n /= 5;
	}
	cout << count5;
}
 