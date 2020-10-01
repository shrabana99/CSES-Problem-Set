#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int n, sum;
	cin >> n >> sum;
	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];

	vector<int> dp(sum+1, INT_MAX);

	dp[0] = 0;
	for(int coin: coins){
		for(int i = 0; i < sum; i++){
			if(i+coin <= sum && dp[i] != INT_MAX)
				dp[i+coin] = min(dp[i+coin], dp[i] + 1);
		}
	}
	cout << (dp[sum] == INT_MAX ? -1 : dp[sum]);
}