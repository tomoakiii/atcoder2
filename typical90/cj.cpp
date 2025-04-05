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
    ll N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector NG(N, vector<int>{});
    rep(i,N) cin>>A[i];
    rep(i,Q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        NG[x].emplace_back(y);
        NG[y].emplace_back(x);
    }
    int M = 10000;
    bitset<128> init;
    init[127] = 1;
    vector<bitset<128>> dp(M+1, init);
    dp[0] = 0;
    auto disp = [](bitset<128> a, bitset<128> b ) -> void {
        rep(q, 2){   
            vector<int> ans{};
            rep(i, 89) {
                if(a[i]) {
                    ans.push_back(i+1);
                }
            }
            cout << ans.size() << endl;
            for(auto p: ans) cout << p << " ";
            cout << endl;
            swap(a,b);
        }
    };
    rep(i, N) {
        vector dp_n = dp;
        rep(j, M) {            
            if(dp[j][127]) continue;
            bool flg = true;
            for(auto ng: NG[i]) {
                if(dp[j][ng]) flg = false;
            }
            if(!flg) continue;
            bitset<128> hist = dp[j];
            hist[i] = 1;
            if(dp[j+A[i]][127] != 1) {
                disp(dp[j+A[i]], hist);                
                return 0;
                cout << "------" << endl;
            } else {
                dp_n[j+A[i]] = hist;
            }
        }
        swap(dp, dp_n);
    }
    return 0;
}