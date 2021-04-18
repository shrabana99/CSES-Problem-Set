// https://www.geeksforgeeks.org/find-power-power-mod-prime/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
ll MOD = 1e9+7;

ll power(ll a, ll b, ll m){
    if(b == 0)
        return 1;

    ll res = power(a, b/2, m);
    res = (res*res)%m;

    if(b%2 == 1)
        res = (res*a)%m;
    return res;
}

int main(){
    ll n;
    cin >> n;
    while(n--){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, MOD-1), MOD) << "\n"; 
    }
}