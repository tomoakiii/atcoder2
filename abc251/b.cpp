#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, w;
    cin >> N >> w;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> W{};
    rep(i, N) {
        if(A[i] > w) continue;
        W.emplace_back(A[i]);
        for(int j=i+1; j<N; j++){
            if(A[i]+A[j] > w) continue;
            W.emplace_back(A[i]+A[j]);
            for(int k=j+1; k<N; k++) {
                if(A[i]+A[j]+A[k] > w) continue;
                W.emplace_back(A[i] + A[j] + A[k]);
            }
        }
    }
    sort(W.begin(), W.end());
    W.erase(unique(W.begin(), W.end()), W.end());
    cout << W.size() << endl;
    return 0;
}