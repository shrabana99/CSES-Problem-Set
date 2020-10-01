#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int n, sum;
	cin >> n >> sum;

	int prices[n], pages[n];
	for(int i = 0; i < n; i++)
		cin >> prices[i];
	for(int i = 0; i < n; i++)
		cin >> pages[i];

	int dp[n+1][sum+1]; // no of pages upto ith book and jth sum
	memset(dp, 0, sizeof(dp));	

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= sum; j++){
			if(j - prices[i] >= 0)
				dp[i+1][j] = max(dp[i][j], dp[i][j-prices[i]] + pages[i]);
			else
				dp[i+1][j] = dp[i][j];
		}
	}

	cout << dp[n][sum];

}