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
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<bool> G(N);
    vector<int> A(K);
    rep(i, K) {
        int a;
        cin >> A[i];
        A[i]--;
        G[A[i]] = true;
    }
    while(Q--){
        int l;
        cin >> l;
        l--;
        if(A[l] == N-1) continue;
        if(G[A[l]+1]) continue;
        swap(G[A[l]], G[A[l]+1]);
        A[l]++;
    }
    rep(i,K) {
        cout << 1+A[i] << " ";
    }
    cout << "\n";
    return 0;
}