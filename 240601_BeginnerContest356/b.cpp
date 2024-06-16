#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M, 0);
    rep(i, M) cin >> A[i];
    vector X(N, vector<ll>(M));
    rep(i, N) rep(j, M) {
        ll x;
        cin >> x;
        A[j] -= x;
    }
    rep(j, M) {
        if(A[j] > 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}