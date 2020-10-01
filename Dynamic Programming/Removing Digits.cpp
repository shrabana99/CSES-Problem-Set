#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;

int main(){
	int n;
	cin >> n;

	long dp[n+11];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= 9; i++)
		dp[i] = 1;

	for(int i = 10; i <= n; i++){
		int num = i;
		dp[i] = INT_MAX;

		while(num){
			int digit = num%10;
			num /= 10;
			dp[i] = min(dp[i], dp[i - digit] + 1);
		}
	}

	cout << dp[n];
}