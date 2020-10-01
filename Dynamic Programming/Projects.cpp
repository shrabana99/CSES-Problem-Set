#include <bits/stdc++.h>
 
using namespace std;

struct Project
{
	int start, end, profit;
};

int main(){
	int n;
	cin >> n;

	Project a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i].start >> a[i].end >> a[i].profit;

	// sort by inc order of end tiime
	sort(a, a+n, [] (const Project A, const Project B) {
		return A.end < B.end;
	});

	long dp[n];  // dp[i] : profit upto ith job
	memset(dp, 0, sizeof(dp));

	dp[0] = a[0].profit;
	for(int i = 1; i < n; i++){
		int l = 0, r = i-1;
		// find in the range(l, r) a job whose endtime <= starttime of current job
		while(l <= r){
			int md = (l + r)/2;
			if(a[md].end >= a[i].start)
				r = md - 1;
			else
				l = md + 1;
		}

		// ignoring current job
		dp[i] = dp[i-1];
		// considering current job
		long profit = a[i].profit;
		if(r != -1)
			profit += dp[r];
		dp[i] = max(dp[i], profit);
	}

	cout << dp[n-1];
}