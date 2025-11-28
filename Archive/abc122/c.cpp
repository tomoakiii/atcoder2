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
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<ll> cnt(N);
    rep(i,N-1) {
        if(S[i] == 'A' && S[i+1] == 'C') {
            cnt[i+1] = 1;
        }
    }
    rep(i,N) cnt[i+1] += cnt[i];
    while(Q--) {
        int l, r; cin>>l>>r;
        l--; r--;
        if(S[l] == 'C') l++;
        if(l == 0) cout<<cnt[r]<<endl;
        else cout<<cnt[r] - cnt[l-1]<<endl;
    }
    return 0;
}