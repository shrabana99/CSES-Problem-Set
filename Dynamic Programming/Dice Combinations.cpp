#include <bits/stdc++.h>
 
using namespace std;

int main(){
	const int MOD = 1e9+7;

	int sum ;
	cin >> sum;

	vector<long> dp(sum+1, 0);

	dp[0] = 1;
	for(int i = 0; i <= sum; i++){
		for(int j = 1; j <= 6; j++){
			if(i+j <= sum)
				dp[i+j] = (dp[i+j] + dp[i])%MOD;
		}
	}

	cout << dp[sum];
}