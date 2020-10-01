#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string s;
	cin >> s;

	int n = s.size();

	vector<int> freq(26, 0);
	for(char x: s)
		freq[x-'A']++;

	int odd = 0, oddC = -1;
	for(int i = 0; i < 26; i++){
		if(freq[i]%2 == 1) // odd frequency
			odd++, oddC = i;
	}

	if((n%2 == 0 && odd) || (n%2 == 1 && odd != 1)){
		cout << "NO SOLUTION";
		return 0;
	}

	string newS;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < freq[i]/2; j++)
			newS += ('A' + i);
	}
	if(oddC != -1)
		newS += ('A' + oddC);

	for(int i = 25; i >= 0; i--){
		for(int j = 0; j < freq[i]/2; j++)
			newS += ('A' + i);
	}
	cout << newS;
}
 