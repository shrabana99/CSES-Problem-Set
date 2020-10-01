#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    int res = 1;
    for(int i = 0, j = 0, cnt = 0; i < n; i++){
        if(s[i] == s[j]){
            cnt++;
            res = max(res, cnt);
        }
        else{
            cnt = 1;
            j = i;
        }
    }
    cout << res;
}