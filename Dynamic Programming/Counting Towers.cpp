#include <bits/stdc++.h>
using namespace std;

const long MOD = 1e9+7, maxN = 1e6+5;

long dp[maxN][2]; 

int main(){

	int t;
	cin >> t; 
	// dp[i][0] = no mid split
	// dp[i][1] = a  mid split

	/*
		|_ _ _| only one way hence dp[i][0] += dp[i-1][1] 
		|_ | _|  

		|_ _ _|  
		|_ _ _|  
		or
		|     |  2 way hence dp[i][0] += dp[i-1][0] * 2 
		|_ _ _| 
		
		in total , dp[i][0] += dp[i-1][1] + dp[i-1][0] * 2
	
	*/

	dp[1][0] = dp[1][1] = 1ll;
	for(int i = 2; i < maxN; i++){
		dp[i][0] = (dp[i-1][1] + dp[i-1][0] * 2) % MOD;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 4) % MOD;
	}

	while(t--){
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1]) % MOD << endl;
	}

}
