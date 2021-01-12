#include <iostream>
using namespace std;

void sortArr(int arr[], int n){
    int lo = 0;
    int mid = 0;
    int high = n-1;
    while(lo < n && high<n && mid<n){
        if(arr[mid] < 0){
            swap(arr[mid++], arr[lo++]);
        } else {
            mid++;
        } 
    }
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0; i<n; i++){
	    cin >> arr[i];
	}
	
	sortArr(arr, n);
	
	for(int i=0; i<n; i++){
	    cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}