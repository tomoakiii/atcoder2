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
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    map<string, ll> mp;    
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return S[i] < S[j]; });    

    vector<ll> ans(N, 0);
    rep(is,N-1) {
        int i = ord[is], i2 = ord[is+1];
        rep(j, min(S[i].size(), S[i2].size())) {
            if (S[i][j] == S[i2][j]) {
                chmax(ans[i], j+1);
                chmax(ans[i2], j+1);
            } else {
                break;
            }
        }
    }
    rep(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}