#include<bits/stdc++.h>
using namespace std;

template<class A, class B>
    void maximize(A& x, B y) {
        if (x < y) x = y;
    }
template<class A, class B>
    void minimize(A& x, B y) {
        if (x > y) x = y;
    }
/* END OF TEMPLATE */

using namespace std;

const int iFirst = 1;
const int iLast = 10;

mt19937 rng(28052006);

long long rd(long long l, long long r) {
    long long tmp = 0;
    for (int i = 0; i < 60; i++) {
        int v = rng() % 2;
        if (v == 1) tmp^=(1LL << i);
    }
    return l + tmp % (r - l + 1);
}

long double rd2(long double a, long double b) {
    long long l = a, r = b;
    long long tmp = 0;
    for (int i = 0; i < 60; i++) {
        int v = rng() % 2;
        if (v == 1) tmp^=(1LL << i);
    }
    long long x = l + tmp % (r - l + 1);
    int d = rd(1, 7);
    long long tich = 1;
    for (int i = 1; i <= d; i++) tich = tich * 10;
    return (long double)x / tich;
}

void MakeTest(ofstream& cout, int iTest)  {
    for (int it = 1; it <= iTest; it++) {
        vector<long double> A;
        int n = 1e6;
        for (int i = 1; i <= n; i++) A.push_back(rd2(-1e7, 1e7));
        if (it == 1) sort(A.begin(), A.end()); else 
        if (it == 2) sort(A.begin(), A.end(), greater<long double>());
        for (auto x : A) cout<<fixed<<setprecision(5)<<x<<" "; cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int iTest = iFirst; iTest <= iLast; iTest++)
    {
        string inputFile = "data.inp";
        ofstream inp (inputFile.c_str());
        MakeTest(inp, iTest);
        inp.close();
        cout<<"OK "<<iTest<<endl;
    }
}
