#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;
const int base = 31;

int occurance(string &a, string &b){
	int cnt = 0;
	int na = a.size(), nb = b.size();
	if(nb > na) 
		return cnt;

	vector<int> pi(nb, 0);
	for(int i = 1; i < nb; i++){
		int j = pi[i-1];
		while(j > 0 && b[i] != b[j]){
			j = pi[j-1];
		}
		if(b[i] == b[j])
			j++;
		pi[i] = j;
	}

	int i = 0, j = 0;
	while(i < na){
		if(a[i] == b[j])
			i++, j++;
		if(j == nb){
			cnt++;
			j = pi[j-1];
		}
		else if(i < na && a[i] != b[j]){
			if(j == 0)
				i++;
			else
				j = pi[j-1];
		}
	}

	return cnt;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << occurance(a, b);
}