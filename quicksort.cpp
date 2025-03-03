#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

double a[N];

int n;

void quicksort(int l, int r) {
    int i = l, j = r;
    double x = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l <= j) quicksort(l, j);
    if (i <= r) quicksort(i, r);
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
        for (int i = 1; i <= n; i++) cin >> a[i];
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(1, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        tmp = (tmp + elapsed.count() * 1000);
        cout<<"Testcase "<<it<<" takes: "<<elapsed.count() * 1000<<" miliseconds"<<endl;
    }
    cout<<"average :" << tmp / 10<< "miliseconds";
    return 0;
}
