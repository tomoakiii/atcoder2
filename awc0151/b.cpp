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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> cnt(N);
    ll mx = 0, ans=0;
    rep(i,M){
        int p; cin>>p; p--;
        cnt[p]++; chmax(mx,cnt[p]);
        if(p!=1)continue;
        if(mx>cnt[1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}