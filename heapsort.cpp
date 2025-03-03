#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

double a[N];

int n;

void heapify(double a[], int n, int i) {
    while (true) {
        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2; 
        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;
        if (largest == i) break; 
        swap(a[i], a[largest]); 
        i = largest;
    }
}

void heapSort(double a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]); 
        heapify(a, i, 0);
    }
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
        heapSort(a, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        tmp = (tmp + elapsed.count() * 1000);
        cout<<"Testcase "<<it<<" takes: "<<elapsed.count() * 1000<<" miliseconds"<<endl;
    }
    cout<<"average :" << tmp / 10<< "miliseconds";
    return 0;
}
