#include <bits/stdc++.h>
using namespace std;

const long MOD = 1e9+7, maxN = 1e6+5;


int main(){

	long n;
	cin >> n;
	long arr[n];

	for(long i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr, arr + n);

	long mid;
	if(n % 2)
		mid = arr[n/2];
	else 
		mid = (arr[n/2] + arr[(n+1)/2]) / 2;

	long sum = 0;
	for(long i = 0; i < n; i++){
		sum += abs(mid - arr[i]);
	}
	cout << sum;

}
