#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long n;
	cin >> n;

	const int MOD = 1e9+7;
	long res = 1;
	for(int i = 0; i < n; i++){
		res = (res * 2)%MOD;
	}
	cout << res;
}
 