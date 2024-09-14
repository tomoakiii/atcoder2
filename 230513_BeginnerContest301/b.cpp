#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<int> A(N, 0);
    rep(i, N) {
        cin >> A[i];
    }
    cout << A[0] << " ";
    for(int i=1; i<N; i++) {
        if (A[i] > A[i-1]) {
            for (int j=A[i-1]+1; j<A[i]; j++) {
                cout << j << " ";
            }
        } else {
            for (int j=A[i-1]-1; j>A[i]; j--) {
                cout << j << " ";
            }
        }
        cout << A[i] << " ";
    }
    return 0;
}