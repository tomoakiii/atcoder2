#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, A;
    cin >> N >> A;
    vector<ll> T(N+1, 0);
    rep(i, N) cin >> T[i+1];

    ll now = -1;
    ll end = -1;
    vector<ll> W(N+1, 0);    

    for(int i=1; i<=N; i++) {
        if (W[i-1] > T[i]) {
            W[i] = W[i-1] + A;
        }
        else {
            W[i] = T[i] + A;
        }
        cout << W[i] << endl;
    }

    return 0;
}