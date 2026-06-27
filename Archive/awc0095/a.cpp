#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> ans(N);
    rep(i,M){
        ll p,c,k; cin>>p>>c>>k;
        p--;
        ans[p]+=c;
        ll d=c/k;
        rep(j,k){
            int a; cin>>a; a--;
            ans[a]-=d;
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}