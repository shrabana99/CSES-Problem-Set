#include <bits/stdc++.h>
 
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	int last = 0;
	dp[last++] = a[0];

	for(int i = 1; i < n; i++){
		int l = 0, r = last-1;
		while(l <= r){
			int md = (l + r)/2;
			if(dp[md] < a[i])
				l = md + 1;
			else
				r = md - 1;
		}

		if(l == last)
			dp[last++] = a[i];
		else
			dp[l] = min(dp[l], a[i]);
	}
	cout << last;
}