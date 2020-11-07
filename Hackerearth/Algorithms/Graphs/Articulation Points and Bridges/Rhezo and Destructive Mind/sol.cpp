/** 
 *    author:  pankaj_m05
 *    created: 24.10.2020 10:43:23
**/ 
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& in, vector<int>& lo, vector<bool>& cut, int s, int p = -1, int timer = 0) {
  in[s] = lo[s] = timer;
	int d = 0;
	for (int& v : adj[s]) {
		if (v != p) {
			if (in[v] != -1) {
				lo[s] = min(lo[s], in[v]);
			} else {
				dfs(adj, in, lo, cut, v, s, timer + 1);
				lo[s] = min(lo[s], lo[v]);
				if (lo[v] >= in[s] && p != -1) {
					cut[s] = 1;
				}
			  ++d;
			}
		}
	}
	if (p == -1 && d > 1) {
		cut[s] = 1;
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> in(n, -1), lo(n, -1);
	vector<bool> cut(n, 0);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 0; i < n; ++i) {
		if (in[i] == -1) {
			dfs(adj, in, lo, cut, i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int v;
		cin >> v;
		if (cut[v - 1]) {
			cout << "Satisfied " << adj[v - 1].size();
		} else {
			cout << "Not Satisfied";
		}
		cout << '\n';
	}
  return 0;
}
