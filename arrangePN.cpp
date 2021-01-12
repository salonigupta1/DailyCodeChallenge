#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<cstring>

using namespace std;
#define ll long long int
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const int MX = 10000007;
ll n, t;

void rearrange(int arr[], int n){
    int i=-1, j = n-1;
    while(i<j){
        while(i<=n-1 && arr[i]>=0){
            i++;
        }
        while(j>=0 && arr[j]<0){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }

    if(i==0 || i == n){
        return;
    }

    int k = 0;
    while(k<n && i<n){
        swap(arr[k], arr[i]);
        i++;
        k+=2;
    }
}

int main(){
    OJ;
    FIO;
    cin >> t;
    while(t--){
        cin >> n;
        int* arr = new int[n];
        int cP = 0;
        int cN = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
    
        rearrange(arr, n);
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
