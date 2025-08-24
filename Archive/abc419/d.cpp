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
    ll N, M;
    cin >> N >> M;
    string S,T; cin>>S>>T;
    vector<int> sm(N+1);
    while(M--){
        int l, r; cin >> l >> r;
        l--, r--;
        sm[l]++;
        sm[r+1]++;
    }
    rep(i,N) sm[i+1] += sm[i];
    string ans;
    rep(i,N) {
        if(sm[i] % 2 == 0) {
            ans.push_back(S[i]);
        } else {
            ans.push_back(T[i]);
        }
    }
    cout << ans << endl;
    return 0;
}