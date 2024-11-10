#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)


int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N, 0);
    while(Q--) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            A[x]++;
        } else if (t ==2) {
            A[x] += 2;
        } else {
            cout << (A[x]>=2?"Yes":"No") << endl;
        }
    }
    return 0;
}