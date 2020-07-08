#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int,int>>seg(n);
	priority_queue<tuple<int,int,int>>q;
	priority_queue<pair<int,int>>in;
	vector<int>res;

	for(int i=0;i<n;++i){
		int l, r;
		cin >> l >> r;

		seg[i].first = l;
		seg[i].second = r;
		
		q.push(make_tuple(-l, 1, i));
		q.push(make_tuple(-r, 0, i));
	}

	while(!q.empty()){
		int p, t, i;
		tie(p, t, i) = q.top();
		q.pop();

		if(t == 1){
			//cout << "add " << i << '\n';
			in.push({seg[i].second, i});
			k--;

			if(k < 0){
				int out_i = in.top().second;
				in.pop();

				seg[out_i].second = -1;
				//cout << "rem " << out_i << '\n';
				k++;
				res.push_back(out_i + 1);
			}
		}
		else{
			if(seg[i].second != -1)k++;
		}
	}

	cout << res.size() << '\n';
	for(auto&i:res)cout << i << ' ';
		cout << '\n';

	return 0;
}