#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<int> adj[], vector<bool> &vis){
	vis[curr] = true;
	for(auto a: adj[curr]){
		if(!vis[a]){
			dfs(a, adj, vis);
		}
	}
}

int main() {
	// your code goes here
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	int a, b;
	for(int i=1; i<=m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<bool> vis(n+1, false);
	int count = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i, adj, vis);
			count++;
		}
	}
	
	if(count == 1 && m == n-1){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}