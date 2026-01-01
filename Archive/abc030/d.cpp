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
    ll N,x;
    cin >> N >> x;
    x--;
    string K; cin>>K;

    vector<ll> A(N);
    scc_graph G(N);
    vector vu(N, vector<int>{});
    rep(i,N) {
        cin>>A[i];
        A[i]--;
        G.add_edge(i, A[i]);
        vu[A[i]].push_back(i);
    }

    if(K.size() < 5) {
        ll kk = stoll(K);
        while(kk--) x = A[x];
        cout << x+1 << endl;
        return 0;
    }

    vector<int> L(N,-1);
    auto vv = G.scc();
    rep(i, vv.size()) {
        if(vv[i].size() < 2) continue;
        rep(j, vv[i].size()) {
            L[vv[i][j]] = i;
        }
    }
    int p = 0;
    while(L[x] == -1) {
        x = A[x];
        p++;
    }
    int i = L[x];
    int md = 0;
    ll tmp = 0;
    for(auto k: K) {
        int ki = k - '0';
        tmp = tmp * 10 + ki;
        tmp = tmp % (int)(vv[i].size());
    }
    while(tmp < p) {
        tmp += (int)(vv[i].size());
    }
    tmp -= p;
    while(tmp--) {
        x = A[x];
    }
    cout << x+1 << endl;
    return 0;
}