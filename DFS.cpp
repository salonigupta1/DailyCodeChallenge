#include <iostream>
#include<vector>
#include<queue>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void dfshelper(int i, vector<vector<int>> adj, vector<bool> &vis){
    vis[i] = true;
    cout << i << " ";
    for(int x=0; x<adj[i].size(); x++){
        int child = adj[i][x];
        if(vis[child] == false) {
            dfshelper(child, adj, vis);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>>  adj)
{
    vector<bool> vis(1001, false);
    for(int i=0; i<adj.size(); i++){
        if(!vis[adj[i][0]]){
            dfshelper(i, adj, vis);
        }
    }
}

int main()
{
    OJ;
    return 0;
}