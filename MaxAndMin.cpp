#include <iostream>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    OJ;
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int maxE, i;
    int minE;
    if(n%2 == 0){
        if(arr[0] > arr[1]){
            maxE = arr[0];
            minE = arr[1];
        } else {
            maxE = arr[1];
            minE = arr[0];
        }
        i=2;
    } else {
        maxE = arr[0];
        minE = arr[0];
        i=1;
    }

    for(; i<n; i+=2){
        if(arr[i] > arr[i+1]){
            if(arr[i] > maxE){
                maxE = arr[i];
            }
            if(arr[i+1] < minE){
                minE = arr[i+1];
            }
        } else {
            if(arr[i+1] > maxE){
                maxE = arr[i+1];
            }
            if(arr[i] < minE){
                minE = arr[i];
            }
        }
    }
    cout << maxE << " " << minE << endl;
    return 0;
}