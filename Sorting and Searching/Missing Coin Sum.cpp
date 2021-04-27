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

	long res = 1;
	for(long i = 0; i < n; i++){
		if(arr[i] <= res){
			res += arr[i];
		}
		else 
			break;
	}

	cout << res << endl;
}
