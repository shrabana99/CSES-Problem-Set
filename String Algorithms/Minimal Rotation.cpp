#include <bits/stdc++.h>
using namespace std;

const long MOD = 1e9+7, maxN = 1e6+5;

// https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation

int main(){

	string s, S;
	cin >> s;

	S = s + s;
	int n = S.size(); 

	int f[n];
	memset(f, -1, sizeof(f));

	int k = 0; // Least rotation of string found so far

	for(int i, j = 1; j < n; j++){
        i = f[j - k - 1]; 

        while(i != -1 && S[j] != S[k + i + 1]) { 
            if (S[j] < S[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i]; 
        } // cout << j << " " << i << endl;
        if(S[j] != S[k + i + 1]){ // if sj != S[k+i+1], then i == -1
             
            if(S[j] < S[k]) {
                k = j; // cout << k << endl; 
            }
            f[j - k] = -1; 
        }
        else{  
        	f[j - k] = i + 1; 
        }

    }
    cout << S.substr(k, s.size()) ;

}
