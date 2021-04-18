#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, sum;
    cin >> n >> sum;
    
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    int i = 0, j = n-1;
    while(i < j){
        if(a[i].first + a[j].first < sum)
            i++;
        else if(a[i].first + a[j].first > sum)
            j--;
        else{
            cout << a[i].second << " " << a[j].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}

