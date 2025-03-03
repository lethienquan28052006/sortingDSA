#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

double a[N];

int n;

double temp[N];    
void merge(double a[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];
    for (int t = left; t <= right; t++)
        a[t] = temp[t];
}
void mergeSort(double a[], int left, int right) {
    if (left >= right) return; 
    int mid = left + (right - left) / 2; 
    mergeSort(a, left, mid);  
    mergeSort(a, mid + 1, right); 
    merge(a, left, mid, right); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("data.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = 1e6;
    long double tmp = 0;
    for (int it = 1; it <= 10; it++) {
        for (int i = 0; i < n; i++) cin >> a[i];
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(a, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        tmp = (tmp + elapsed.count() * 1000);
        cout<<"Testcase "<<it<<" takes: "<<elapsed.count() * 1000<<" miliseconds"<<endl;
    }
    cout<<"average :" << tmp / 10<< " miliseconds";
    return 0;
}
