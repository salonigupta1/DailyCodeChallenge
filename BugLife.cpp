#include <iostream>
#include<vector>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool dfs(int curr, int color, vector<bool> &vis, vector<int>* adj, vector<int> &col){
    vis[curr] = true;
    col[curr] = color;
    for(int a: adj[curr]){
        if(!vis[a]){
            if(dfs(a, (color==1)?0:1, vis, adj, col) == false){
                return false;
            }
        }
        else if(col[a] == col[curr])
            return false;
    }

    return true;
}

int main()
{
    OJ;
    int t;
    cin >> t;
    for(int z = 1; z<=t; z++){
        int n, m;
        cin >> n >> m;
        vector<int>* adj = new vector<int>[n+1];
        int a, b;
        for(int i=0; i<m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(n+1, false);
        vector<int> col(n+1);
        bool flag = true;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                flag = dfs(i, 0, vis, adj, col);
                if(flag == false){
                    break;
                }
            }
        }


        cout << "Scenario #" << z << ":" << endl;
        if(flag == false){
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
        }

    }
    return 0;
}