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
    vector<int> A(2*N, 0);
    vector<int> M(N, -1);

    rep(i, 2*N) {
        cin >> A[i];
        A[i]--;
    }

    ll cnt = 0;
    rep(i, 2*N) {
        if (M[A[i]] == -1) {
            M[A[i]] = i;
        } else {
            if (i - M[A[i]] == 2) {
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}