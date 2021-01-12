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

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vector<bool> vis(10001, 0);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        if (vis[top] == false)
        {
            ans.push_back(top);
        }
        vis[top] = true;
        for (auto it = adj[top].begin(); it != adj[top].end(); it++)
        {
            if (vis[*it] == false)
                q.push(*it);
        }
    }

    return ans;
}

int main()
{
    OJ;
    return 0;
}