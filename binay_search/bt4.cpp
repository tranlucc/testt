//Tim dinh cua mot mang tang dan cach
#include <iostream>
using namespace std;

int findPeak(int arr[], int n){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(m == 0 || m == n - 1 || arr[m] > arr[m - 1] && arr[m] > arr[m + 1]){
            return m;
        }
        if(arr[m] > arr[m + 1]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << findPeak(arr, n) << " ";
    return 0;
}