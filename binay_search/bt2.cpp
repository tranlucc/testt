//Trộn 2 mảng đã được sắp xếp thành một mảng sắp xếp tăng dần


//C1
#include <iostream>
using namespace std;

void tron(int arr1[], int m, int arr2[], int n, int mer[]){
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(arr1[i] <= arr2[j]){
            mer[k++] = arr1[i];
            ++i;
        }
        else{
            mer[k++] = arr2[j];
            ++j;
        }
    }
    while(i < m){
        mer[k++] = arr1[i++];
    }
    while(j < n){
        mer[k++] = arr2[j++];
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int j = 0; j < n; j++){
        cin >> b[j];
    }
    int merged[n + m];
    tron(a, m, b, n, merged);
    for(int i = 0; i < n+ m; i++){
        cout << merged[i] << " ";
    }
    return 0;
}


//C2
// #include <iostream>
// #include <vector>
// using namespace std;

// vector <int> tronMang(vector <int>& a, vector <int>& b){
//     int i = 0, j = 0;
//     vector <int> mer;
//     while(i < a.size() && j < b.size()){
//         if(a[i] <= b[j]){
//             mer.push_back(a[i]);
//             ++i;
//         }
//         else{
//             mer.push_back(b[j]);
//             ++j;
//         }
//     }
//     while(i < a.size()){
//         mer.push_back(a[i]);
//         ++i;
//     }
//     while(j < b.size()){
//         mer.push_back(b[j]);
//         ++j;
//     }
//     return mer;
// }

// int main(){
//     int m, n;
//     cin >> m >> n;
//     vector <int> a(m), b(n);
//     for(int i = 0; i < m; i++){
//         cin >> a[i];
//     }
//     for(int j = 0; j < n; j++){
//         cin >> b[j];
//     }
//     vector <int> merged = tronMang(a, b);
//     for(int i = 0; i < m + n; i++){
//         cout << merged[i] << " ";
//     }
//     return 0;
// }