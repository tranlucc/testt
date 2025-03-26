//Tim vị trí đầu tiên của 1 phần tử trong mảng đã sắp xếp
//           cuoi cung


#include <iostream>
using namespace std;

int first_check(int arr[], int n, int x){
    int l = 0, r = n - 1;
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == x){
            res = m;
            r = m - 1;
        }
        else if(arr[m] < x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return res;
}

int last_check(int arr[], int n, int x){
    int l = 0, r = n - 1;
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == x){
        res = m;
        l = m + 1;
        }
        else if(arr[m] < x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x; cin >> x;
    cout << "Vi tri dau: " << first_check(arr, n, x) << ", vi tri cuoi cung: " << last_check(arr, n, x) << endl;
    int a = first_check(arr, n, x);
    int b = last_check(arr, n, x);
    cout << "Khoang cach la: " << b - a;
    return 0;
}