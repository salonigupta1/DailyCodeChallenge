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

class Graph {
    int n;
    int m;
    vector<int>* arr;
    public:
        Graph(int n, int m){
            this->n = n;
            this->m = m;
            arr = new vector<int>[n];
        }

        void addEdge(int a, int b){
            arr[a].push_back(b);
        }

        void printGraph(){
            for(int i=0; i<n; i++){
                cout << i << "-> ";
                for(auto it = arr[i].begin(); it!=arr[i].end(); it++){
                    cout << (*it) << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    OJ;
    int n, m;
    cin >> n >> m;
    Graph* g = new Graph(n, m);
    int a, b;
    while(m--){
        cin >> a >> b;
        g->addEdge(a, b);
    }

    g->printGraph();
    return 0;
}