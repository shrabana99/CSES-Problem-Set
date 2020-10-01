#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	if(n%4 == 0 || n%4 == 3){
		cout << "YES\n";
		vector<int> a, b;

		if(n%4 == 0){
			for(int i = 0; i < n/4; i++){
				a.push_back(i*4 + 1);
				a.push_back(i*4 + 4);

				b.push_back(i*4 + 2);
				b.push_back(i*4 + 3);
			}
		}
		else{
			a.push_back(1);
			a.push_back(2);  // 1 2 3    4 5 6 7
			b.push_back(3);

			for(int i = 0; i < n/4; i++){
				a.push_back(i*4 + 4);
				a.push_back(i*4 + 7);

				b.push_back(i*4 + 5);
				b.push_back(i*4 + 6);
			}
		}

		cout << a.size() << " ";
		for(int x: a)
			cout << x << " ";
		cout << b.size() << " ";
		for(int x: b)
			cout << x << " ";
	}	
	else 
		cout << "NO\n";
}
 