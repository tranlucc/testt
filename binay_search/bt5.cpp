//Tim vi tri cua phan tu trong mang tang dan ngat quang
#include <iostream>
using namespace std;

int local(int arr[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == x) return m;
        if(arr[l] <= arr[m]){
            if(arr[l] <= x && x < arr[m]){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        else{
            if(arr[m] < x && x <= arr[r]){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
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
    int x; cin >> x;

    cout << local(arr, n, x);
    return 0;
}