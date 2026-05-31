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
    ll N, K, M;
    cin >> N >> K >> M;
    vector<ll> Ve, Am;
    rep(i,N) {
        int h; ll p; cin>>h>>p;
        if(h==1) Ve.push_back(p);
        else Am.push_back(p);
    }
    sort(Ve.rbegin(), Ve.rend());
    sort(Am.rbegin(), Am.rend());
    if(Ve.size()<M || Am.size()<K-M) {
        cout<<-1<<endl;
        return 0;
    }
    ll ans = 0;
    rep(i,M) ans+=Ve[i];
    rep(i,K-M) ans+=Am[i];
    cout<<ans<<endl;
    return 0;
}