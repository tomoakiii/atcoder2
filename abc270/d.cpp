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
    ll N, K;
    cin >> N >> K;
    vector<int> A(K+1);
    rep(i,K) cin>>A[i+1];
    A.push_back(INFi);
    bool flg = true;
    ll ans = 0;
    while(N) {
        auto id = lower_bound(A.begin(), A.end(), N);
        if(*id > N) id--;
        if(*id == 0) break;
        N -= *id;
        if(flg) ans += *id;        
        flg = !flg;
    }
    cout << ans << endl;
    return 0;
}