#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		queue<char>odd, even;
		for(auto&i:s){
			if(i & 1)odd.push(i);
			else even.push(i);
		}

		while(1){
			if(odd.empty()){
				while(!even.empty()){
					cout << even.front();
					even.pop();
				}
			}
			else if(even.empty()){
				while(!odd.empty()){
					cout << odd.front();
					odd.pop();
				}
			}
			else{
				if(odd.front() < even.front()){
					cout << odd.front();
					odd.pop();
				}
				else{
					cout << even.front();
					even.pop();
				}
			}

			if(odd.empty() && even.empty())break;
		}
		cout << '\n';
	}

	return 0;
}