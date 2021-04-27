#include <bits/stdc++.h>
using namespace std;

void toBin(int x, int n){
	string bin = "";
	int z = n;
	while(x > 0){
		bin += '0' + (x % 2);
		x /= 2;
		z--;
	}

	while(z--) bin += '0';
	
	reverse(bin.begin(), bin.end());
	cout << bin << endl;
}

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < (1 << n); i++){
		int x = i ^ (i >> 1);
		toBin(x, n);
	}
}