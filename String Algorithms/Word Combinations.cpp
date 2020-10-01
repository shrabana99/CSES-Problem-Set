#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;

struct Node{
    bool isEnd;
    Node* child[26];
    Node() : isEnd(false){
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

void insertN(Node* root, string word){ 
	Node* cur = root;
    for(auto c: word){ 
        if(cur->child[c - 'a'] == nullptr)
            cur->child[c - 'a'] = new Node();
        cur = cur->child[c-'a'];
    }
    cur->isEnd = true;
}

int main(){
	string s;
	cin >> s;
	int n = s.size(), k;
	cin >> k;

	Node* root = new Node();
	for(int i = 0; i < k; i++){
		string x; cin >> x; insertN(root, x);
	}


	vector<long> dp(n+1, 0);
	dp[0] = 1;

	for(int i = 0; i < n; i++){
		Node* cur = root;
		for(int j = i; j < n; j++){
			if(cur->child[s[j] - 'a'] == nullptr)
				break;

			cur = cur->child[s[j] - 'a'];
			if(cur->isEnd)
				dp[j+1] = (dp[j+1] + dp[i]) % MOD;
		}
	}
	cout << dp[n];
}