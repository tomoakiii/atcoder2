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
    ll N,K;
    cin >> N >> K;
    vector<bool> S(N+1);
    vector<bool> A(N);
    rep(i,N) {
        ll a; cin>>a; A[i] = (a==1);
    }

    bool flg = false;
    ll ans = 0;
    rep(i,N) {
        if(S[i]) flg = !flg;
        if(flg != A[i]) {
            ans++;
            if(i+K <= N) {
                flg = !flg;
                S[i+K] = true;
            } else {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}