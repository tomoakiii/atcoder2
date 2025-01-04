#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
int main(){
    int N, K;
    cin >> N >> K;
    map<int, map<int, int>> AB;
    vector<int> A(N), B(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        AB[a][b] = i;
        A[i] = a;
        B[i] = b;
    }
    rep(i, N)
    {
        for(int h = A[i]; h <= A[i] + K; h++) {
            if(!AB.contains(h)) continue;
            auto p = AB[h].upper_bound(B[i] + K);
            if(p->first > h+K) p--;

        }
    }

    return 0;
}