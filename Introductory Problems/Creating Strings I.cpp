#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string s;
	cin >> s;

	sort(s.begin(), s.end());
	vector<string> permutations;

	do{
		permutations.push_back(s);
	}
	while(next_permutation(s.begin(), s.end()));

	cout << permutations.size() << endl;
	for(auto x: permutations){
		cout << x << endl;
	}
}