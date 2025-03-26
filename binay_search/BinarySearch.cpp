//Tìm số trung vị của 2 mảng đã sắp xếp

#include <iostream>
#include <vector>
using namespace std;


//Bai 1
void tronMang(int x[], int m, int y[], int n, int mer[]){
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(x[i] <= y[j]){
            mer[k++] = x[i];
            ++i;
        }
        else{
            mer[k++] = y[j];
            ++j;
        }
    }
    while(i < m){
        mer[k++] = x[i];
        ++i;
    }
    while(j < n){
        mer[k++] = y[j];
        ++j;
    }
}
double median(int merge[], int n){
    if(n % 2 == 1){
        return merge[n / 2];
    }
    else{
        return (merge[n/2 - 1] + merge[n / 2]) / 2.0;
    }
}



//Bai 2
int first(int arr[], int n, int x){
    int l = 0, r = n - 1;
    int res = - 1;
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
int last(int arr[], int n, int x){
    int l = 0, r = n - 1;
    int res = - 1;
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


//Bai 3
int local(vector <int>& arr, int x){
    int l = 0, r = arr.size() - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(arr[m] == x) return m;
        if(arr[l] <= arr[m]){  // Nua trai xep tang dan
            if(arr[l] <= x && x < arr[m]){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        else{                 // Nua phai sap xep tang dan
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


//Bai 4
int findPeak(int arr[], int n){
    int l = 0, r = n - 1;
    while(l <= n){
        int m = (l + r) / 2;
        if(m == 0 || m == n - 1 || arr[m] > arr[m + 1] && arr[m] > arr[m - 1]){
            return m;
        }
        if(arr[m] > arr[m + 1]){
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return - 1; // khi khong tim thay
}

int main(){
//Bai 1
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int j = 0; j < n; j++){
        cin >> b[j];
    }
    int merged[m + n];
    tronMang(a, m, b, n, merged);
    cout << median(merged, m + n) << endl;


//Bai 2
    int v;
    cin >> v;
    int arr[v];
    for(int i = 0; i < v; i++){
        cin >> arr[i];
    }
    int x; cin >> x;
    cout << "[" << first(arr, v, x) << "," << last(arr, v, x) << "]" << endl;


//Bai 3
   int p; cin >> p;
   vector <int> array(p);
   for(int i = 0; i < p; i++){
    cin >> array[i];
   }
   int u; cin >> u;
   cout << local(array, u) << endl;


//Bai 4
   int t; cin >> t;
   int mang[t];
   for(int i = 0; i < t; i++){
    cin >> mang[i];
   }
   cout << findPeak(mang, t);
    return 0;
}