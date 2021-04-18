#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].second >> a[i].first; // {r,l}
    }

    sort(a.begin(), a.end());

    int ans = 0, right = -1;
    for(auto x: a){
        if(x.second >= right){
            ans++;
            right = x.first;
        }
    }
    cout << ans;
}

