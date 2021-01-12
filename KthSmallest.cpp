#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


int partition(int arr[], int l, int h){
    int pivot = arr[h], i = l;
    for(int j=l; j<h; j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[i], arr[h]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k){
    if(k>0 && (k<= (r-l+1))){
        
        int pos = partition(arr, l , r);
        
        if((pos-l) == (k-1)){
            return arr[pos];
        }
        if(pos-l > k-1){
            return kthSmallest(arr, l, pos-1, k);
        }
        
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    
    return INT_MAX;
}

int main() {
	//code
	int t;
	cin  >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int* arr = new int[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int k;
	    cin >> k;
	    cout << kthSmallest(arr, 0, n-1, k) << endl;
	}
	return 0;
}