#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;

int main(){
	int n, m;
	cin >> n >> m;

	long dp[n][m+1];
	int a[n];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < n; i++)
		cin >> a[i];

	// base case
	if(a[0] == 0){
		for(int i = 1; i <= m; i++)
			dp[0][i] = 1;
	}
	else
		dp[0][a[0]] = 1;

	for(int i = 1; i < n; i++){
		if(a[i] == 0){
			for(int j = 1; j <= m; j++){
				dp[i][j] = dp[i-1][j];
				if(j-1 >= 1)
					dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
				if(j+1 <= m)
					dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
			}

		}
		else{
			int j = a[i];
			dp[i][j] = dp[i-1][j];
			if(j-1 >= 1)
				dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
			if(j+1 <= m)
				dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
		}
	}
	
	long sum = 0;
	for(int i = 1; i <= m; i++)
		sum = (sum + dp[n-1][i]) % MOD;

	cout << sum;

}