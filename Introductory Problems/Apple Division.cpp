#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	long diff = INT_MAX;
	for(int mask = 0; mask < (1<<n); mask++){
		long g1 = 0, g2 = 0;
		for(int j = 0; j < n; j++){
			if(mask & (1<<j) )
				g1 += a[j];
			else
				g2 += a[j];
		}
		diff = min(diff, abs(g1 - g2));
	}
	cout << diff;
}