#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i < n; i++){
        long long x; 
        cin >> x;
        sum += x;
    }

    sum = (n *(n+1))/2 - sum;
    cout << sum;
}