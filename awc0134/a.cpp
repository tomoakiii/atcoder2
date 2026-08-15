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
    ll N;
    cin >> N;
    vector<vector<ll>> v(N);
    rep(i,N){
        int c, l; cin>>c>>l; c--;
        v[c].push_back(l);
    }
    ll ans=0;
    for(auto vv : v) {
        rep(i,vv.size()){
            for(int j=i+1; j<vv.size(); j++){
                ans += abs(vv[j]-vv[i]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}