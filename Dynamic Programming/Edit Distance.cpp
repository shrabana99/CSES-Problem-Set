#include <bits/stdc++.h>
 
using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	int na = a.size(), nb = b.size();

	int dp[na+1][nb+1];

	for(int i = 0; i <= na; i++){
		for(int j = 0; j <= nb; j++){
			if(i == 0 || j == 0)
				dp[i][j] = i+j;

			else{
				if(a[i-1] == b[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
			}
			//cout << dp[i][j] << " ";
		}//cout << endl;
	}

	cout << dp[na][nb];
}