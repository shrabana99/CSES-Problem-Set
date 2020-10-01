#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;

long power(int a, int b){
	if(b == 0)
		return 1;

	long res = power(a, b/2);
	res = (res * res)%MOD;
	if(b%2 == 1)
		res = (res * a)%MOD;
	return res;
}

int main(){
	int n;
	cin >> n;
	if( (n * (n+1)) % 4 ){
		cout << "0\n"; 
		return 0;
	}
	int total = (n*(n+1))/4;
	/*long dp[n+1][total+1];
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= total; j++){
			dp[i][j] = dp[i-1][j];
			if(j-i >= 0)
				dp[i][j] = (dp[i][j] + dp[i-1][j-i])%MOD;
			//cout << dp[i][j] << " ";
		}//cout << endl;
	}
	*/

	long dp[total + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = total; j >= 0; j--){
			if(j-i >= 0)
				dp[j] = (dp[j] + dp[j-i])%MOD;
		}
	}
	cout << (dp[total] * power(2, MOD-2) ) %MOD;
}