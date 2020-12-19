#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct item {
	int key, prior;
	item * l, * r;
	item() {
	}
	item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {
	}
};
typedef item * pitem;

void split (pitem t, int key, pitem & l, pitem & r) {
	if ( !t )
		l = r = NULL;
	else if ( key < t->key )
		split (t->l, key, l, t->l),  r = t;
	else
		split (t->r, key, t->r, r),  l = t;
}

void insert (pitem & t, pitem it) {
	if ( !t )
		t = it;
	else if ( it->prior > t->prior )
		split (t, it->key, it->l, it->r),  t = it;
	else
		insert (it->key < t->key ? t->l : t->r, it);
}

void merge (pitem & t, pitem l, pitem r) {
	if ( !l || !r )
		t = l ? l : r;
	else if ( l->prior > r->prior )
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
}

void out_tree(pitem r) {
	if ( !r )
		return;
	cout << r->key << ' ' << r->prior << endl;
	out_tree(r->l);
	out_tree(r->r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m;
	cin >> n >> m;

	pitem r = NULL;
	for ( int i = 0; i < m; ++i ) {
		char c;
		cin >> c;

		if ( c == 'M' ) {
			int x, a;
			cin >> x >> a;
			insert(r, new item(a, -x));
		}
		else {
			int y, b;
			cin >> y >> b;

			pitem t1, t2, t3;
			split(r, b - 1, t2, t3);

			if ( !t3 || t3->prior < -y ) {
				cout << "-1\n";
				merge(r, t2, t3);
				continue;
			}

			t1 = t3;
			int ans = t1->key;
			while ( t1 && t1->prior >= -y ) {
				ans = t1->key;
				t1 = t1->l;
			}
			cout << ans << endl;
			merge(r, t2, t3);
		}
	}

	//out_tree(r);

	return 0;
}