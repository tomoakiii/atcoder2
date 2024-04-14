#include <bits/stdc++.h>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a: A) cin>>a;
    int mx = 0;
    for (int l=0; l<N; l++){
        int mn = 200000;
        for (int r=l; r<N; r++){
            mn = min(mn, A[r]);
            mx = max(mx, (r-l+1)*mn);
        }
    }
    cout << mx << endl;
    
    return 0;
}
