#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> d1(n, 0), d2(n, 0);

    int len = 0, pos = -1;
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r ? 0 : min(r-i+1, d1[r+l-i]));

        while(i+k < n && i-k >= 0 && s[i+k] == s[i-k])
            k++;
        d1[i] = k--;

        if(i+k > r)
            l = i-k, r = i+k;

        if(len < d1[i]*2-1){
            len = d1[i]*2 - 1;
            pos = i - d1[i] + 1;
        }//cout << d1[i] << " ";
    }//cout << endl;

    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r ? 0 : min(r-i+1, d2[l+r-i+1]));

        while(i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])
            k++;
        d2[i] = k--;

        if(i+k > r)
            l = i-k-1, r = i+k;

        if(len < d2[i]*2){
            len = d2[i]*2;
            pos = i - d2[i];
        }//cout << d2[i] << " ";
    } 
    
    cout << s.substr(pos, len);

}