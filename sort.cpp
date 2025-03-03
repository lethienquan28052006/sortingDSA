#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

double a[N];

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("data.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = 1e6;
    long double tmp = 0;    
    vector<vector<double>> A;
    for (int it = 1; it <= 10; it++) {
        for (int i = 0; i < n; i++) cin >> a[i];
        A.push_back(vector<double>(a, a + n));
        auto start = std::chrono::high_resolution_clock::now();
        sort(a, a + n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        tmp = (tmp + elapsed.count() * 1000);
        cout<<"Testcase "<<it<<" takes: "<<elapsed.count() * 1000<<" miliseconds"<<endl;
    }
    cout<<"average : " << tmp / 10<< " miliseconds";
    return 0;
}
