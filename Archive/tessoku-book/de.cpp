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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N,K; cin>>N>>K;
    vector<ll> A(K);
    rep(i,K) cin>>A[i];
    vector<int> win(N+1,-1);
    win[0] = 0;
    for(int i=1; i<=N; i++) {
        if(win[i] != -1) continue;
        bool flg = false;
        rep(j,K) {
            if(i-A[j]<0) continue;
            if(win[i-A[j]] == 0) {
                win[i] = 1;
                flg = true;
                break;
            }
        }
        if(!flg) win[i] = 0;
    }
    if(win[N] == 1) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
