#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> coins(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> coins[i];
		sum += coins[i];
	}

	vector<int> dp(sum + 1, 0);

	dp[0] = 1; 
	for(int coin: coins){
		for(int j = sum; j >= 0; j--){
			if(dp[j] && j+coin <= sum)
				dp[j + coin] = 1;
		}
	}

	int cnt = 0;
	for(int i = 1; i <= sum; i++)
		cnt += dp[i];

	cout << cnt << endl;
	for(int i = 1; i <= sum; i++){
		if(dp[i])
			cout << i << " ";
	}

}