#include <bits/stdc++.h>
using namespace std;

const long MOD = 1e9+7, maxN = 1e6+5;


int main(){

	string s;
	cin >> s;

	int n = s.size(); 

	// z[i]: length of the longest common prefix b/w s and suffix start from i(s.substr(i, n))
	int z[n];
	memset(z, 0, sizeof(z));

	int left = 0, right = 0; // boundaries of z index
	for(int i = 1; i < n; i++){ // z[0] is always 0
		if(i <= right){ // if currend index is inside the window 
			// use the value of equivalent position ie (i - left)
			// however, the z[i] + i should not exceed right side of the boundary 
			z[i] = min(z[i - left], right - i + 1); 
		}

		// extend the current window if possible
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;

		// update current window
		if(i + z[i] - 1 > right)
			left = i, right = i + z[i] - 1;

		if(i + z[i] == n){ 
			cout << n - z[i] << " ";
		} 

	}
	cout << n << endl;
}
