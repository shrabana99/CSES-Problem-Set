#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int n;
	cin >> n;

	int a[n];
	long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	long dp[n][n]; // dp[i][j] = diff of score of player1 & player2

	for(int i = n-1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(i == j)
				dp[i][j] = a[i];
			else
				dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
		}
	}

	// let score of player1 & 2 is x, y
	// dp[0][n-1] = x - y
	// sum = x + y
	//sum + dp[0][n-1] = (x-y + x+y) = 2x
	cout << (dp[0][n-1] + sum)/2;
}